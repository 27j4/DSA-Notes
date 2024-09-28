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
double eps = 1e-6; // for 5 digit accuracy [ Acuurcay bata rha hai]
double binpow(double mid , double n){
    int q = (int)n;
    //cout << "q " << q << "\n"; 
    double res = 1;
    while(q){
        if(q&1){
            res = res*mid;
            q--;
        }
        else{
            mid = mid*mid;
            q = q/2;
        }
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double x ,n;
    cin >> x >> n;
    double l =0 , h = x , mid;
    while(h-l>eps){ // Syntax for floating point numbers
    	// Author - Anshul Pandey
    	mid = (l+h)/2;
    	if(binpow(mid,n)<x){
            //cout << binpow(mid,n) << "\n";
    		l = mid;
    	}
    	else{
    		h = mid;
    	}
    }
    // Time complexity [logn*log(10^accuracy)] // -> for sqrt of a number 
    cout << l << "\n";
}
/*__*/

/*---Anshul_Pandey---------------------------------------------------------------------------------------------*/