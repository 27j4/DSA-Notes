#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb emplace_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define rloop(i,b,a) for(ll i=b;i>=a;i--)
#define test int t; cin>>t; while(t--)
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<":"; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
/*--------------------------------------------------------------------------------------------------------------*/
// DFS -> Depth first search
// Many order can be form using the dfs
// Site -  visualisealgo.net
/*---------------------------------------------------------------------------------------------------------------*/
const int N = 1e5+10;
vector<int> g[N];

bool vis[N];

void dfs(int vertex){
    // Section - 1 :
    /*
    Take vertex in vertex after entering the vertex
    */
    if(vis[vertex]){
        return;
    }
    vis[vertex] = true;
    for(int child : g[vertex]){
        // Section - 2 :
        /*
        Take action on child before entering the child node
        */
        /*
        if(vis[child]){
            continue;
        }
        */
        dfs(child);
        // Section - 3 :
        /*
        Take action on child after exiting the child node
        */
    }
    // Section - 4 :
    /*
    Take action on vertex before exiting the vertex
    */
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m;
    cin >> n >> m;
    for(int i =0 ;i < 9 ;i++){
        int v1 , v2 , wt;
        cin >> v1 >> v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
}

/*---Anshul_Pandey---------------------------------------------------------------------------------------------*/
