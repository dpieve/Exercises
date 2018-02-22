#include <bits/stdc++.h>

using namespace std;

int n, power[52], weight[52], dp[52][102];

int mission(int bullet, int carry){
    //calculated
    if(dp[bullet][carry] != -1)
        return dp[bullet][carry];

    //limits
    if(bullet == n || carry <= 0)
        return 0;

    //max carry or not
    if(weight[bullet] <= carry)
        return dp[bullet][carry] = max( mission(bullet+1, carry), power[bullet] + mission(bullet+1, carry - weight[bullet]));

    //not hold
    return dp[bullet][carry] = mission(bullet+1, carry);

}

int main() {
   
    int T, K, R;
    scanf("%d", &T);

    while(T--){
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d %d", &power[i], &weight[i]);

        scanf("%d", &K);
        scanf("%d", &R);

        memset(dp, -1, sizeof dp);

        // if sum POWER >= Resistence (R) then Mission's ok, else it's not
        if(mission(0, K) >= R)
            printf("Missao completada com sucesso\n");

        else printf("Falha na missao\n");

    }
  return 0;
}
