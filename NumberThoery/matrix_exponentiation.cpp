#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb emplace_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define rloop(i,b,a) for(ll i=b;i>=a;i--)
#define test int t; cin>>t; while(t--)
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<":"; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
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
/*--------------------------------------------------------------------------------------------------------------*/
ll T[3][3];
ll temp[3][3];
const ll m = 1e9+7;
void matrixmul(ll a[][3] , ll b[][3]){
	memset(temp,0,sizeof(temp));
	for(ll i =1  ;i < 3 ;i++){
		for(ll j = 1 ;j < 3;j++){
			for(ll k = 1 ; k < 3 ;k++){
				temp[i][j] = (temp[i][j] + a[i][k]*b[k][j])%m;
			}
		}
	}
	// cout << "HI\n";
	for(ll i = 1; i < 3 ;i++){
		for(ll j = 1 ;j < 3 ;j++){
			// cout << temp[i][j] << " ";
			a[i][j] = temp[i][j];
		}
		// cout << "\n";
	}
}
void matrixexpo(ll T[][3],ll n){
	ll res[3][3];
	for(ll i = 1 ;i < 3;i++){
		for(ll j = 1 ;j < 3 ;j++){
			if(i==j){
				res[i][j] = 1;
			}
			else{
				res[i][j] = 0;
			}
		}
	}
	while(n){
		if(n&1){
			matrixmul(res,T);
			n--;
		}
	else{
			matrixmul(T,T);
			n = n/2;
		}
	}
	for(ll i = 1;i < 3 ;i++){
		for(ll j =1;j < 3 ;j++){
			// cout << res[i][j] << " ";
			T[i][j] = res[i][j];
		}
		// cout << "\n";
	}
}
ll fibo(ll n){
	if(n<=0){
		return 0;
	}
	ll a[3] = {0,1,0};
	T[1][1] = T[1][2] = T[2][1] = 1;
	T[2][2] = 0;
	// for(ll i = 1;i < 3 ;i++){
	// 	for(ll j =1;j < 3 ;j++){
	// 		cout << T[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	matrixexpo(T,n-1);
	// for(ll i = 1;i < 3 ;i++){
	// 	for(ll j =1;j < 3 ;j++){
	// 		cout << T[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	return (a[1]*T[1][1] + a[2]*T[2][1])%m;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n ;
    cin >> n;
    cout << fibo(n) << "\n";
}

/*---Anshul_Pandey---------------------------------------------------------------------------------------------*/