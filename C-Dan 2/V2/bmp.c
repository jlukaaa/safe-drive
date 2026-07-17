#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*— ensure no struct padding —*/
#pragma pack(push, 1)
typedef struct
{
    uint16_t bfType;      // must be 'BM' = 0x4D42
    uint32_t bfSize;      // file size in bytes
    uint16_t bfReserved1; // =0
    uint16_t bfReserved2; // =0
    uint32_t bfOffBits;   // offset to pixel data
} BITMAPFILEHEADER;

typedef struct
{
    uint32_t biSize;         // size of this header (40)
    int32_t biWidth;         // image width
    int32_t biHeight;        // image height (positive = bottom-up)
    uint16_t biPlanes;       // must be 1
    uint16_t biBitCount;     // bits per pixel (we expect 24)
    uint32_t biCompression;  // 0 = BI_RGB (no compression)
    uint32_t biSizeImage;    // image data size (including padding)
    int32_t biXPelsPerMeter; // resolution
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed; // palette entries (0 for true color)
    uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

/**
 * load_bmp:
 *   filename: path to .bmp
 *   outWidth, outHeight: filled with dims
 *   returns: pointer to malloc'ed buffer [width*height*3] in RGB order,
 *            or NULL on error. Free with free().
 */
unsigned char *load_bmp(const char *filename, int *outWidth, int *outHeight)
{
    FILE *f = fopen(filename, "rb");
    if (!f)
    {
        perror("fopen");
        return NULL;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    if (fread(&bfh, sizeof bfh, 1, f) != 1 ||
        fread(&bih, sizeof bih, 1, f) != 1)
    {
        fprintf(stderr, "Failed to read BMP headers\n");
        fclose(f);
        return NULL;
    }

    if (bfh.bfType != 0x4D42 || bih.biBitCount != 24 || bih.biCompression != 0)
    {
        fprintf(stderr, "Unsupported BMP format (only uncompressed 24bpp)\n");
        fclose(f);
        return NULL;
    }

    int w = bih.biWidth;
    int h = abs(bih.biHeight);
    int row_bytes = ((w * 3 + 3) / 4) * 4; // padded to 4 bytes
    unsigned char *data = malloc(w * h * 3);
    if (!data)
    {
        perror("malloc");
        fclose(f);
        return NULL;
    }

    fseek(f, bfh.bfOffBits, SEEK_SET);
    for (int y = 0; y < h; y++)
    {
        // BMP stores bottom row first if biHeight>0
        int row = (bih.biHeight > 0) ? (h - 1 - y) : y;
        unsigned char *ptr = data + (row * w * 3);
        unsigned char *scan = malloc(row_bytes);
        if (!scan)
        {
            perror("malloc");
            free(data);
            fclose(f);
            return NULL;
        }
        if (fread(scan, 1, row_bytes, f) != (size_t)row_bytes)
        {
            fprintf(stderr, "Failed to read BMP scanline\n");
            free(scan);
            free(data);
            fclose(f);
            return NULL;
        }
        // BGR -> RGB
        for (int x = 0; x < w; x++)
        {
            ptr[3 * x + 0] = scan[3 * x + 2];
            ptr[3 * x + 1] = scan[3 * x + 1];
            ptr[3 * x + 2] = scan[3 * x + 0];
        }
        free(scan);
    }

    fclose(f);
    *outWidth = w;
    *outHeight = h;
    return data;
}

/**
 * write_bmp:
 *   filename: output path
 *   data:     RGB buffer [w*h*3]
 *   w, h:     dims
 * returns 0 on success, -1 on error
 */
int write_bmp(const char *filename,
              const unsigned char *data,
              int w, int h)
{
    int row_bytes = ((w * 3 + 3) / 4) * 4;
    uint32_t imageSize = row_bytes * h;
    BITMAPFILEHEADER bfh = {
        .bfType = 0x4D42,
        .bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + imageSize,
        .bfReserved1 = 0,
        .bfReserved2 = 0,
        .bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)};
    BITMAPINFOHEADER bih = {
        .biSize = sizeof(BITMAPINFOHEADER),
        .biWidth = w,
        .biHeight = h, // positive = bottom-up
        .biPlanes = 1,
        .biBitCount = 24,
        .biCompression = 0,
        .biSizeImage = imageSize,
        .biXPelsPerMeter = 2835, // 72 DPI
        .biYPelsPerMeter = 2835,
        .biClrUsed = 0,
        .biClrImportant = 0};

    FILE *f = fopen(filename, "wb");
    if (!f)
    {
        perror("fopen");
        return -1;
    }

    if (fwrite(&bfh, sizeof bfh, 1, f) != 1 ||
        fwrite(&bih, sizeof bih, 1, f) != 1)
    {
        fprintf(stderr, "Failed to write BMP headers\n");
        fclose(f);
        return -1;
    }

    unsigned char *scan = malloc(row_bytes);
    if (!scan)
    {
        perror("malloc");
        fclose(f);
        return -1;
    }

    for (int y = 0; y < h; y++)
    {
        int row = h - 1 - y; // write bottom row first
        const unsigned char *ptr = data + (row * w * 3);
        // RGB -> BGR + padding
        for (int x = 0; x < w; x++)
        {
            scan[3 * x + 0] = ptr[3 * x + 2];
            scan[3 * x + 1] = ptr[3 * x + 1];
            scan[3 * x + 2] = ptr[3 * x + 0];
        }
        // zero pad remaining bytes
        for (int p = 3 * w; p < row_bytes; p++)
            scan[p] = 0;
        fwrite(scan, 1, row_bytes, f);
    }

    free(scan);
    fclose(f);
    return 0;
}
void grayscale_average(unsigned char *img, int w, int h)
    {
    for (int i = 0; i < w * h; i++)
        {
            unsigned char r = img[3 * i];
            unsigned char g = img[3 * i + 1];
            unsigned char b = img[3 * i + 2];

            unsigned char gray =(r + g + b) / 3;

            img[3 * i] = gray;
            img[3 * i + 1] = gray;
            img[3 * i + 2] = gray;
        }
    }

   void grayscale_luminance(unsigned char *img, int w, int h)
    {
    for (int i = 0; i < w * h ; i++)
        {
            unsigned char r = img[3 * i];
            unsigned char g = img[3 * i + 1];
            unsigned char b = img[3 * i + 2];

            unsigned char gray = (unsigned char)(0.299 * r + 0.587 * g +
                                                    0.114 * b);

            img[3 * i] = gray;
            img[3 * i + 1] = gray;
            img[3 * i + 2] = gray;
        }
    }
   unsigned char max3(unsigned char a, unsigned char b, unsigned char c)
    {
        unsigned char m = a;
        if (b > m) m = b;
        if (c > m) m = c;
        return m;
    }
     unsigned char min3(unsigned char a, unsigned char b, unsigned char c)
    {
        unsigned char m = a;
        if (b < m) m = b;
        if (c < m) m = c;
        return m;
    }
   void grayscale_desaturation(unsigned char *img, int w, int h)
    {
    for (int i = 0; i < w * h; i++)
        {
            unsigned char r = img[3 * i];
            unsigned char g = img[3 * i + 1];
            unsigned char b = img[3 * i + 2];

            unsigned char gray = (max3(r, g, b) + min3(r, g, b)) / 2;

            img[3 * i] = gray;
            img[3 * i + 1] = gray;
            img[3 * i + 2] = gray;
        }
    }

    void mean_filter(unsigned char *img, int w, int h)
    {
     unsigned char *temp = malloc(w*h*3);
     if (!temp)
        return;
        
    memcpy(temp, img, w*h*3);

        for (int y = 1; y < h - 1; y++)
        {
            for (int x = 1; x < w - 1; x++)
            {
                int sum_r = 0;
                int sum_g = 0;
                int sum_b = 0;

                for (int ky = -1; ky <=1; ky++)
                {
                    for (int kx = -1; kx <= 1; kx++)
                    {
                       int n_id = ((y + ky) * w + (x + kx)) * 3;
                       sum_r += temp[n_id + 0];
                       sum_g += temp[n_id + 1];
                       sum_b += temp[n_id + 2];
                    }
                }

                int c_id = (y * w + x) * 3;
                img[c_id + 0] = (unsigned char)(sum_r / 9); 
                img[c_id + 1] = (unsigned char)(sum_g / 9); 
                img[c_id + 2] = (unsigned char)(sum_b / 9); 
            }
        }
        free(temp);
    }

int main(int argc, char *argv[])
{

    int w, h;
    unsigned char *img = load_bmp("Image.bmp", &w, &h);
    if (!img)
        return 1;

     // grayscale_average(img, w, h);
        mean_filter(img,w,h);
    if (write_bmp("bmp_24_copy_mean.bmp", img, w, h) != 0)
    {
        free(img);
        return 1;
    }
    free(img);

  
    return 0;
}