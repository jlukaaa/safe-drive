#include <stdint.h>
#include "helper.h"

double rac_prosjek (const int *niz, int vel)
{
    if (vel <= 0) return 0.0;
    long suma = 0;
    for (int i = 0; i < vel; i++)
        {
            suma += niz[i];
        }
    return (double)suma / vel;
}

int nadji_min(const int *niz, int vel)
{
    int min = niz[0];
    for (int i = 1; i < vel; i++)
        {
            if (niz[i] < min) min = niz[i];
        }
    return min;
}

int nadji_max(const int *niz, int vel)
{
    int max = niz[0];
    for (int i = 1; i < vel; i++)
        {
            if (niz[i] > max) max = niz[i];
        }
    return max;
}

uint32_t postavi_bit (uint32_t podatak, int pozicija)
{
    return podatak | (1U << pozicija);
}