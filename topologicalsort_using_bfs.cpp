//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define eb emplace_back
#define mod 1000000007
#define maxN 100005
#define endl '\n'
#define all(x) x.begin(),x.end()
#define dekhao(tc,ans) cout<<"Case "<<tc<<": "<<ans<<"\n"
#define rep(i,a,b) for(int i=a;i<b;i++)
const double pi=acos(-1.0);
using namespace std;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
ll dx[]={+1,+0,+0,-1};
ll dy[]={+0,-1,+1,+0};
vector<ll>g[maxN];
ll deg[maxN];
queue<ll>q;
vector<ll>ans;
void topobfs()
{
    while(!q.empty())
    {
        ll v=q.front();
        q.pop();
        ans.pb(v);
        for(auto u:g[v])
        {
            deg[u]--;
            if(deg[u]==0)
            {
                q.push(u);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
        ll a,b;
        cin>>a>>b;
        g[a].pb(b);
    }
    for(ll i=0;i<n;i++)
    {
        for(auto x:g[i])
        {
            deg[x]++;
        }
    }
    for(ll i=0;i<n;i++)
    {
        if(deg[i]==0)
        {
            q.push(i);
        }
    }
    topobfs();
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}