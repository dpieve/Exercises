//https://www.urionlinejudge.com.br/judge/en/problems/view/1310

#include <bits/stdc++.h>

using namespace std;

int main() {
   
    //freopen("input.txt", "r", stdin);

    int n, perDayCost;

    while(scanf("%d", &n) != EOF){
        scanf("%d", &perDayCost);

        int x;
        vector< int > revenue;
        for(int i=0; i<n; i++){
            scanf("%d", &x);
            x = x - perDayCost;
            revenue.push_back(x);
        }

        int ans = 0, sum = 0;
        
        for(int i=0; i<n; i++){
            sum += revenue[i];
            
            if(sum < 0)
                sum = 0;
            else if(ans < sum)
                ans = sum;
        }

        if(ans<=0) printf("0\n");
        else printf("%d\n", ans);

    }
  return 0;
}
