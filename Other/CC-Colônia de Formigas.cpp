//http://www.codcad.com/problem/160
//(Maratona de Programação 2010, Fase 2)
//Menor Ancestral Comum | B

#include <bits/stdc++.h>
#define MAXN 100001

using namespace std;

typedef long long int ll;
typedef pair<int,ll> ii;
typedef vector<ii>  vii;

std::vector< vii > path;
ll L[MAXN]; int P[MAXN];

void DFS(int u){
    for(int i=0; i<(int)path[u].size(); i++)
    {
        ii v = path[u][i];
        if(L[v.first] == -1)
        {
           P[v.first]= u;
           L[v.first]= L[u] + v.second;
           DFS(v.first);
        }
    }
}
int LCA(int a, int b){
    while(a != b){
        if(L[a] > L[b])
             a = P[a];
        else b = P[b];
    }
    return a;
}
void initialize(int n){
    path.assign(n+1, vii());
    for(int i=0; i<=n; i++)
        P[i] = L[i] = -1;

    L[0] = 0;
    return;
}
int main(){

    int n;

    while(scanf("%d", &n), n){
        initialize(n);

        int u, v; ll w;
        for(u=1; u<=(n-1); u++){
            scanf("%d %lld", &v, &w);
            path[u].push_back(ii(v, w));
            path[v].push_back(ii(u, w));
        }
        DFS(0);

        int q, comum;
        scanf("%d", &q);
        scanf("%d %d", &u, &v);

        comum = LCA(u ,v);
        printf("%lld", (L[u]+L[v]) - (2*L[comum]));

        for(int i=1; i<q; i++){
            scanf("%d %d", &u, &v);

            comum = LCA(u ,v);
            printf(" %lld", (L[u]+L[v]) - (2*L[comum]));
        }
        printf("\n");
    }
    return 0;
}
