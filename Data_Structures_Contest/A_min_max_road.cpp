#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int LOGN = 21;
const int INF = 0x3f3f3f3f;

vector < pair<int,int> > g[MAXN + 5];

int h[MAXN + 5];
int up[MAXN +5][LOGN + 5];
int mn[MAXN +5][LOGN + 5];
int mx[MAXN +5][LOGN + 5];

void init(){
    for(int i = 0; i <= MAXN; ++i){
        g[i].clear();
        for(int j = 0; j <= LOGN; ++j){
            up[i][j] = -1;
            mn[i][j] = INF;
            mx[i][j] = -INF;
        }
    }
}

void dfs(int u){
    for(pair<int,int> v : g[u]){
        if(up[u][0] == v.first)
            continue;
        h[v.first] = h[u] + 1;
        up[v.first][0] = u;
        mn[v.first][0] = mx[v.first][0] = v.second;
        
        dfs(v.first);    
    }
}

void build(int N){
    for (int j = 1; j < LOGN; ++j){
        for(int i = 1; i <= N; ++i){
            int p = up[i][j-1];
            up[i][j] = up[p][j-1];
            mn[i][j] = min(mn[p][j-1],mn[i][j-1]);
            mx[i][j] = max(mx[p][j-1],mx[i][j-1]);
        }
    }
}

pair<int,int> query(int x, int y){
    
    if(h[x] < h[y]) 
        swap(x,y);
    
    int d = h[x] - h[y];
    int D = INF, U = -INF;
    
    for(int i = LOGN - 1; i >= 0; --i) {
        if (d & (1 << i)){
            U = max(U, mx[x][i]);
            D = min(D, mn[x][i]);
            x = up[x][i];
        }
    }
    
    if(x == y)
        return {D,U};
    
    for(int i = LOGN - 1; i >= 0; --i) {
        if(up[x][i] != up[y][i]) {
        
            U = max(U, mx[x][i]);
            U = max(U, mx[y][i]);
            
            D = min(D, mn[x][i]);
            D = min(D, mn[y][i]);
            
            x = up[x][i];
            y = up[y][i];
        }
    }            
    
    D = min(D, mn[x][0]);
    D = min(D, mn[y][0]);
    
    U = max(U, mx[x][0]);
    U = max(U, mx[y][0]);
    
    return{D, U};
}


void solve(){
   init();

   int N;   
   scanf("%d", &N);
   
   for (int i = 1, u, v, w; i < N; ++i){
       scanf("%d %d %d", &u, &v, &w);
       g[u].push_back({v, w});
       g[v].push_back({u, w});           
   }
   
   dfs(1);
   build(N);
   
   int Q;
   scanf("%d", &Q);
   
   while(Q--){
       int x, y;
       scanf("%d %d", &x, &y);
       pair<int,int> ED = query(x, y);
       printf("%d %d\n", ED.first, ED.second);
   }
   
}

int main(){

    int T;
    scanf("%d", &T);
    
    for (int c = 1; c <= T; ++c) {
        printf("Case %d:\n", c);
        solve();
    }
        
    return 0;
}