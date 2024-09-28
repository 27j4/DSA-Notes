#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
typedef long long ll;


// Code for finding the number of distinct elements in the range [a , b] for each query 
// the query's are offline -> means the queries are given at a time 

/*

Approach :

1. sort the queries
2.for each element find the left most index of it while iterating from rigth to left

*/


class SegmentTree{
public:

    vector<int> seg;
    int size;

    void init(int n){ // nearest power of 2 
        int res = 1; 
        while(res < n){
            res*=2;
        }
        size = res;
        seg.assign(size*2,0);
    }


    // There is no use of build function here becuase all the element in the seg is 0


    // [lx , rx)
    void update(int i , int el , int x , int lx , int rx){ // here is the node of the tree and it is representing the index the seg array
        if(rx - lx == 1){ // base case
            seg[x] = el;
            return;
        }

        int m = (lx+rx) >> 1;

        if(i < m){
            update(i,el,2*x+1,lx,m);
        }
        else{
            update(i,el,2*x+2,m,rx);
        }

        seg[x] = seg[2*x+1] + seg[2*x+2];

    }

    void update(int i , int el){ // change a[i] to el
        update(i,el,0,0,size);
    }


    int query(int l , int r , int x , int lx , int rx){
        if(l <= lx && r >= rx){
            return seg[x];
        }
        if(rx <= l || lx >= r){
            return 0;
        }

        int m = (lx + rx)/2;


        return query(l , r , 2*x+1 , lx , m) + query(l , r , 2*x+2 , m , rx);

    }


    int query(int l , int r){
        return query(l,r,0,0,size);
    }


};


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n , m;
    cin >> n >> m;
    vector<int> elements(n);
    for(int i = 0 ; i < n ; i++){
        cin >> elements[i];
    }


    SegmentTree st;
    st.init(n);


    vector<vector<pair<int,int>>> query(n);
    for(int i = 0 ; i < m ; i++){
        int a , b;
        cin >> a >> b;
        a--;
        query[a].push_back({b,i});
    }

    map<int,int> lastIndex;

    vector<int> ans(m);

    for(int i = n-1 ; i >= 0 ; i--){
        if(lastIndex.find(elements[i]) == lastIndex.end()){
            lastIndex[elements[i]] = i;
            st.update(i,1);
        }
        else{
            st.update(lastIndex[elements[i]],0);
            lastIndex[elements[i]] = i;
            st.update(lastIndex[elements[i]],1);
        }


        for(auto it : query[i]){
            ans[it.ss] = st.query(i,it.ff);
        }
    }
    for(auto it : ans){
        cout << it << "\n";
    }    
}   