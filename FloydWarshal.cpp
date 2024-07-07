//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define pb push_back
#define eb emplace_back
#define mod 1000000007
#define maxN 100005
#define endl '\n'
#define all(x) x.begin(),x.end()
#define dekhao(tc,ans) cout<<"Case "<<tc<<": "<<ans<<"\n"
#define rep(i,a,b) for(int i=a;i<b;i++)
#define min_heap priority_queue<ll,vector<ll>,greater<ll>>
template <typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const double pi=acos(-1.0);
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
ll binpow(ll b,ll p){ll res=1;while(p){if(p%2==0){b*=b;p/=2;}else{res*=b;p--;}}return res;}
ll dx[]={+1,+0,+0,-1};
ll dy[]={+0,-1,+1,+0};
ll inf=1e17;
void solve(int tc)
{
    ll n,m,q;
    cin>>n>>m>>q;
    ll dist[n+1][n+1];
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            if(i==j)
            {
                dist[i][j]=0;
            }
            else
            {
                dist[i][j]=inf;
            }
        }
    }
    for(ll i=1;i<=m;i++)
    {
        ll a,b,wt;
        cin>>a>>b>>wt;
        dist[a][b]=min(wt,dist[a][b]);
        dist[b][a]=min(dist[b][a],wt);
    }
    for(ll k=1;k<=n;k++)
    {
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
            }
        }
    }
    for(ll i=1;i<=q;i++)
    {
        ll x,y;
        cin>>x>>y;
        if(dist[x][y]==inf)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<dist[x][y]<<endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc=1;
    solve(tc);
    return 0;
}