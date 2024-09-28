#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Edge {
    int a, b, cost;
};

int n, m;
vector<Edge> edges;
const int INF = 1e15;

void solve()
{
    vector<int> d(n+1);
    vector<int> p(n+1, -1);
    int x;
    for (int i = 1; i <= n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = max(-INF, d[e.a] + e.cost);
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO";
    } else {
        for (int i = 1; i <= n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}

signed main(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int a , b , c;
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }
    solve();
}