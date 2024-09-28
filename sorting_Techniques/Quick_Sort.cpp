/*______JAI_SHRI_RAM______*/

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
int get_cons(int arr[] ,int low , int high){
    int i =low , j = high;
    int pivot = low;
    while(i<j){
        while(arr[i] <= arr[pivot] && i < high){
            i++;
        }
        while(arr[j] >= arr[pivot] &&  j > low){
            j--;
        }
        if(i < j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[pivot],arr[j]);
    return j;
}
void quick_sort(int arr[] , int low , int high){
    if(low<high){
        int pvt_idx = get_cons(arr,low,high);
        quick_sort(arr,low,pvt_idx-1);
        quick_sort(arr,pvt_idx+1,high);
    }
} 
int main()
{
#ifndef Anshul_Pandey
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n;i++){
        cin >> arr[i];
    }
    quick_sort(arr,0,n-1);
    for(int i = 0 ;i < n ;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}