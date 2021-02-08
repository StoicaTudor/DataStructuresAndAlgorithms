#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node * next;
    struct node * previous;
} node;

int main()
{
    node * first=NULL;
    node * last=NULL;

    for(int i=0; i<10; i++)
    {
        if(first==NULL)
        {
            first=(node *) malloc(sizeof(node));
            first->info=i;
            first->next=last;
            last=first;
            last->previous=first;
            first->previous=NULL;
        }

        else
        {
            node * temp=(node *) malloc(sizeof(node));
            temp->next=NULL;
            temp->previous=last;
            temp->info=i;
            last->next=temp;
            last=temp;
        }
        /// inserare la sfarsit
    }

    /// for(int i=0;i<)

//    node * t=last;
//
//    while(t!=NULL)
//    {
//        printf("%d ",t->info);
//        t=t->previous;
//    }
//
//    printf("\n");

    for(int i=0; i<10; i++)
    {
        if(first==NULL)
        {
            first=(node *) malloc(sizeof(node));
            first->info=i;
            first->next=last;
            last=first;
            first->previous=NULL;
            last->previous=NULL;
        }

        else
        {
            node * element=(node *) malloc(sizeof(node));
            element->next=first;
            element->info=i;
            first->previous=element;
            element->previous=NULL;
            first=element;
        }
        /// inserare la inceput
    }

//    node * t=last;
//
//    while(t!=NULL)
//    {
//        printf("%d ",t->info);
//        t=t->previous;
//    }
//
//    printf("\n");

/// delete first
    node * elem=first->next;
    free(first);
    first=elem;

//    node * t=first;
//
//    while(t!=NULL)
//    {
//        printf("%d ",t->info);
//        t=t->next;
//    }
//
//    printf("\n");

/// delete last
    node * elemm=last;
    last=last->previous;
    free(elemm);
    last->next=NULL;

//    node * t=first;
//
//    while(t!=NULL)
//    {
//        printf("%d ",t->info);
//        t=t->next;
//    }
//
//    printf("\n");


/// delete first apparition of 4

    node * t=first;

    while(t!=NULL)
    {
        if(t->info==4)
        {
            t->previous->next=t->next;
            t->next->previous=t->previous;
            free(t);
            break;
        }

        t=t->next;
    }

//    node * tt=first;
//
//    while(tt!=NULL)
//    {
//        printf("%d ",tt->info);
//        tt=tt->next;
//    }
//
//    printf("\n");


    return 0;
}
