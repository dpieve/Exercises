//https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=&problem=3666&mosmsg=Submission+received+with+ID+21056880

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    while(n--){
        
        int b;
        scanf("%d", &b);

        int v[ 10 ];
        for(int i = 0; i < 10; i++)
            v[i] = 0;


        for(int i = 0; i <= b; i++){
            int tmp = i;
            while( tmp != 0 ){
                v[ tmp%10 ]++;
                tmp /= 10;
            }
        }

        for(int i = 0; i < 9; i++)
            printf("%d ", v[i]);
        printf("%d\n", v[9]);
    }

    return 0;
}
