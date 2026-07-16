#include <stdio.h>
#define MAX 5

int fifo[MAX];
int front = 0;
int rear = 0;
int count = 0;


void dodaj_u_fifo(int element)
{
    if (count == MAX)
    {
        printf("Bafer je pun!\n");
        return;
    }

    fifo[rear] = element;
    rear = (rear + 1) % MAX;   
    count++;

    printf("Dodat je element: %d\n", element);
}

int main()
{

    dodaj_u_fifo(10);
    dodaj_u_fifo(20);
    dodaj_u_fifo(30);

    return 0;
}