#include <bits/stdc++.h>
//exercice 11723
using namespace std;


int main(){

    int R,N,ans,i,c=0;
    bool ok;
    while(scanf("%d %d",&R,&N) == 2){
        if(!R && !N) break;
        ok=false;
        for (i = 1; i <= 27; i++){
            if(R <= N*i){
                ok=true;
                ans = i-1;
                break;
            }
        }
        if(ok) printf("Case %d: %d\n",++c,ans);
        else   printf("Case %d: impossible\n",++c);
    }
    return 0;
}
