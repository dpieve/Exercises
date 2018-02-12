//https://www.urionlinejudge.com.br/judge/en/problems/view/1212
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){

    ll a, b;
    while( (cin >> a >> b) && (a+b) ){

        int c=0, ans=0;
        while(a>0 || b>0){
            ans += c;
            int x = a%10;
            int y = b%10;

            c = (x+y+c)/10;
            a /= 10; b /= 10;
        }
        ans += c;

             if(ans==0) printf("No carry operation.\n");
        else if(ans==1) printf("%d carry operation.\n", ans);
        else            printf("%d carry operations.\n", ans);
    }
    return 0;
}
