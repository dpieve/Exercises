// http://codeforces.com/problemset/problem/103/B
// Check a set of three or more rooted trees, whose roots are connected by a simple cycle.

#include <bits/stdc++.h>
#define MAX 10003

using namespace std;

int n, m, t[MAX][MAX], d[MAX];

void DFS(int u){
    d[u] = 1;
    for(int v=1; v<=n; v++)
        if(d[v]==0 && t[u][v]==1)
            DFS(v);
}

bool connected(){
    DFS(1);
    for(int i=1; i<=n; i++)
        if(d[i]==0)
            return false;

    return true;
}

int main(){

    //freopen("input.txt","r",stdin);

    scanf("%d %d", &n, &m);

    for(int i=0; i<=n; i++){
        d[i]=0;
        for(int j=0; j<=n; j++)
            t[i][j]=0;
    }

    int u, v;
    for(int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        t[u][v] = 1; t[v][u] = 1;
    }

    if(!connected())
         printf("NO\n");
    else printf("FHTAGN!\n");


    return 0;
}
