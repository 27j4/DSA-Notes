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

// adjacency list

const int N = 1e3+10;
vector<pair<int,int>> graph[N];
// wt and connected vertices
int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // adjacencey list - > method
    // s.c -> O(v+e)
    for(int i =0 ;i < m ;i++){
    	int v1 , v2 , wt;
    	cin >> v1 >> v2;
    	graph[v1].pb({v2.wt});
    	graph[v2].pb({v1,wt});
    }
    // n<= 10^3
   	// S.C --> O(n+m)

   	// i,j connected ? i,j > wt? // O(N)
   	for(pair<int,int> child :graph[i]){
   		if(child.ff == j){
   			// connected
   			child.ss = wt // weight
   		}
   	}
}

/*---Anshul_Pandey---------------------------------------------------------------------------------------------*/
