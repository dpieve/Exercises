#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;

    cin >> n >> t;
    
    //We need at least 2 digits to make a number divisible by 10;
    //Number is divisible by 10 if last digit = '0';

    if(t == 10)
    {
        if(n == 1) 
            printf("-1\n");
        else{
            for(int i=1; i<=n-1; i++)
                printf("1"); 
            printf("0\n");  
        } 
    }
    else
    {
        // Sure, ttttt...tn is divible by t;
        for(int i=1; i<=n; i++)
            printf("%d", t);
        printf("\n");
    }  

  return 0;
}
