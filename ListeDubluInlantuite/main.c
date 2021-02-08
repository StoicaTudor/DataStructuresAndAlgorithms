#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node * next;
    struct node* previous;
} node;

node * first,*last;

void initList(node ** element)
{
    (* element)=NULL;
}

void addToEnd(node ** first, node ** last, int data)
{
    if((*first)==NULL)
    {
        (* first)=(node *) malloc(sizeof(node));
        (*first)->info=data;
        (*first)->next=(*last);
        (*last)=(*first);
        (*last)->previous=(*first);
    }

    else
    {
        node * element=(node *) malloc(sizeof(node));
        element->info=data;
        element->next=NULL;
        element->previous=(*last)->previous;
        (*last)->next=element;
        (*last)=element;
    }
}

//void addToFront(node ** first, node ** last, int data)
//{
//    if((* first)==NULL)
//    {
//        (* first)=(node *) malloc(sizeof(node));
//        (* first)->info=data;
//        (* first)->next=last;
//        (* first)=(* last);
//        (*last)->previous=(*first);
//    }
//
//    else
//    {
//        node * element=(node *) malloc((sizeof(node)));
//        element->info=data;
//        element->next=first->next;
//
//    }
//}

int main()
{
    initList(&first);
    initList(&last);
    addToEnd(&first,&last,0);
    addToEnd(&first,&last,1);
    addToEnd(&first,&last,2);
    addToEnd(&first,&last,3);
    addToEnd(&first,&last,4);
    addToEnd(&first,&last,5);

    node * previous=NULL;
    node * element=first;

    while(element!=NULL)
    {
        node * aux=NULL;

        if(element->next!=NULL)
        {
            aux=element->next;
            element->next=previous;
            previous=element;
            element=aux;
        }

        else
        {
            element->next=previous;
        }
    }

    element=first;
    first=last;
    last=element;

    element=first;

    while(element!=NULL)
    {
        printf("%d ",element->info);
        element=element->next;
    }

    return 0;
}
