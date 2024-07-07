#include<bits/stdc++.h>
using namespace std;
int adjmat[100][100];
int main()
{
    int v,e;
    cin>>v>>e;
    for(int i=0;i<=v;i++)
    {
        for(int j=0;j<=v;j++)
        {
            adjmat[i][j]=0;
        }
    }
    for(int i=1;i<=e;i++)
    {
        int a,b;
        cin>>a>>b;
        adjmat[a][b]=1;
        adjmat[b][a]=1;
    }
    for(int i=0;i<=v;i++)
    {
        for(int j=0;j<=v;j++)
        {
            cout<<adjmat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}