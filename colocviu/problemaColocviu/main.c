
#include "header.h"

int main()
{
    /// this only works if friends' names start from A (A,B,C,D....)
    /// please do not use random letters for the input :)

    FILE * in=fopen("input.txt","r");
    FILE * out=fopen("output.txt","w");

    read(in);
    int * firstDegreeFriends=findFirstDegreeFriends();
    int * secondDegreeFriends=findSecondDegreeFriends(firstDegreeFriends);
    secondDegreeFriends=sortSecondDegreeFriends(secondDegreeFriends);

    for(int i=0;i<nrTrueSecondDegreeFriends;i++)
    {
        fprintf(out,"%c ",secondDegreeFriends[i]+'A');
    } /// print secondDegreeFriends

    if(nrTrueSecondDegreeFriends==0)
    {
        printf("no second best friends");
    }

    return 0;
}
