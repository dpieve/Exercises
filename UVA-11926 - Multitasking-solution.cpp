#include <bits/stdc++.h>

using namespace std;

bitset<1000000> activate;

int main(){

    int n,m,i,j,a,b,c;

    while(scanf("%d %d",&n,&m) == 2){
        if(!n && !m)
            break;
        int flag=0;
        
        for(i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            for(j=a;j<b;j++){
                if(activate[j]){
                    flag = 1;
                }
                activate[j]=1;
            }
        }
        for(i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&c);
            if(!flag){
                while(a<1000000){
                    for(j=a;j<b && j<1000000;j++){
                        if(activate[j]){
                            flag = 1;
                        }
                        activate[j]=1;
                    }
                    a+=c; b+=c;
                    if(flag) break;
                }
            }
        }
        puts(flag ? "CONFLICT" : "NO CONFLICT");
        activate.reset();
    }
    return 0;
}