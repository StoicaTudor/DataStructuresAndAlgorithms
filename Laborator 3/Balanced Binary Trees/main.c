#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    char id;
    struct nodeType *left,*right;
}NodeT;

NodeT *createBalBinTree(int nbOfNodes)
{
    NodeT *p;
    if(nbOfNodes==0)
    {
        return NULL;
    }

    int nLeft = nbOfNodes/2;
    int nRight=nbOfNodes-nLeft-1;
    p=(NodeT *) malloc(sizeof(NodeT));

    if(p)
    {
        printf("Node identifier in preorder=");
        scanf("%c",&p->id);
        p->left=createBalBinTree(nLeft);
        p->right=createBalBinTree(nRight);
    }
    else abort();
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
    int nbOfNodes=0;
    scanf("%d",&nbOfNodes);
    NodeT *root=createBalBinTree(nbOfNodes);

    preorder(root,0);

    return 0;
}
