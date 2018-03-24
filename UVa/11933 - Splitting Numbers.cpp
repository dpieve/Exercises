//https://uva.onlinejudge.org/external/119/11933.pdf

#include <bits/stdc++.h>

using namespace std;

int main(){

   int n;

    while(scanf("%d", &n), n){

        bool addA = true;
        int  addV = 1, a = 0, b = 0;

        while(n != 0){

            // last digit 1
            if( n & 1 ){
                if(addA)
                    a += addV;   // add value of this digit
                else b += addV;

                addA = !addA;
            }

               n >>= 1;          // go next
            addV <<= 1;          // next value
            
        }
        printf("%d %d\n", a, b);

    }

    return 0;
}
