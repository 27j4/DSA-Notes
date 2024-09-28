#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
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
ll arr[200001] , st[800004];
ll idx[200001];
ll sub[200001];
ll timer = 1;
vector<ll> flatten;
void build(ll si , ll ss , ll se)
{
    if(se == ss){
        st[si] = arr[ss];
        return;
    }
    ll mid = (se+ss)/2;
    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);
    st[si] = st[2*si]+st[2*si+1];
}
ll query(ll si , ll ss , ll se , ll qs , ll qe)
{
    if(ss>qe || se<qs){
        return 0;
    }
    if(ss >= qs && se <= qe){
        return st[si];
    }
    ll mid = (ss+se)/2;
    return query(2*si,ss,mid,qs,qe)+query(2*si+1,mid+1,se,qs,qe);
}
void update(ll si , ll ss , ll se , ll qi){
    if(ss == se){
        st[si] = arr[ss];
        return;
    }
    ll mid = (ss+se)/2;
    if(qi <= mid){
        update(2*si,ss,mid,qi);
    }
    else{
        update(2*si+1,mid+1,se,qi);
    }
    st[si] = st[2*si]+st[2*si+1];
}
void dfs(ll node , ll par , vector<ll> tree[]){
    flatten.push_back(node);
    idx[node] = timer;
    timer++;
    ll cnt = 1;
    for(auto it : tree[node]){
        if(it != par){
            dfs(it,node,tree);
            cnt += sub[it]; 
        }
    }
    sub[node] = cnt;
}
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    timer = 1;
    ll n , q , tt;
    cin >> n >> q;
    ll val[n+1];
    for(ll i = 0 ; i < n ;i++){
        cin >> val[i+1];
    }
    vector<ll> tree[n+1];
    for(ll i = 0 ; i < n-1 ; i++){
        ll a , b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    flatten.push_back(0);
    dfs(1,0,tree);
    for(ll i = 1;i <= n ;i++){
        arr[i] = val[flatten[i]];
    }
    build(1,1,n);
    while(q--){
        cin >> tt;
        if(tt == 1){
            ll u , x;
            cin >> u >> x;
            arr[idx[u]] = x;
            update(1,1,n,idx[u]);
        }
        else{
            ll u;
            cin >> u;
            ll idn = idx[u];
            ll subtree = sub[u]-1;
            cout << query(1,1,n,idn,idn+subtree) << "\n";
        }
    }
}