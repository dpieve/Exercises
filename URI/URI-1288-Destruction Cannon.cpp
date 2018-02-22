#include <bits/stdc++.h>

#define MAXN 55

using namespace std;

int N, P[MAXN], W[MAXN], dp[MAXN][105];

int mission(int idx, int hold){

    if(dp[idx][hold] != -1)
        return dp[idx][hold];

    if(idx ==  N || !hold)
        return dp[idx][hold] = 0;

    int out = mission(idx+1, hold);

    if(W[idx] <= hold){
        int in = P[idx] + mission(idx+1, hold - W[idx]);

        return dp[idx][hold] = max(in, out);
    }

    return dp[idx][hold] = out;

}


int main() {
   
    //freopen("input.txt", "r", stdin);

    int T, K, R;

    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        
        for(int i=0; i<N; i++)
            scanf("%d %d", &P[i], &W[i]);

        scanf("%d", &K);
        scanf("%d", &R);
    
        memset(dp, -1, sizeof dp);

        int destruction = mission(0, K);  

        if(destruction >= R)
            printf("Missao completada com sucesso\n");
        else printf("Falha na missao\n");
    }

  return 0;
}
