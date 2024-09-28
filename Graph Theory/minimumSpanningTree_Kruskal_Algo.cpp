#include<bits/stdc++.h>
using namespace std;

vector<int> parent, rk;
long long n , m ,  cost = 0;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};


vector<Edge> edges , result;


int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap(a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            rk[a]++;
    }
}


int main(){
    cin >> n >> m;
    parent.resize(n+1);
    rk.resize(n+1);

    for(int j =1 ; j <= m ; j++){
        int u , v , m;
        cin >> u >> v >> m;
        edges.push_back({u,v,m});
    }

    sort(edges.begin(), edges.end());

    for(int i = 1; i <= n ; i++){
        rk[i] = 0;
        parent[i] = i;
    }   

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
    cout << cost << endl;
}


