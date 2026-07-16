#include <stdio.h>

struct Podaci {

    char a;
    int b;
    char c;

};

#pragma pack(1)

struct SpakovaniPodaci
{
    char a;
    int b;
    char c;
};

#pragma pack(0)

int main()
{
    printf ("Velicina strukture Podaci : %zu bajta\n", sizeof(struct Podaci));
    printf ("Velicina strukture SpakovaniPodaci: %zu bajta\n", sizeof(struct SpakovaniPodaci));

    return 0;
}
