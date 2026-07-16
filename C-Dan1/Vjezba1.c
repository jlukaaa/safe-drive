#include <stdio.h>


void brojac_poziva()
{
    static int brojac = 0;
    brojac++;
    printf("Funkcija je pozvana %d. put\n", brojac);
}

int main()
{
    brojac_poziva();
    brojac_poziva();
    brojac_poziva();
}