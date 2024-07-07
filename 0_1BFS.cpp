//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define eb emplace_back
#define mod 1000000007
#define maxN 10005
#define endl '\n'
#define dekhao(tc,ans) cout<<"Case "<<tc<<": "<<ans<<"\n"
#define rep(i,a,b) for(int i=a;i<b;i++)
const double pi=acos(-1.0);
using namespace std;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
ll dx[]={+1,-1,+0,+0};
ll dy[]={+0,+0,+1,-1};
//0-1BFS
vector<ll>g[maxN],cost[maxN];
vector<bool>vis(maxN);
ll d[maxN],p[maxN];
ll bfs(ll src,ll dst)
{
    fill(d,d+maxN,1e9);
    deque<int>q;
    d[src]=0;
    q.push_back(src);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop_front();
        for(ll i=0;i<g[u].size();i++)
        {
            ll v=g[u][i];
            ll c=cost[u][i];
            if(d[v]>d[u]+c)
            {
                d[v]=d[u]+c;
                if(c==0)
                {
                    q.push_front(v);
                }
                else
                {
                    q.push_back(v);
                }
            }
        }
    }
    return d[dst];
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        g[a].pb(b);
        g[b].pb(a);
        cost[a].pb(c);
        cost[b].pb(c);
    }
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    /*int t;
    cin>>t;
    int tc=1;
    while(t--)
    {
        solve();
        tc++;
    }
    //*/solve();
    return 0;
}