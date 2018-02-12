#include <bits/stdc++.h>

using namespace std;

int N, P;
int times[61], pizza[31], memo[61][31]; 

int motoboy(int idx, int hold){
    if(memo[idx][hold] != -1)
        return memo[idx][hold];

    if(idx == N || hold == 0)
        return 0;
    
    int not_take = motoboy(idx+1, hold);

    if(pizza[idx] <= hold){
        int take = times[idx] + motoboy(idx+1, hold-pizza[idx]);
        return max(not_take, take);
    }

    return not_take;

}
int main(){

    while(scanf("%d", &N), N){
        scanf("%d", &P);

        for(int i=0; i<N; i++)
            scanf("%d %d", &times[i], &pizza[i]);

        memset(memo, -1, sizeof memo);

        printf("%d min.\n", motoboy(0, P));
    }
    return 0;
}
