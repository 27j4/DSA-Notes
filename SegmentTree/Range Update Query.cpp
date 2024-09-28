// Lazy propogation // Lazy Segment Tree
// Kuck Kuch shi soch rha tha mai , Ki jab hme uski jarurat hai tabhi usko update kro 
 
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct  segTree
{
    int size;
    vector<ll> lazy;
    vector<ll> seg;
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        lazy.assign(size*2,0);
        seg.assign(size*2,0);
    } 
    void build(vector<int> &a , ll x , ll lx , ll rx){
        if(rx - lx == 1){
            if(lx < a.size()) seg[x] = a[lx];
            return; 
        }
        int m = (lx+rx)>>1;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
 
    void set(ll l , ll r , ll v , ll x , ll lx , ll rx){
 
        if(rx <= l || lx >= r) return;
 
        // cout << lx << ' ' << rx << ' ' << x  << endl;
        if(lx >= l && r >= rx){
            lazy[x] += v;
            return;
        }
 
        int m = (lx+rx)>>1;
 
        set(l,r,v,2*x+1,lx,m);
        set(l,r,v,2*x+2,m,rx);
    }
 
    void set(ll l , ll r , ll v){
        set(l,r,v,0,0,size);
        // for(auto it : lazy){
        //     cout << it << " ";
        // }
        // cout << "\n";
    }
 
 
    ll ans(ll k , ll x, ll lx , ll rx){
        if(rx - lx == 1) return lazy[x] + seg[x];
 
        int m = (lx+rx)>>1;
 
        ll sum = lazy[x];
        if(k < m){
            return sum + ans(k,2*x+1,lx,m);
        }
        else{
            return sum + ans(k,2*x+2,m,rx);
        }
    }
 
 
    ll ans(ll k){
        return ans(k,0,0,size);
    }
 
    
};
 
 
 
int main(){
    int n , q;
    cin >> n >> q;
    vector<int> vec(n);
    for(auto &it : vec){
        cin >> it;
    }
 
    segTree s1;
    s1.init(n);
    s1.build(vec);
 
    while(q--){
        ll k;
        cin >> k;
        if(k == 2){
            ll idx;
            cin >> idx;
            idx--;
            cout << s1.ans(idx) << "\n";
        }
        else{
            ll l , r , v;
            cin >> l >> r >> v;
            l--;
            s1.set(l,r,v);
        }
    }
 
    // cout << "Anshul Pandey\n";
}