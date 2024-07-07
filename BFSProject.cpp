#include<bits/stdc++.h>
#define maxN 100001
#define ll long long int
using namespace std;
vector<int>adj[100001],cost[100001];
vector<bool>vis(100001);
ll d[100001],p[100001];
vector<ll>ans;
vector<vector<ll>>visV;
int n,e;
void bfs(int v)
{
    queue<int>q;
    q.push(v);
    vis[v]=true;
    p[v]=-1;
    // cout<<"Visited Vertics"<<"     "<<"Vertices in Queue"<<"         "<<"Vertices Traversed Done"<<endl;
    // cout<<v<<"     "<<v<<"         "<<"NULL"<<endl;
    vector<ll>t,t1;
    t.push_back(v);
    visV.push_back(t);
    cout<<"Vertices in Queue: "<<endl;
    cout<<v<<endl;
    ans.push_back((-1));
    while(!q.empty())
    {
        int u=q.front();
        //cout<<u<<" ";
        ans.push_back(u);
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
        queue<int>temp=q;
        vector<ll>V;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                V.push_back(i);
            }
        }
        visV.push_back(V);
        if(temp.empty())
        {
            cout<<"NULL"<<endl;
        }
        while(!temp.empty())
        {
            cout<<temp.front()<<" ";
            temp.pop();
        }
        cout<<endl;
        // cout<<"     ";
        // cout<<u<<endl;
    }
}
int main()
{
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
   cout<<"Visited Vertices: "<<endl;
   for(int i=0;i<visV.size();i++)
   {
       for(int j=0;j<visV[i].size();j++)
       {
           cout<<visV[i][j]<<" ";
       }
       cout<<endl;
   }
   cout<<"Vertices Traversed Done: "<<endl;
   for(int i=0;i<ans.size();i++)
   {
       if(ans[i]==-1)
       {
           cout<<"NULL"<<endl;
       }
       else
       {
           cout<<ans[i]<<endl;
       }
   }
   cout<<"BFS: "<<endl;
   for(int i=0;i<ans.size();i++)
   {
       if(ans[i]==-1)
       {
           continue;
       }
       else
       {
           cout<<ans[i]<<" ";
       }
   }
   cout<<endl;
    return 0;
}