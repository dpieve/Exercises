//https://www.codechef.com/problems/NDIFFPAL

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, t;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        int c = 0;    
        char s[5] = "abcd";

        if( n%2 == 0 ){
            while(n--){
                printf("%c", s[c++]);

                if(c >= 4) c = 0;
            }
            printf("\n");
        }else{
            while(n--){
                printf("%c", s[c++]);

                if(c >= 3) c = 0;
            }
            printf("\n");
        }
    }


  return 0;
}
