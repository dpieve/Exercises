#include <bits/stdc++.h>
#define MAXV 302

using namespace std;

int V, G[MAXV][MAXV];

bool isBipartite(int s){
    int color[V +1];
    memset(color, -1, sizeof color);

    queue<int> q;
    q.push(s); color[s] = 1;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v=1; v<=V; v++){
            if(G[u][v] == 1){
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                }else if(color[v] == color[u])
                    return false;
            }
        }
    }

    return true;
}

int main(){
    
    while(scanf("%d", &V), V){
        memset(G, 0, sizeof G);
        
        int x, y;
        while(scanf("%d %d", &x, &y), x, y){
            G[x][y] = 1;
            G[y][x] = 1;
        }

        isBipartite(1) ? cout << "YES" : cout << "NO"; 
        printf("\n");
    }

    return 0;
}
