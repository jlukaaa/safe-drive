#include <stdio.h>
#include <stdint.h>
#include "helper.h"

int main(void) {
    int brojevi[] = {5, 12, 3, 19, 8};
    int n = sizeof(brojevi) / sizeof(brojevi[0]);

    printf("Srednja vrijednost niza: %.2f\n", rac_prosjek(brojevi, n));
    printf("Minimalni element: %d\n", nadji_min(brojevi, n));
    printf("Maksimalni element: %d\n", nadji_max(brojevi, n));

    uint32_t broj = 0; 
    int bit_za_postavljanje = 3; 
    uint32_t novi_broj = postavi_bit(broj, bit_za_postavljanje);
    printf("Broj nakon postavljanja %d. bita je: %u (binarno: 1000)\n", bit_za_postavljanje, novi_broj);

    return 0;
}