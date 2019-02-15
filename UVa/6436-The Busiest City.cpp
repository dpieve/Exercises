#include <bits/stdc++.h>

using namespace std;

const int MAXN = 212345;

int T, N, sz[MAXN];

vector < int > g[MAXN];

int dfs (int u, int p) {
    
    sz[u] = 1;
    
    for (int i = 0; i < g[u].size(); ++i) {
        
        int v = g[u][i];
        if (v != p) sz[u] += dfs (v, u);
        
    }

    return sz[u];
}


int solve (int u, int p) {

    int paths = (N - sz[u]) * (sz[u] - 1);

    for (int i = 0; i < g[u].size(); ++i) {
        
        int v = g[u][i];

        if (v != p) {

            paths += (N - sz[v] - 1) * sz[v];

        }
    }

    paths /= 2;

    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v != p) paths = max (paths, solve (v, u));
    }

    return paths;

}


int main () {

    scanf("%d", &T);

    for (int cc = 1; cc <= T; ++cc) {

        scanf("%d", &N);

        for (int i = 0, u, v; i < N - 1; ++i) {
            scanf("%d %d", &u, &v);
            --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs (0, -1);

        printf("Case #%d: %d\n", cc, solve (0, -1));

        for (int i = 0; i < N; ++i) g[i].clear();


    }







    return 0;
}
