#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int cases,n;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n);

        if(n == 1)
            printf("0.000\n");
        else{
            int moves_sides  = (n-1)*4;                              // four sides (square)
            int moves_mid    = (n*n) - moves_sides;                  // total moves (n^2)
            double legth_path= moves_sides + moves_mid*(sqrt(2));    // (1^2)+(1^2) = mid^2

            printf("%.3f\n",legth_path);
        }

        if(cases) puts("");
    }

    return 0;
}
