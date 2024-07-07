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
vector<ll>g[maxN];
ll vis[maxN];
bool BipartiteBfs(ll src)
{
    queue<ll>q;
    q.push(src);
    vis[src]=1;
    while(!q.empty())
    {
        ll v=q.front();
        q.pop();
        for(auto u:g[v])
        {
            if(vis[u]==-1)
            {
                vis[u]=1-vis[v];
                q.push(u);
            }
            else if(vis[u]==vis[v])
            {
                return false;
            }
        }
    }
    return true;
}
bool BipartiteDfs(ll src)
{
    if(vis[src]==-1)
    {
        vis[src]=0;
    }
    for(auto u:g[src])
    {
        if(vis[u]==-1)
        {
            vis[u]=1-vis[src];
            if(!BipartiteDfs(u)) return false;
        }
        else if(vis[u]==vis[src])
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    memset(vis,-1,sizeof(vis));
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
        ll a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==-1)
        {
            if(!BipartiteDfs(i))
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    int tc=1;
    while(t--)
    {
        solve();
        tc++;
    }
    //solve();
    return 0;
}