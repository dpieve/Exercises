//http://www.spoj.com/status/ns=21613505
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001
#define ll long long int

int main(){

    int v[9001], n;

    while(scanf("%d", &n)==1 && n>0){

        int sum = 0, ans = 0;

        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]);
        
            sum += v[i];
        }

        if(sum%n)
            printf("-1\n");
        else{
            sum = sum/n;
            for(int i = 0; i < n-1; i++){
                
                int diff = v[i]-sum;
                v[i+1]+=diff;

                diff = abs(diff);
                ans = max(ans, diff);
            }

            printf("%d\n", ans);
        }

    }



   return 0;
}
