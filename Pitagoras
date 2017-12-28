#include <bits/stdc++.h>

using namespace std;

//encontrar velocidade necessária - encontrar tempos - determinar diferença - 10773
int main(){

    int c,n;
    double d,v,u,t1,t2,p;
    scanf("%d",&n);

    for (int c = 1; c <= n; c++){
        scanf("%lf %lf %lf",&d,&v,&u);
        if(v<=0 || u<=0 || u==v){
            printf("Case %d: can't determine\n",c);
        }
        else{
            t1 = d/u;
            t2 = d/sqrt(u*u-v*v);
            p  = abs(t1-t2);
            printf("Case %d: %.3lf\n",c,p);
        }
    }
    return 0;
}
