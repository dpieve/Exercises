#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;



int main(){

    //freopen("input.txt","r",stdin);

    int tc,n;
    scanf("%d",&tc);
    for(int cases=1;cases<=tc;cases++){
        scanf("%d",&n);
        
        long long coin[1001], dp[1001];
        for(int i=0;i<n;i++)
            scanf("%lld",&coin[i]);

        dp[0] = coin[0];
        dp[1] = max(dp[0],coin[1]);
        for(int i=2;i<n;i++)
            dp[i] = max(dp[i-1],coin[i]+dp[i-2]);

        printf("Case %d: %lld\n",cases,dp[n-1]);
    }

  return 0;
}
