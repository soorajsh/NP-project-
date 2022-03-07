#include <stdio.h>
#include <stdlib.h>


void error_handle(char *message);
char* substr(char* str, int position, int length);


struct Student {
    unsigned int id;
    char name[100];
    long registration_no;
    long msj_sent_count;
};

struct node {
    struct Student data;
    struct node* next;
    struct node* last;
};

struct node* init();
struct node* insert(struct node *ll, struct Student data);
void traverse(struct node *ll);
struct node* search(struct node* head, long rollNo);

typedef struct Student Student;
typedef struct node node;

node *init()
{
    node *head = NULL;
    Student c1 = {id : 1, name : "PewDiePie", registration_no : 99201};
    Student c2 = {id : 2, name : "Kids Diana Show", registration_no : 99202};
    Student c3 = {id : 3, name : "Like Nastya", registration_no : 99203};
    Student c4 = {id : 4, name : "Vlad and Niki", registration_no : 99204};
    Student c5 = {id : 5, name : "Mr Beast", registration_no : 99205};
    Student c6 = {id : 6, name : "Dude Perfect", registration_no : 99206};
    Student c7 = {id : 7, name : "Hola Soy German", registration_no : 99207};
    Student c8 = {id : 8, name : "Whinderssonnunes", registration_no : 99208};
    Student c9 = {id : 9, name : "Felipe Neto", registration_no : 99209};
    Student c10 = {id : 10, name : "Fernanfloo", registration_no : 99210};
    Student c11 = {id : 11, name : "Voce Sabia", registration_no : 99211};
    Student c12 = {id : 12, name : "El Rubius OMG", registration_no : 99212};
    Student c[15] = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12};
    for (size_t i = 0; i < 12; i++)
        head = insert(head, c[i]);
    return head;
}

node *insert(node *ll, Student data)
{
    node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    link->next = NULL;
    if (ll == NULL)
    {
        ll = link;
        ll->last = link;
        return ll;
    }
    ll->last->next = link;
    ll->last = link;
    return ll;
}

void traverse(node *ll)
{
    node *temp;
    temp = ll;
    while (temp != NULL)
    {
        printf("id: %d\tname: %s\n", temp->data.id, temp->data.name);
        temp = temp->next;
    }
}

node *search(node *ll, long rollNo)
{
    node *temp;
    temp = ll;
    while (temp != NULL)
    {
        if (temp->data.registration_no == rollNo)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

