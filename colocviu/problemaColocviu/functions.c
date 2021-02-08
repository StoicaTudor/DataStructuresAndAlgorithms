#include "header.h"

void read(FILE * in)
{
    char residualCh;

    fscanf(in,"%d",&nrPersons); /// read nr persons
    fscanf(in,"%c",&residualCh); /// read that residual space
    fscanf(in,"%c\n",&startingPerson); /// residual the startingPerson (letter)
    startingPerson-='A'; /// we work with small numbers, so substract 66 (A)


    char * s=(char *) malloc(sizeof(char) * 255);

    for(int i=0; i<nrPersons; i++)
    {
        fgets(s,255,in);

        char * token=NULL;
        token = strtok(s, " \n\0");

        bool first=true;

        while(token!=NULL)
        {
            if(first==true)
            {
                first=false;
            } /// we ignore the first letter in token (we do not need it)

            else
            {
                adjMatrix[i][nrFriends[i]]=token[0]-'A'; /// substract A (66)
                nrFriends[i]++;
            }

            token = strtok(NULL, " \n\0");
        }
    }
}

int * findFirstDegreeFriends()
{
    int * firstDegreeFriends=(int *) malloc(sizeof(int) * nrFriends[startingPerson]);

    for(int i=0; i<nrFriends[startingPerson]; i++)
    {
        firstDegreeFriends[i]=adjMatrix[startingPerson][i];
        allocationSize+=nrFriends[adjMatrix[startingPerson][i]]; /// we need this to allocate the secondDegreeFriends array
    }

    return firstDegreeFriends; /// return firstDegreeFriends
}

int * findSecondDegreeFriends(int * firstDegreeFriends)
{
    int * secondDegreeFriends=(int *) malloc(sizeof(int) * allocationSize); /// allocate with secondDegreeFriends size
    int * frequenceArray=(int *) calloc(105,sizeof(int)); /// we need this in order to nor have duplicates

    for(int i=0; i<nrFriends[startingPerson]; i++) /// pentru fiecare prieten
    {
        frequenceArray[adjMatrix[startingPerson][i]]=1; /// put frequence to 1
    }

    frequenceArray[startingPerson]=1; /// not necessary

    for(int i=0; i<nrFriends[startingPerson]; i++) /// pentru fiecare prieten
    {

        int friendd=adjMatrix[startingPerson][i]; /// denote friendd shorter

        for(int j=0; j<nrFriends[friendd]; j++) /// pentru fiecare prieten al prietenului
        {

            if(frequenceArray[adjMatrix[friendd][j]]==0) /// not a first degree friend
            {

                int secondRealFriend=adjMatrix[friendd][j]; /// we found the secondRealFriend
                frequenceArray[adjMatrix[friendd][j]]=1; /// set its frequence to 1 (not visit it anymore)

                secondDegreeFriends[nrTrueSecondDegreeFriends++]=secondRealFriend; /// put secondRealFriend in our to print array
            }
        }
    }
    return secondDegreeFriends;
}

int * sortSecondDegreeFriends(int * secondDegreeFriends) /// sort then alphabetically
{
    for(int i=0; i<nrTrueSecondDegreeFriends-1; i++)
    {
        for(int j=i+1; j<nrTrueSecondDegreeFriends; j++)
        {
            if(secondDegreeFriends[i]>secondDegreeFriends[j])
            {
                int aux=secondDegreeFriends[i];
                secondDegreeFriends[i]=secondDegreeFriends[j];
                secondDegreeFriends[j]=aux;
            }
        }
    }

    return secondDegreeFriends;
}
