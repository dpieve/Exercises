#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000;

typedef pair < int, int > ii;

int t, n, m, k, p[MAXN], sz[MAXN];
vector < pair <int, ii > > g;

int find (int x) { return p[x] == x ? x : p[x] = find (p[x]); }

bool same (int u, int v) { return find (u) == find (v); }

void unite (int u, int v) {
    u = find (u);
    v = find (v);
    if (u != v) {
        if (sz[u] < sz[v]) swap (u, v);
        p[v] = u;
        sz[u] += sz[v];
    }
}

int mst () {
    sort (g.begin(), g.end());
    
    int cost = 0;

    for (auto x : g) {

        int u = x.second.first;
        int v = x.second.second;
        int w = x.first;

        if (!same (u, v)) {
            cost += w;
            unite (u, v);
        }
    }
    return cost;

}


int main () {

    scanf("%d", &t);
    for (int cc = 1; cc <= t; ++cc) {

        scanf("%d %d %d", &n, &m, &k);

        g.clear();
        for (int i = 0; i < n + 10; ++i) {
            p[i] = i;
            sz[i] = 1;
        }
        int a, b, c;

        for (int i = 0; i < k; ++i) {
            scanf("%d", &a);
            g.push_back({ 0, { n, a - 1} } );
        }

        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            g.push_back ({c, {a - 1, b - 1}});
        }

        printf("Case #%d: %d\n", cc, mst());
    }



    return 0;
}
