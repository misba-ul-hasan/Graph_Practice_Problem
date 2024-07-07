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
vector<ll>g[maxN],cost[maxN];
vector<bool>vis(maxN);
bool cyclebfs(ll src)
{
    queue<pair<ll,ll>>q;
    vis[src]=true;
    q.push({src,-1});
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        ll v=p.first;
        ll par=p.second;
        for(auto u:g[v])
        {
            if(!vis[u])
            {
                vis[u]=true;
                q.push({u,v});
            }
            else if(u!=par)
            {
                return true;
            }
        }
    }
    return false;
}
bool cycledfs(ll src,ll par)
{
    vis[src]=true;
    for(auto u:g[src])
    {
        if(!vis[u])
        {
            if(cycledfs(u,src)) return true;
        }
        else if(u!=par)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
        ll a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
        // cost[a].pb(c);
        // cost[b].pb(c);
    }
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(cycledfs(i,-1))
            {
                cout<<"Yes"<<endl;
                return;
            }
        }
    }
    cout<<"No"<<endl;
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