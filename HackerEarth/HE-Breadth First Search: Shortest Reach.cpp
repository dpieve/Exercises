//Breadth First Search: Shortest Reach
//https://www.hackerrank.com/challenges/bfsshortreach/problem

#include <bits/stdc++.h>

using namespace std;

int dist[1010];
std::vector<int> g[1010];

void BFS(int s){
    queue<int> q;
    q.push(s); dist[s]=0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int j=0; j<g[u].size(); j++){
            int v = g[u][j];
            if(dist[v]==0){
                dist[v] = dist[u]+6;
                q.push(v);
            }
        }
    }
}

int main(){

    //freopen("input.txt","r",stdin);
    int tc, n, m, u, v, s;

    scanf("%d", &tc);

    while(tc--){
        scanf("%d %d", &n, &m);

        for(int i=0; i<=n+1; i++){
            dist[i]=0;
            g[i].clear();
        }

        for(int i=0; i<m; i++){
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        scanf("%d", &s);
        BFS(s);

        for(int i=1; i<=n; i++){
            if(i != s){
                if(dist[i] == 0)
                    printf("-1 ");
                else printf("%d ", dist[i]);
            }
        }
        printf("\n");
    }



    return 0;
}
