//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define eb emplace_back
#define mod 1000000007
#define maxN 10000
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
ll vis[maxN];
vector<ll>ans;
void toposortdfs(ll src)
{
    vis[src]=1;
    for(auto u:g[src])
    {
        if(!vis[u])
        {
            toposortdfs(u);
        }
    }
    ans.pb(src);
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
    }
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            toposortdfs(i);
        }
    }
    reverse(ans.begin(),ans.end());
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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