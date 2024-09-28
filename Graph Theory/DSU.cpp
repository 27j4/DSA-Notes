#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
/*---------------------------------------------------------------------------------------------------------------------------*/
const int N = 1e5 + 10;
int parent[N];
int size[N];
void make(int v){
    parent[v] = v;
    size[v] = 1;
}
void find(int v){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = find(parent[v]);
}
void Union(int a , int b){
    a = find(a) , b = find(b);
    if( a != b ){ // b ka parent hum a krdenge // But we want to add chota wla tree to bada wla tree
        // Union of size
        if(size[a] < size[b]){ // size se comparison ho gya 
            swap(a,b);
        }
        parent[b] = a;  //  there are two methods // size and rank -- > Bot have same tc 
        size[a] += size[b];
    }
    // TC --> O(alpha(n)); --> Reverse Ackerman function --> almost constant hi mani jati hai
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // DSU --> make , find --> Parent of the group , union 

    int n , k;
    cin >> n >> k;
    for(ll i = 1; i <= n ;i++){
        make(i);
    }
    while(k--){
        int u , v;
        cin >> u >> v;
        union(u,v);
    }
    int conn_co = 0;
    for(ll i = 1 ;i <=n ;i++){
        if(find[v] == v){
            conn_co++;
        }
    }
    cout <<< conn_co << "\n";
}

/*---Author : Anshul_Pandey--------------------------------------------------------------------------------------------------*/