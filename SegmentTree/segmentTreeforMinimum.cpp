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
void read(vector<ll> &vec){for(ll i = 0 ; i < vec.size();i++)cin >> vec[i];}
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
struct segtree{
    int size;
    vector<int> minimum;
    void init(int n){
        size = 1;
        while(size < n){
            size*=2;
        }
        minimum.assign(2*size,INT_MAX);
    }
    void build(vector<int> &a , int x , int lx , int rx){
        if(rx - lx == 1){
            if(lx < int(a.size())){
                minimum[x] = a[lx];
            }
            return;
        }

        int m = (lx+rx)>>1;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        minimum[x] = min(minimum[2*x+1],minimum[2*x+2]);
    }
    void build(vector<int> &a){
        build(a,0,0,size);
        // for(auto it : minimum){
        //     cout << it << " ";
        // }
        // cout << "\n";
        debug(minimum);
    }

    void set(int i , int v , int x , int lx , int rx){
        if(rx-lx == 1){
            minimum[x] = v;
            return;
        }

        int m = (lx+rx)>>1;
        if(i < m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        minimum[x] = min(minimum[2*x+1],minimum[2*x+2]);
    }
    void set(int i , int v){
        set(i,v,0,0,size);
        // for(auto it : minimum){
        //     cout << it << " ";
        // }
        // cout << "\n";
        debug(minimum);
    }
    int mini(int l , int r , int x , int lx , int rx){
        if(rx <= l || r <= lx){
            return INT_MAX;
        }
        if(lx >= l && r >= rx){
            return minimum[x];
        }
        int m = (lx+rx)>>1;

        int mini1 = mini(l,r,2*x+1,lx,m);
        int mini2 = mini(l,r,2*x+2,m,rx);
        return min(mini1,mini2);
    }
    int mini(int l , int r){
        return mini(l,r,0,0,size);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m;
    cin >> n >> m;
    vector<int> a(n);
    segtree st;
    st.init(n);
    for(int i = 0 ; i < n ;i++) cin >> a[i];
    st.build(a);
    while(m--){
        int op;
        cin >> op;
        if(op ==1){
            int i , v;
            cin >> i >> v;
            st.set(i,v);
        }
        else{
            int l , r;
            cin >> l >> r;
            cout << st.mini(l,r) << "\n";
        }
    }
}   