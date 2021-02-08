#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NR_NODES 1005

int adjMatrix[MAX_NR_NODES][MAX_NR_NODES];
int nrFriends[MAX_NR_NODES];

int nrPersons;
int startingPerson;

int nrTrueSecondDegreeFriends;

int allocationSize;


void read(FILE * in);
int * findFirstDegreeFriends();
int * findSecondDegreeFriends(int * firstDegreeFriends);
int * sortSecondDegreeFriends(int * secondDegreeFriends);
