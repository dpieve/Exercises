//http://www.codcad.com/problem/67
//knapsack problem

#include <bits/stdc++.h>
#define MAX 2001

using namespace std;
typedef long long int ll;

int N, P;
ll v[MAX], p[MAX], memo[MAX][MAX];

ll comer(int pedaco, int aguenta){
    if(memo[pedaco][aguenta] != -1)
        return memo[pedaco][aguenta];

    if(pedaco == N || aguenta == 0)
        return 0;

    int nao_come = comer(pedaco+1, aguenta);

    if(p[pedaco] <= aguenta){
        int come = v[pedaco] + comer(pedaco+1, aguenta-p[pedaco]);
        return memo[pedaco][aguenta] = max(come, nao_come);
    } 
    return memo[pedaco][aguenta] = nao_come;
}
int main(){
 
    scanf("%d %d", &P, &N);

    memset(memo, -1, sizeof memo);
    for(int i=0; i<N; i++)
        scanf("%lld %lld", &p[i], &v[i]);
     
    ll ans = comer(0, P);
    cout << ans << endl;

    return 0;
}
