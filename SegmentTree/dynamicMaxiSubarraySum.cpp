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
    vector<vector<long long>> cope;
    // seg , sum , pref , suff
    void init(int n){
        size = 1;
        while(size < n){
            size*=2;
        }
        cope.assign(2*size,{0,0,0,0});
    }

    void build(vector<int> &a , int x , int lx , int rx){
        if(rx - lx == 1){
            if(lx < int(a.size())){
                cope[x] = {max(0,a[lx]),a[lx],max(0,a[lx]),max(0,a[lx])}; 
            }
            return;
        }
        int m = (lx+rx)>>1;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);


        // seg
        cope[x][0] = max(cope[2*x+1][0],cope[2*x+2][0]);
        cope[x][0] = max(cope[x][0],cope[2*x+1][3]+cope[2*x+2][2]);

        // sum
        cope[x][1] = cope[2*x+1][1] + cope[2*x+2][1];

        // prefix
        cope[x][2] = max(cope[2*x+1][2],cope[2*x+2][2]+cope[2*x+1][1]);

        // suffix
        cope[x][3] = max(cope[2*x+2][3],cope[2*x+2][1]+cope[2*x+1][3]);

    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }


    void set(int i , int v , int x , int lx , int rx){
        // 
        if(rx - lx == 1){
            cope[x] = {max(0,v),v,max(0,v),max(0,v)};
            return;
        }
        int m = (lx+rx)>>1;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }

        // seg
        cope[x][0] = max(cope[2*x+1][0],cope[2*x+2][0]);
        cope[x][0] = max(cope[x][0],cope[2*x+1][3]+cope[2*x+2][2]);

        // sum
        cope[x][1] = cope[2*x+1][1] + cope[2*x+2][1];

        // prefix
        cope[x][2] = max(cope[2*x+1][2],cope[2*x+2][2]+cope[2*x+1][1]);

        // suffix
        cope[x][3] = max(cope[2*x+2][3],cope[2*x+2][1]+cope[2*x+1][3]);

    }
    void set(int i , int v){
        set(i,v,0,0,size);
    }

    long long maxi(){
        return cope[0][0];
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

    cout << st.maxi() << "\n";
    while(m--){
        int i , v;
        cin >> i >> v;
        st.set(i,v);
        cout << st.maxi() << "\n";
    }
}