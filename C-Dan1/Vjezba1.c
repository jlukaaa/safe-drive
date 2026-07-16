//Napisi funkciju void brojac_poziva(). Funkcija treba da ispisuje koliko
//je puta do sada bila izvrsena. U main funckiji pozvati ovu funkciju 3 puta unutar petlje.


#include <stdio.h>


void brojac_poziva()
{
    static int brojac = 0;
    brojac++;
    printf("Funkcija je pozvana %d. put\n", brojac);
}

int main()
{
    int temp = 3;
    for (int i = 0; i < temp; i++){
    brojac_poziva();
    }
}