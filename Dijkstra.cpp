#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define pii pair < int , int >
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
const ll INF = (ll)1e11;
vector < pair < ll , ll > > graph[100001];
ll dist[100001],p[100001],n,m;
bool vis[100001];
void dijkstra(ll s)
{
    ll i,j,k,x,y,z;
    set < pair < ll , ll > > st;
    set < pair < ll , ll > >::iterator it1,it2;
    memset(vis,false,sizeof(vis));
    fill(dist,dist+100001,INF);
    dist[s] = 0;
    Fo(i,1,n+1)st.insert(mp(dist[i],i));
    Fo(i,1,n+1)
    {
        it1 = st.begin();
        x = it1->F;y = it1->S;st.erase(it1);
        for(auto q:graph[y])
        {
            if(dist[q.F]>dist[y]+q.S)
            {
                st.erase({dist[q.F],q.F});
                dist[q.F] = dist[y] + q.S;
                p[q.F] = y;
                st.insert({dist[q.F],q.F});
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