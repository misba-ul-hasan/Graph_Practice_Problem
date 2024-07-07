#include<bits/stdc++.h>
using namespace std;
int parent[1000005],rnk[1000005];
int findpar(int node)
{
    if(parent[node]==node)
    {
        return node;
    }
    return parent[node]=findpar(parent[node]);
}
void Union(int u,int v)
{
    u=findpar(u);
    v=findpar(v);
    if(rnk[u]<rnk[v])
    {
        parent[u]=v;
    }
    else if(rnk[u]>rnk[v])
    {
        parent[v]=u;
    }
    else
    {
        parent[u]=v;
        rnk[v]++;
    }
}
int main()
{
    for(int i=0;i<1000005;i++)
    {
        parent[i]=i;
        rnk[i]=0;
    }
    int m;
    cin>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    int x,y;
    cin>>x>>y;
    if(findpar(x)!=findpar(y))
    {
        cout<<"diff"<<endl;
    }
    else
    {
        cout<<"Same"<<endl;
    }
    return 0;
}
// struct Disjointsetunion{
//     vector<ll>par,rnk;
//     Disjointsetunion(ll n)
//     {
//         par.resize(n+1);
//         rnk.assign(n+1,0);
//         iota(par.begin(),par.end(),0);
//     }
//     ll find(ll x)
//     {
//         return par[x]=(par[x]==x ? x : find(par[x]));
//     }
//     void unite(ll x,ll y)
//     {
//         x=find(x);
//         y=find(y);
//         if(rnk[x]<rnk[y])
//         {
//             par[x]=y;
//         }
//         else if(rnk[x]>rnk[y])
//         {
//             par[y]=x;
//         }
//         else
//         {
//             par[x]=y;
//             rnk[y]++;
//         }
//     }
//     bool same(ll x,ll y)
//     {
//         return (find(x)==find(y));
//     }
// };