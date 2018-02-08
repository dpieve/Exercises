//http://www.codcad.com/problem/119
#include <bits/stdc++.h>

using namespace std;

bool amizade[1001][1001], vis[1001];

void DFS(int u, int n){
    vis[u] = true;
    for(int v=1; v<=n; v++)
        if(amizade[u][v] && !vis[v])
            DFS(v, n);   
}

int main(){
    
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    memset(vis, false, sizeof vis);
    memset(amizade, false, sizeof amizade);

    for(int i=1; i<=m; i++){
        scanf("%d %d", &u, &v);
        amizade[u][v] = amizade[v][u] = true;
    }

    int times=0;
    for(int j=1; j<=n; j++){
        if(!vis[j]){
            DFS(j, n);
            times++;
        }
    }
    printf("%d\n", times);
    return 0;
}
