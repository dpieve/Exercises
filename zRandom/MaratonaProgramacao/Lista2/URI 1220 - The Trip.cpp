//https://www.urionlinejudge.com.br/judge/en/problems/view/1220

#include <bits/stdc++.h>

using namespace std;

int main(){

    //freopen("input.txt", "r", stdin);

    int n;
    
    while(scanf("%d", &n), n){

        double total = 0;
        int a[n+1], x, y;

        for(int i = 0; i < n; i++){
            scanf("%d.%d", &x, &y);
            
            //precision
            a[i] = x*100 + y;

            total += a[i];
        }

        total = ((double)total)/n;   // how much each person should to pay

        double maior = 0, menor = 0;

        
        // find sum high diff to equalize the numbers
        for(int i = 0; i < n; i++){
            
            if(a[i] < total){
                menor += ((int)(total - a[i]))/100.0;   
            }
            else{
                maior += ((int)(a[i] - total))/100.0;
            }   
        }

        maior = max( maior, menor );
        printf("$%.2lf\n", maior);

    }

    return 0;
}
