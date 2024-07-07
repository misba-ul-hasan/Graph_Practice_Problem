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
struct node{
    int u;
    int v;
    int wt;
    node(int first,int second,int third)
    {
        u=first;
        v=second;
        wt=third;
    }
};
void solve(int tc)
{
    ll v,e;
    cin>>v>>e;
    vector<node>g;
    for(ll i=1;i<=e;i++)
    {
        ll a,b,wt;
        cin>>a>>b>>wt;
        g.pb(node(a,b,wt));
    }
    ll src;
    cin>>src;
    vector<ll>dis(v+1,LLONG_MAX);
    dis[src]=0;
    for(ll i=1;i<=(v-1);i++)
    {
        for(auto it:g)
        {
            if((dis[it.u]+it.wt)<dis[it.v])
            {
                dis[it.v]=dis[it.u]+it.wt;
            }
        }
    }
    for(auto it:g)
    {
        if(dis[it.u]+it.wt<dis[it.v])
        {
            cout<<"Negative Cycle"<<endl;
            return;
        }
    }
    for(ll i=1;i<=v;i++)
    {
        cout<<dis[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc=1;
    int t;
    cin>>t;
    while(t--)
    {
        solve(tc);
        tc++;
    }
    //solve(tc);
    return 0;
}