#include <stdio.h>

extern int g_b;

void ispisi_vrijednost(void)
{
    printf("Vrijednost globalne promjenjive je: %d\n", g_b);
}