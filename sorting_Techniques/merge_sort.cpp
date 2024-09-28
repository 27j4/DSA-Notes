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
void print(vector<int> vec){
	int n = vec.size();
	for(int i =0 ;i < n;i++){
		cout << vec[i] << " ";
	}
	cout << "\n";
}
void merge(vector<int> &vec ,int s , int mid , int e){
	vector<int> cpy,a,b;
	loop(i,s,mid+1){
		a.pb(vec[i]);
	}
	loop(i,mid+1,e+1){
		b.pb(vec[i]);
	}
	int i = 0 , j = 0 ;
	int n = a.size() , m = b.size();
	//cerr << s << " " << mid << " " << e << "\n";
	// debug(a);
	// debug(b);
	while(i<n && j<m){
		if(a[i]<b[j]){
			cpy.pb(a[i]);
			i++;
		}
		else{
			cpy.pb(b[j]);
			j++;
		}
	}
	while(i<n){
		cpy.pb(a[i]);
		i++;
	}
	while(j<m){
		cpy.pb(b[j]);
		j++;
	}
	//debug(cpy);
	int idx = 0;
	for(int i = s ;i <= e ;i++){
		vec[i] = cpy[idx++];
	}
	//debug(vec);
}
void mergesort(vector<int> &vec ,int s , int e){
	if(e-s == 0){
		return;
	}
	int mid = (s+e)/2;
	mergesort(vec,s,mid);
	mergesort(vec,mid+1,e);
	merge(vec,s,mid,e);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec(n);
    loop(i,0,n) cin >> vec[i];
    mergesort(vec,0,n-1);
    print(vec);
}

/*---Anshul_Pandey---------------------------------------------------------------------------------------------*/