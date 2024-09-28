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
struct segmentTree{
    int size;
    vector<int> count;
    void init(int n){
        size = 1;
        while(size < n){
            size*=2;
        }
        count.assign(2*size,0);
    }
    void build(vector<int> &a , int x , int lx , int rx){
        if(rx-lx == 1){
            if(lx < (int)a.size()){
                count[x] = a[lx]; 
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        count[x] = count[2*x+1] + count[2*x+2];
    }
    void build(vector<int> &a){
        build(a,0,0,size);
        // debug(count);
    }


    void set(int i , int x , int lx , int rx){
        if(rx - lx == 1){
            int prev = count[x];
            count[x] = 1 - prev;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m){
            set(i,2*x+1,lx,m);
        }
        else{
            set(i,2*x+2,m,rx);
        }
        count[x] = count[2*x+1] + count[2*x+2];
    }
    void set(int i){
        set(i,0,0,size);
        // debug(count);
    }

    int kthone(int k ,int x,  int lx , int rx){
        int current = count[x];
       
    }
    int kthone(int k){
        return kthone(k,0,0,size);
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
    for(int i = 0 ; i < n ;i++) cin >> a[i];


    segmentTree st;
    st.init(n);
    st.build(a);

    while(m--){
        int op , var;
        cin >> op >> var;
        if(op == 1){
            st.set(var);
        }
        else{
            cout << st.kthone(var+1) << "\n";
        }
    }

    // cout << "Anshul Pandey\n";
}