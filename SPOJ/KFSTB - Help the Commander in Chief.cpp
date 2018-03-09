http://www.spoj.com/problems/KFSTB/

#include <bits/stdc++.h>

#define MAX 100005
#define MOD 1000000007

using namespace std;

vector<int> G[MAX];

int D, C, B, S, T, vis[MAX], path[MAX];

long long DFS(int u){

    long long path_child = 0;

    if(u == T)
        return 1;       //finish

    for(int i=0; i<(int)G[u].size(); i++){
        int v = G[u][i];

        if(!vis[v]){ 
            if(path[v] == 0){    // if not calculated
                vis[v] = 1;
                path_child = DFS(v);
                vis[v] = 0;
            }else{
                path_child = (path[v]%MOD);   // if calculated
            }
            path[u] = ((path[u]%MOD) + (path_child%MOD))%MOD;  // sum prop MOD
        }

    }
    return path[u]; // return num path starting with S to T
}

int main() {

    scanf("%d", &D);

    while(D--){

        //start
        memset(vis,  0, sizeof vis); 
        memset(path, 0, sizeof path);

        for(int i=0; i<=C; i++)
            G[i].clear();

        scanf("%d %d %d %d", &C, &B, &S, &T);

        int u, v;
        for(int i=0; i<B; i++){
            scanf("%d %d", &u, &v);

            G[u].push_back(v);
        }
 
        if(S == T)               // (x --> x) == 1 way
            printf("1\n");
        else{
            vis[S] = 1;      
            printf("%lld\n", DFS(S)); 
        } 
    }

  return 0;
}
