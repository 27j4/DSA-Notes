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
void bubble_sort(vector<int> &vec){
	int n  = vec.size();
	for(int i = 0 ;i < n-1 ;i++){
		for(int j = 0 ; j < n-i-1 ;j++){
			if(vec[j]>vec[j+1]){
				swap(vec[j],vec[j+1]);
			}
		}
	}
}
void selection_sort(vector<int> &vec){
	int n = vec.size();
	for(int i =0 ;i <  n-1;i++){
		int mid_index = i;
		int mini = vec[i];
		for(int j = i+1 ; j < n ;j++){
			if(vec[j] < mini){
				mini = vec[j];
				mid_index = j;
			}
		}
		swap(vec[i],vec[mid_index]);
		//print(vec);
	}
}
void insertion_sort(vector<int> &vec){
	int n = vec.size();
	for(int i = 1 ;i < n ;i++){
		for(int j = i ;j > 0 ;j--){
			if(vec[j-1]>vec[j]){
				swap(vec[j-1],vec[j]);
			}
			else{
				break;
			}
		}
	}
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
    //selection_sort(vec);
    //bubble_sort(vec);
    insertion_sort(vec);
    print(vec);
}

/*---Anshul_Pandey---------------------------------------------------------------------------------------------*/