//http://www.codcad.com/problem/68
//Maior subsequencia comum

#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int s1[MAX], s2[MAX], memo[MAX][MAX];

int lsc(int a, int b){

    if(memo[a][b] != -1)
        return memo[a][b];
    if(a == 0 || b == 0)
        return 0;

    if(s1[a] == s2[b])
         return memo[a][b] = 1+lsc(a-1, b-1);

    return memo[a][b] = max(lsc(a-1, b), lsc(a, b-1));
}

int main(){
    
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)
        scanf("%d", &s1[i]);
    for(int i=0; i<m; i++)
        scanf("%d", &s2[i]);

    memset(memo, -1, sizeof memo);

    int igual = lsc(n-1, m-1);
    printf("%d %d\n", n-igual, m-igual);

    return 0;
}
