#include <stdio.h>

void obrni(int niz[], int start, int end){
    while (start < end)
    {
        int temp = niz[start];
        niz[start] = niz[end];
        niz[end] = temp;
        start++;
        end--;
    }
}

void rotirajUlijevo(int niz[], int n, int d)
{

    obrni(niz, 0, d - 1);
    obrni(niz, d, n - 1);
    obrni(niz, 0, n - 1);

}

int main ()
{
    int niz[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(niz) / sizeof (niz[0]);
    int d = 3;
    rotirajUlijevo(niz,n,d);
     printf("Niz pomjeren za %d mjesta ulijevo: ", d);
    for (int i = 0; i < n; i++)
        {
            printf(" %d ", niz[i]);
        }
        printf("\n");
    return 0;
}