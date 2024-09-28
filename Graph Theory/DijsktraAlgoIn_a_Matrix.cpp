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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c, d;
    vector<ll> knight1 = {2,2,-2,-2,1,1,-1,-1};
    vector<ll> knight2 = {1,-1,1,-1,2,-2,2,-2 };
    while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF)
    {
        ll vis[8][8]{};
        ll dis[8][8];
        for(ll i = 0 ;i < 8 ;i++) for(ll j =0 ;j < 8 ;j++) dis[i][j] = INT_MAX;
        pair<ll,ll> st = {a,b};
        pair<ll,ll> en = {c,d};
        dis[a][b] = 0;
        priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>> , greater<pair<ll,pair<ll,ll>>>> q;
        q.push({0,st});
        bool is_find = false;
        while(!q.empty()){
            pair<ll,pair<ll,ll>> node = q.top();
            q.pop();
            if(node.ss == en){
                is_find = true;
                break;
            }
            ll x = node.ss.ff , y = node.ss.ss;
            // cout << x << " " << y << "\n";
            vis[x][y] = 1;
            for(ll i = 0 ;i < 8 ;i++){
                ll new_x = x + knight1[i] , new_y = y + knight2[i];
                if(new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8){
                    if(vis[new_x][new_y] == 0){
                        ll new_d = dis[x][y] + x*new_x + y*new_y;
                        if(new_d<dis[new_x][new_y]){
                            dis[new_x][new_y] = new_d;
                            q.push({new_d,{new_x,new_y}});
                        }
                    }
                }
            }
        }
        if(!is_find) cout << -1 << "\n";
        else cout << dis[c][d] << "\n";
    }
}

/*---Author : Anshul_Pandey--------------------------------------------------------------------------------------------------*/