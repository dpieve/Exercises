
#include <bits/stdc++.h>
using namespace std;

#define LOG 25
#define MAX 212345
#define pb push_back
#define ll long long

typedef pair<int,int> ii;

set< ii > used;
vector< pair< int, ii > > g1, g2;

int p[MAX], sz[MAX];

int find(int x){ return ( p[x] == x ? x : (p[x] = find(p[x])) ); }

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
        if(sz[x] < sz[y]) swap(x, y);    
        sz[x] += sz[y];
        p[y] = x;
    }
}

vector< ii > g[MAX];
int nvl[MAX], memo[MAX][LOG], dist[MAX][LOG];

void dfs(int u){
    for(int j = 0; j < g[u].size(); j++){
        int v = g[u][j].first;
        int w = g[u][j].second;

        if(nvl[v] != -1) continue;

        dist[v][0] = w;
        memo[v][0] = u;
        nvl[v] = nvl[u] + 1;

        dfs(v);        
    }
}

inline void build(const int& n){

    memset(nvl, -1, sizeof nvl);
    memset(memo, -1, sizeof memo);

    nvl[1] = 0; 
    dfs(1);

    for(int j = 1; j < LOG; j++){
        for(int i = 1; i <= n; i++){
            if(memo[i][j - 1] != -1){
                memo[i][j] =     memo[ memo[i][j-1] ][j-1];
                dist[i][j] = max(dist[ memo[i][j-1] ][j-1], dist[i][j-1]);
            }
        }
    }
}

int ME(int u, int v){
    if(nvl[u] < nvl[v]) swap(u, v);

    int ans = 0;

    for(int j = LOG - 1; j >= 0; j--){
        if(nvl[u] - (1<<j) >= nvl[v]){
            ans = max(ans, dist[u][j]);
            u = memo[u][j];
        }
    }

    if(u == v) return ans;

    for(int i = LOG - 1; i >= 0; i--){
        if(memo[u][i] != -1 && memo[u][i] != memo[v][i]){
            ans = max(ans, dist[u][i]);
            ans = max(ans, dist[v][i]);

            u = memo[u][i];
            v = memo[v][i];
        }
    }

    return max( ans, max(dist[u][0], dist[v][0]) );
}



int main(){
   
    //init();
 
    memset(nvl, -1, sizeof nvl);
    memset(memo,-1, sizeof memo);

    int n, m, u, v, w;

    cin >> n >> m;

    for(int i = 0; i < MAX-1; i++){ 
        p[i] = i; 
        sz[i] = 1; 
    }

    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        g1.pb({w,{u,v}});
    }

    g2 = g1;
    sort(g2.begin(), g2.end());

    ll cost = 0;

    for(int i = 0; i < m; i++){
        u = g2[i].second.first;
        v = g2[i].second.second;
        w = g2[i].first;

        if(find(u) != find(v)){
            cost += w;
            unite(u, v);
            used.insert({u, v});

            g[u].pb({v, w});
            g[v].pb({u, w});
        }
    }

    build(n);

    for(int i = 0; i < m; i++){
        u = g1[i].second.first;
        v = g1[i].second.second;
        w = g1[i].first;

        if(used.count({u,v}) != 0){
            cout << cost << endl;
        }
        else{
            cout << cost + w - ME(u, v) << endl;
        }
    }


    return 0;
}
