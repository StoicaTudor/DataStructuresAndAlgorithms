#include <stdio.h>
#include <stdlib.h>
#define MAX_CHILD 25

typedef struct treeNode
{
    char info;
    struct treeNode * children[MAX_CHILD];
} treeNode;

treeNode *createBinTree()
{
    treeNode *p;
    char c;

    scanf("%d",&c);

    if(c== '*')
    {
        return NULL;
    }

    else
    {
        p=(treeNode *) malloc(sizeof(treeNode));

        if(p==NULL)
        {
            printf("Out of space\n");
            exit(1);
        }

        p->id=c;
//        p->left=createBinTree();
//        p->right=createBinTree();
        for(int i=0; i<0; i++)
        {

        }
    }
    return p;
}

int main()
{
    treeNode * root=createBinaryTree();

    return 0;
}
