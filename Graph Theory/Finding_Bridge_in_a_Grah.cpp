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
void dfs(ll vertex ,vector<ll> adj[] ,vector<ll> &vis , vector<ll> &in , vector<ll> &low,ll &timer , ll parent){
    vis[vertex] = 1;
    low[vertex] = in[vertex] = timer;
    timer++;
    for(auto child : adj[vertex]){
        if( vis[child] == -1){
            // means it is forward edge
            vis[child] = 1;
            dfs(child,adj,vis,in,low,timer,vertex);
            if(low[child] > low[vertex]){
                cout << vertex << " - " << node << " is a Bridge.\n";
            }
            low[vertex] = min(low[vertex],low[child]);
        }
        else{
            // Not a forward edge // back edge
            if(child == parent) continue;
            else{
                low[vertex] = min(low[vertex],in[child]);
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Finding Bridges in a graph
    ll n , m  , timer = 1;
    cin >> n >> m; // No. of vetices and edges
    vector<ll> adj[n+1];
    vector<ll> vis(n+1,-1);
    for(ll i = 0 ;i < m ;i++){
        ll a, b;
        cin >> a>> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<ll> low(n+1,0); // the main concept of finding the bridges in graph
    vector<ll> in(n+1,0);  // Forward and back edge --> Forward edge are the participants
    dfs(1,adj,vis,in,low,timer,-1); // -1 as a parent
    // cout << "Hi\n";
}

/*---Anshul_Pandey--------------------------------------------------------------------------------------------------*/