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
    // cout << k << "\n";
    if(k > 0) a = -1;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    memset(dp,-1,sizeof(dp));
    for(ll i = 2 ; i <= n ; i++){
        cin >> dp[i][0];
    }
    preprocess();
    ll a , k;
    cin >> a >> k;
    cout << get_ans(a,k) << "\n";
    // cout << "Hi\n";
}
