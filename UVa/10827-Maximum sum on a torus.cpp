//Determine the sub-rectangle with the largest sum. 
//The sum of a sub-rectangle is
//the sum of all the elements in that rectangle

// More than one retangle to make the greater sum
// Kadene's Algorithm - DP

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, cases;
    scanf("%d", &cases);

    int m[300][300];

    while(cases--){

        scanf("%d", &n);

        for(int i=0; i<2*n; i++){
            for(int j=0; j<2*n; j++){
                if(i<n && j<n){
                    scanf("%d", &m[i][j]);

                    m[i +n][j] = m[i][j +n] = m[i +n][j +n] = m[i][j];
                }

                if(i>0)        m[i][j] += m[i-1][j];
                if(j>0)        m[i][j] += m[i][j-1];
                if(i>0 && j>0) m[i][j] -= m[i-1][j-1];
            }
        }
        /*
        printf("\n-------------------------------------------------\n");
        for (int i = 0; i < 2*n; ++i){
            for (int j = 0; j < 2*n; ++j)
                printf("%2d ", m[i][j]);
            printf("\n");
        }
        printf("\n---------------------------------------------------\n");
        */
        int ans = -1000000;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=i; k<i+n; k++){
                    for(int l=j; l<j+n; l++){
                        int cur = m[k][l];
                        if(i>0) cur-=m[i-1][l];
                        if(j>0) cur-=m[k][j-1];
                        if(i>0 && j>0) cur += m[i-1][j-1];
                        
                        ans = max(ans, cur);
                    }
                    
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
