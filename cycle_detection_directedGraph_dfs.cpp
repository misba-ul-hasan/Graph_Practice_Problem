//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define eb emplace_back
#define mod 1000000007
#define maxN 1005
#define endl '\n'
#define dekhao(tc,ans) cout<<"Case "<<tc<<": "<<ans<<"\n"
#define rep(i,a,b) for(int i=a;i<b;i++)
const double pi=acos(-1.0);
using namespace std;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
ll dx[]={+1,+0,+0,-1};
ll dy[]={+0,-1,+1,+0};
vector<ll>g[maxN];
bool vis[maxN],vis1[maxN];
bool cycledfs(ll src)
{
    vis[src]=1;
    vis1[src]=1;
    for(auto u:g[src])
    {
        if(!vis[u])
        {
            if(cycledfs(u))
            {
                return true;
            }
        }
        else if(vis1[u])
        {
            return true;
        }
    }
    vis1[src]=0;
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
        //g[b].pb(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(cycledfs(i))
            {
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
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