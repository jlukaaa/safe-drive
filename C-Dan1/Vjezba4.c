#include <stdio.h>
struct PametniProzor
{
    unsigned int otvoren : 1;
    unsigned int roletna : 1;
    unsigned int svjetlost : 3;
    unsigned int vlaznost : 7;
};

int main ()
{
    struct PametniProzor prozor;
    
    prozor.otvoren = 1;
    prozor.roletna = 0;
    prozor.svjetlost = 5;
    prozor.vlaznost = 64;

    printf("Prozor %s otvoren \n", prozor.otvoren ? "je" : "nije");
    printf("Roletna %s otvorena\n", prozor.roletna ? "je" : "nije");
    printf("Jacina svjetlosti napolju je %d\n", prozor.svjetlost);
    printf("Vlaznost vazduha napolju je %d\n", prozor.vlaznost);
    return 0;
}