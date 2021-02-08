#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("radiera.in");
ofstream fout("radiera.out");
int n, A[1005],maxi=-1,maxt, pm;
unsigned long long L[1005],S;

int rez;

void afis(int k, int m)
{
    if(m>0)
    {
        int i=k-1;
        while(L[i]!=m-1)
            i--;
        afis(i,m-1);
        /// fout<<A[k]<<" ";
        rez++;
    }
}

int main()
{
    int i,j,maxx;
    fin>>n;
    for(i=1; i<=n; i++)
        fin>>A[i];
    L[1]=1;
    for(i=2; i<=n; i++)
    {
        maxx=0;
        for(j=1; j<i; j++)
            if(A[j]<=A[i] && L[j]>maxx)
                maxx=L[j];
        L[i]=maxx+1;
        if(L[i]>maxt)
        {
            maxt=L[i];
            pm=i;
        }
    }

    afis(pm,maxt);

    fout<<n-rez;

    return 0;
}
