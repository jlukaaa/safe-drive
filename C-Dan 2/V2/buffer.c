#include <stdio.h>

#define SIZE 5
#include <stdbool.h>

typedef struct 
{
    int data[SIZE];
    int front;
    int rear;
    int count;
}CBuffer;

void init(CBuffer *cb)
{
    cb->front = 0;
    cb->rear = 0;
    cb->count = 0;
}

bool isEmpty(CBuffer *cb)
{
    return cb->count == 0;
}

bool isFull(CBuffer *cb)
{
    return cb->count == SIZE;
}

void encue(CBuffer *cb, int podatak)
{
    if (isFull(cb))
        {
            printf("Bafer je pun!\n");
            return;
        }
    
        cb->data[cb->rear] = podatak;
        cb->rear = (cb->rear + 1) % SIZE;
        cb->count++;
    
}

int decue(CBuffer *cb)
{
    if (isEmpty(cb))
    {
        printf("Bafer je prazan!\n");
        return -1;
    }

    int value = cb->data[cb->front];
    cb->front = (cb->front + 1) % SIZE;
    cb->count--;

    return value;
}

void printBuffer(CBuffer *cb)
{
    int i, index = cb->front;

    printf("Bafer: ");

    for (i = 0; i < cb->count; i++)
    {
        printf("%d ", cb->data[index]);
        index = (index + 1) % SIZE;
    }

    printf("\n");
}

int main()
{
    CBuffer cb;

    init(&cb);
    for (int i = 0; i < 10*SIZE; i += 10)
    {
        encue(&cb, i);
    }
    printBuffer(&cb);

    printf("Izbacen: %d\n", decue(&cb));
    printf("Izbacen: %d\n", decue(&cb));
    encue(&cb, 60);
    encue(&cb, 70);

    printBuffer(&cb);


    return 0;

}