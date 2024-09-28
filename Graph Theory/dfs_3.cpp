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

/*  Detect a cycle in a graph  */

const int N = 1e5+10;
vector<int> g[N];

bool vis[N];
bool dfs(int vertex, int par){
    // Section - 1 :
    /*
    Take vertex in vertex after entering the vertex
    */
    vis[vertex] = true;
    bool isLoopexist = false;
    for(int child : g[vertex]){

        /* For cycle detection */
        if(vis[child] && child == par) continue;
        if(vis[child] && child != par) return true;

        // Section - 2 :
        /*
        Take action on child before entering the child node
        if(vis[child]){
            continue;
        }
        */
        isLoopexist |= dfs(child,vertex);
        // Section - 3 :
        /*
        Take action on child after exiting the child node
        */
    }
    // Section - 4 :
    /*
    Take action on vertex before exiting the vertex
    */
    return isLoopexist;
}


//    ** We have to now modify dfs **
// Now we have a task of storing the connected componets
// vector<vector<int>> vec_cc; -- > for storing all the components
// vector<int> curr_cc; -- > for storing the current components
int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // How to find connected components
    int n ,  e;
    cin >> n >> e;
    for(int i = 0 ;i < e ;i++){
        int a, b;
        cin >> a>> b;;
        g[a].pb(b);
        g[b].pb(a);
    }
    bool flag = false;
    for(int i = 1; i < n ;i++){
        if(vis[i]) continue;
        if(dfs(i,-1)){
            flag = true;
            break;
        }
    }  
    if(flag){
        cout << "Loop exist\n";
    } 
    else{
        cout << "Do not exist\n";
    }
}

/*---Anshul_Pandey---------------------------------------------------------------------------------------------*/
