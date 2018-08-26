// https://www.urionlinejudge.com.br/judge/en/problems/view/2532

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 4005;
const int INF  = 0x3f3f3f3f;

int N, P;
int D[MAXN], M[MAXN], m[MAXN][MAXN];

int solve (int i, int hp) {
    if (i >= N || hp <= 0) return ( hp <= 0 ? 0 : (INF) );
    
    if(m[i][hp] != -1) return m[i][hp];
    
    return m[i][hp] = min( M[i] + solve(i + 1, hp - D[i]), solve(i + 1, hp));
}
int main() {

    while ( scanf("%d %d", &N, &P) != EOF ) { 
    
        for (int i = 0; i < N; ++i) 
            scanf("%d %d", &D[i], &M[i]);
    
        memset(m, -1, sizeof m); int r = solve(0, P);
    
        printf("%d\n", (r == INF ? -1 : (r)));
    
    }
    
    return 0;
}
