#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long ull;
// Gives the kth ancestor of any node if exist else give -1;

const ll maxC = 21;
const ll maxR = 2e5+1;
ll dp[maxR][maxC];
ll n , q;
void preprocess(){
    for(ll i = 1 ; i < maxC ; i++){
        for(ll j = 1 ; j <= n ;j++){
            ll iska_par = dp[j][i-1];// par at (i-1)th level
            if(iska_par == -1){
                continue;
            }
            else{
                dp[j][i] = dp[iska_par][i-1];
            }
        }
    }
}
ll get_ans(ll a , ll k){
    ll i = 0;
    while(i < maxC){
        if((k&(1ll<<i)) && dp[a][i] != -1){
            a = dp[a][i];
            k -= (1ll<<i);
        }
        i++;
    }
    if(k > 0) a = -1;
    return a;
}
ll lca(ll a , ll b){
    ll diff = abs(level[a]-level[b]);
    if(level[a]<level[b]){
        swap(a,b);
    }

    a = get_ans(a,diff);
    if(a == b){
        return a;
    }
    for(ll i = 20 ; i >= 0 ;i--){
        ll aT = dp[a][i], bT = dp[b][i];
        if (aT != bT) a = aT, b = bT;
    }
    return dp[a][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    memset(dp,-1,sizeof(dp));
    vector<ll> tree[n+1];
    for(ll i = 2 ; i <= n ; i++){
        cin >> dp[i][0];
        tree[dp[i][0]].push_back(i);
    }
    preprocess();
    vector<ll> level(n+1,-1);
    level[1] = 0;
    queue<ll> que;
    que.push(1);
    while(!que.empty()){
        ll node = que.front();
        que.pop();
        for(auto it : tree[node]){
            if(level[it] == -1){
                level[it] = level[node] + 1;
                que.push(it);
            }
        }
    }
    while(q--){
        ll a , b;
        cin >> a >> b;
        ll lowest_C_A = lca(a,b);
        cout << lowest_C_A << "\n";
    }
}