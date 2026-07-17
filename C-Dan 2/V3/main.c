#include <stdio.h>
#include <stdint.h>
#include "ceasar/ceasar.h" 

int main(void)
{
    const char *originalni_tekst = "RT-RK!";
    char enkriptovani_tekst[100];
    char dekriptovani_tekst[100];
    int_fast16_t kljuc = 4; 

    printf("Originalni tekst:  %s\n", originalni_tekst);

    encryptCeasar(originalni_tekst, enkriptovani_tekst, kljuc);
    printf("Enkriptovani tekst: %s\n", enkriptovani_tekst);

    decryptCeasar(enkriptovani_tekst, dekriptovani_tekst, kljuc);
    printf("Dekriptovani tekst: %s\n", dekriptovani_tekst);

    return 0;
}