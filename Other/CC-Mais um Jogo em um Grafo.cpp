//http://www.codcad.com/problem/221
//escolher um conjunto de vértices de forma que a soma de seus pesos seja máxima 
//e que nenhum vértice no conjunto seja vizinho de qualquer outro vértice do conjunto.

#include <bits/stdc++.h>
 
const int maxn = 1e5 + 100; // n <= 100000 
 
int v[maxn]; // ensure v[i] <= 1e4, or else int won't work for dp
int dp[maxn][2]; // dynamic programming answers
 
std::vector<int> G[maxn]; // graph for connections
 
void dfs(int x, int parent) {
    for (int y: G[x]) {
        if (y == parent) continue; 
        dfs(y, x); // dfs all children
    }
 
    int taking_x = v[x], not_taking_x = 0; // two cases for the values
 
    for (int y: G[x]) {
        if (y == parent) continue;
        taking_x += dp[y][true]; 
        not_taking_x += dp[y][false]; 
    }
 
    dp[x][true] = not_taking_x;  // if parent of x is taken, x is not taken
    dp[x][false] = std::max(taking_x, not_taking_x);  //  if parent of x is not taken
}
 
int main() {
    // speed up cin/cout
    std::ios::sync_with_stdio(false); std::cin.tie(0);
 
    /* input start */
 
    int n; std::cin >> n;
 
    for (int i = 1; i < n; i++) {
        int x,y; std::cin >> x >> y;
        G[x].push_back(y); G[y].push_back(x); 
    }

    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
    } 
 
    /* input ends */
 
    dfs(1, -1); 
 
    std::cout << dp[1][false] << std::endl; // 1 never has its "parent" selected.

    return 0;
}
