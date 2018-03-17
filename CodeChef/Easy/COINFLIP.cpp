//https://www.codechef.com/problems/CONFLIP


#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
 
    //freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--){
        int G;
        scanf("%d", &G);

        while(G--){
            int I, Q; ll N;
            scanf("%d %lld %d", &I, &N, &Q);

            if(I == 1){         
                if(N & 1){
                    if(Q == 1)  
                        printf("%lld\n", N/2);
                    else printf("%lld\n", N/2 +1);
                }else{
                    printf("%lld\n", N/2); 
                }
            }else{
                if(N & 1){
                    if(Q == 1)
                        printf("%lld\n", N/2 +1);
                    else printf("%lld\n", N/2);
                }else{
                    printf("%lld\n", N/2);
                }
            }

        }
    }


  return 0;
}
