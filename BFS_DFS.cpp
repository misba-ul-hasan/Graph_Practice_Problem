#include<bits/stdc++.h>
#define maxN 100001
#define ll long long int
using namespace std;
vector<int>adj[100001],cost[100001];
vector<bool>vis(100001);
ll d[100001],p[100001];
void bfs(int v)
{
    queue<int>q;
    q.push(v);
    vis[v]=true;
    p[v]=-1;
    while(!q.empty())
    {
        int u=q.front();
        cout<<u<<" ";
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            if(!vis[adj[u][i]])
            {
                q.push(adj[u][i]);
                vis[adj[u][i]]=true;
                d[adj[u][i]]=d[u]+1;
                p[adj[u][i]]=u;
            }
        }
    }
}
void pathfind(int v)
{
    if(!vis[v])
    {
        cout<<"No Path"<<endl;
    }
    else
    {
        vector<int>path;
        for(int i=v;i!=-1;i=p[i])
        {
            path.push_back(i);
        }
        reverse(path.begin(),path.end());
        cout<<"Path: ";
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
}
ll bfs1(ll src,ll dst)
{
    fill(d,d+maxN,1e9+7);
    p[src]=-1;
    d[src]=0;
    queue<ll>q;
    q.push(src);
    while(!q.empty())
    {
        ll v=q.front();
        q.pop();
        for(ll i=0;i<adj[v].size();i++)
        {
            ll u=adj[v][i];
            ll c=cost[v][i];
            if(d[u]>d[v]+c)
            {
                d[u]=d[v]+c;
                p[u]=v;
                q.push(u);
            }
        }
    }
    return d[dst];
}
void dfs(int v)
{
    vis[v]=true;
    cout<<v<<" ";
    for(auto u : adj[v])
    {
        if(!vis[u])
        {
            dfs(u);
        }
    }
}
void dfs1(int v)
{
    stack<int>st;
    st.push(v);
    vis[v]=true;
    while(!st.empty())
    {
        int u=st.top();
        cout<<u<<" ";
        st.pop();
        for(auto child : adj[u])
        {
            if(!vis[child])
            {
                st.push(child);
                vis[child]=true;
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1);
    //bfs(0);
    // for(int i=0;i<n;i++)
    // {
    //     pathfind(i);
    // }
    //dfs(0);
    //cout<<endl;
   // memset(vis,0,sizeof(vis));
   // dfs1(0);
    return 0;
}