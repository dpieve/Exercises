//http://www.codcad.com/problem/221
//escolher um conjunto de vértices de forma que a soma de seus pesos seja máxima 
//e que nenhum vértice no conjunto seja vizinho de qualquer outro vértice do conjunto.

#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 100;

int w[maxn], dp[maxn][2];
std::vector<int> g[maxn];

void dfs(int x, int parent){
    for(int y : g[x])
        if(y != parent) 
            dfs(y, x);
    
    int taking_x     = w[x];
    int not_taking_x = 0;

    for(int y : g[x])
        if(y != parent){
            taking_x     += dp[y][true];
            not_taking_x += dp[y][false];
        }
    dp[x][true] = not_taking_x;
    dp[x][false]= max(taking_x, not_taking_x);

    return;

}
int main(){

    int n, x, y, i;
    scanf("%d", &n);

    for(i=1; i<=n-1; i++){
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(i=1; i<=n; i++)
        scanf("%d", &w[i]);

    dfs(1, -1);
    printf("%d\n", dp[1][false]);

    return 0;
}

