#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define loop(i,a,b) for(ll i=a;i<b;i++)
typedef long long ll;
typedef unsigned long long ull;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<":"; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-------------------------------------------------------------------------------------------------------------------*/
 vector<pair<ll,ll>> adj[400009];
 ll vis[400000];
 ll dis[400000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n , m;
    cin >> n >> m;
    for(ll i = 0 ;i < m ;i++){
        ll a , b , c;
        cin >> a >> b >> c;
        adj[a].pb({b,c});
        // adj[b].pb({a,c});
    }
    memset(vis,-1,sizeof(vis));
    // vector<ll> vis(n+1,-1);
    for(ll i = 0 ;i <= n ;i++){
        dis[i] = LLONG_MAX;
    }
    // vector<ll> dis(n+1,LLONG_MAX);
    dis[1] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>> , greater<pair<ll,ll>>> q;
    // vis[1] = 1;
    q.push({0,1});
    while(!q.empty()){
        // cout << "Hi\n";
        pair<ll,ll> node = q.top();
        ll ele = node.second;
        ll d = node.first;
        q.pop();
        if(vis[ele] == -1){
            for(auto it : adj[ele]){
                ll f = it.first , s = it.second;
                dis[f] = min(dis[f],d + s);
                q.push({dis[f],f});
                // vis[f] = 1;
            }
            vis[ele] = 1;
        }
    }
    for(ll i = 1ll ;i <= n ;i++){
        cout << dis[i] << " ";
    }
    cout << "\n";
}
 
