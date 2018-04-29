#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define pii pair < ll , ll >
#define vi vector < int >
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
#define vll vector < long long int >
#define sll set < long long int >
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = (ll)1e13;
vector < pair < ll , ll > > graph[100001];
ll dist[100001],p[100001],n,m;
bool vis[100001];
void dijkstra(ll s)
{
    ll i,j,k,x,y,z;
    priority_queue < pii, vector<pii>, greater<pii> > que;
    memset(vis,false,sizeof(vis));
    fill(dist,dist+100001,INF);
    dist[s] = 0;
    que.push(mp(0,s));
    while(!que.empty())
    {
        x = que.top().F;
        y = que.top().S;
        que.pop();
        if(dist[y]!=x)continue;
        for(auto xxx:graph[y])
        {
            if(dist[xxx.F]>dist[y]+xxx.S)
            {
                dist[xxx.F] = dist[y] + xxx.S;
                p[xxx.F] = y;
                que.push({dist[xxx.F],xxx.F});
            }
        }
    }
}
int main()
{
    fastIO;
    ll i,j,k,pp;
    cin>>n>>m;
    fo(i,100001)graph[i].clear();
    fo(i,m)
    {
        cin>>j>>k>>pp;
        graph[j].pb(mp(k,pp));
        graph[k].pb(mp(j,pp));
    }
    dijkstra(1);
    if(dist[n]==INF){cout<<-1;return(0);}
    vector < ll > path;
    i = n;
    while(i!=1)
    {
        path.pb(i);
        i = p[i];
    }
    path.pb(1);
    reverse(path.begin(),path.end());
    for(auto x:path)cout<<x<<" ";
}
//Problem Link: http://codeforces.com/contest/20/problem/C
