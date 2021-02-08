#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    char id;
    struct node_type *left, *right;

} NodeT;

NodeT *createBinTree()
{
    NodeT *p;
    char c;

    scanf("%c",&c);

    if(c== '*')
    {
        return NULL;
    }

    else
    {
        p=(NodeT *) malloc(sizeof(NodeT));

        if(p==NULL)
        {
            printf("Out of space\n");
            exit(1);
        }

        p->id=c;
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}

void preorder(NodeT *p,int level)
{
    if(p!=NULL)
    {
        for(int i=0;i<=level;i++)
        {
            printf("*");
        }
        printf("%c\n",p->id);
        preorder(p->left,level+1);
        preorder(p->right,level+1);
    }
}

void inorder(NodeT *p,int level)
{
    if(p!=NULL)
    {
        inorder(p->left,level+1);

        for(int i=0;i<=level;i++)
        {
            printf(" ");
        }

        printf("%c\n",p->id);

        inorder(p->right,level+1);
    }
}

void postorder(NodeT *p,int level)
{
    if(p!=NULL)
    {
        postorder(p->left,level+1);
        postorder(p->right,level+1);

        for(int i=0;i<=level;i++)
        {
            printf(" ");
        }
        printf("%c\n",p->id);
    }
}

int main()
{
    NodeT * root=createBinTree();
     preorder(root,0);
    /// inorder(root,0);
    /// postorder(root,0);

    return 0;
}///12345***67*89**
