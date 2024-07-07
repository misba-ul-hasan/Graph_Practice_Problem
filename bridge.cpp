#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>g[1000];
ll vis[1000],tin[1000],tlow[1000],timer;
void dfs(ll p,ll src)
{
    vis[src]=1;
    tin[src]=tlow[src]=timer++;
    for(auto it:g[src])
    {
        if(it==p) continue;
        if(!vis[it])
        {
            dfs(src,it);
            tlow[src]=min(tlow[src],tlow[it]);
            if(tlow[it]>tin[src])
            {
                cout<<src<<" "<<it<<endl;
            }
        }
        else
        {
            tlow[src]=min(tlow[src],tlow[it]);
        }
    }
}
int main()
{
    memset(tin,-1,sizeof(tin));
    memset(tlow,-1,sizeof(tlow));
    ll v,e;
    cin>>v>>e;
    for(ll i=0;i<e;i++)
    {
        ll a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(ll i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            dfs(-1,i);
        }
    }
    return 0;
}