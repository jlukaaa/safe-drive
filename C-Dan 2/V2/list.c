#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct person
{
    int id;
    char name[25];
    int age;
};

typedef struct person person;

struct node
{
    struct person data;
    struct node *next;
};

typedef struct node node;

node* head = NULL;
/*
    head ostaje NULL sve dok se ne doda prvi element u listu!
    node* new_node = (struct node *)malloc(sizeof(struct node));
    funkcija za dodavanje treba da bude univerzalna u odnosu na trenutni broj elemenata liste,
    tj. da prvo nadje zadnji element pa na njega da dodaje
*/

node* create_node(int id, char name[], int age)
{
    node *new_node = (node*)malloc(sizeof(node));

    new_node->data.id = id;
    strcpy(new_node->data.name, name);
    new_node->data.age = age;
    new_node->next = NULL;

    return new_node;
}

void add_front(int id, char name[], int age)
{
    node *new_node = create_node(id, name, age);

    new_node->next = head;
    head = new_node;

}

void add_back(int id, char name[], int age)
{
    node *new_node = create_node(id, name, age);

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    node *temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;

}

node *find_element(int id)
{
    node *temp = head;

    while (temp != NULL)
    {
        if(temp->data.id == id)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

void add_after(node *position, int id, char name[], int age)
{
    if(position == NULL)
        return;

    node *new_node = create_node(id, name, age);

    new_node->next = position->next;
    position->next = new_node;

}

void for_each()
{
    node *temp = head;

    while(temp != NULL)
    {
        printf("ID: %d\n", temp->data.id);
        printf("Ime: %s\n", temp->data.name);
        printf("Godine: %d\n\n", temp->data.age);

        temp = temp->next;
    }
}
int main()
{
    /*
        Zadaci:
            zadatak (a): Napisati funkcije za dodavanje elemenata na pocetak, kraj i iza
                         zadanog (pomocu pokazivaca) elementa liste
            zadatak (b): Napisati funkcije find_element i for_each za istu listu

            Sve istestirati u okviru ove main funkcije  
    */
    add_front(1, "Marko", 20);
    add_front(2, "Ana", 22);
    add_back(3, "Ivan", 25);

    printf("Lista nakon dodavanja:\n");
    for_each();

    node *p = find_element(1);

    if(p != NULL)
    {
        add_after(p, 4, "Petar", 30);
    }

    printf("\nNakon add_after:\n");
    for_each();

    return 0;
}