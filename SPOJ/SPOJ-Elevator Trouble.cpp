//ELEVTRBL - Elevator Trouble

#include <stdio.h>
#include <cstdio>

using namespace std;


int main(){
    
    //freopen("input.txt","r",stdin);

    long long f,s,g,u,d,cnt=0,curr;
    scanf("%lld %lld %lld %lld %lld",&f,&s,&g,&u,&d);

    curr = s;
    while(curr != g){
        if(curr < g) curr+=u; 
        else         curr-=d;
        cnt++;

        if(cnt >= 1000000)
            break;
    }
    if(curr == g) printf("%lld\n",cnt);
    else         printf("use the stairs\n");

    return 0;
}
