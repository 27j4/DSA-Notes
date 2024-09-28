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

bool cmp(ll a , ll b){
    return a > b;
}
bool dfs(ll v ,vector<ll> adj[] , vector<ll> &vis){
    ll c = vis[v];
    bool chk = false;
    for(auto it : adj[v]){
        if(vis[it] == -1){
            vis[it] = (1^c);
            chk |=  dfs(it,adj,vis);
        }
        if(vis[it] != -1 && vis[it] == vis[v]){
            chk |= true;
        }
    }
    return chk;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    for(ll tt = 1; tt<=t ; tt++){
        cout << "Scenario #" << tt << ":" << "\n";
        ll n , m ;
        cin >> n >> m ;
        vector<ll> adj[n+1];
        vector<ll> vis(n+1,-1), ans;
        for(ll i = 0 ;i < m ;i++){
            ll a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        bool flag = false;
        for(ll i = 1; i <= n ;i++){
            if(vis[i] == -1){
                vis[i] = 1;
                flag = dfs(i,adj,vis);
                if(flag){
                    break;
                }
            }
        }
        debug(vis);
        if(flag){
            cout << "Suspicious bugs found!\n";
        }
        else{
            cout << "No suspicious bugs found!\n";
        }
    }
    return 0;
}