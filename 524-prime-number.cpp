#include <bits/stdc++.h>

//exercice 524
using namespace std;

bool used[20];
int circle[20];
int T=0,n;

bool is_prime(int n){
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(int i=3;i*i<=sqrt(n);i+=2){
        if(n%2==0) return false;
    }
    return true;
}
void search(int m) {
    if(m == n - 1 && is_prime(circle[n - 1] + circle[n])) {
        for(int i = 0; i < n; i++)
            printf(i == n - 1? "%d" : "%d ", circle[i]);
        printf("\n");
        return;
    }
    for(int i = 2; i <= n; i++)
        if(!used[i] && is_prime(circle[m] + i)) {
            used[i] = true;
            circle[m + 1] = i;
            search(m + 1);
            used[i] = false;
        }
}
int main(){

    while(scanf("%d",&n)){
        T++;
        circle[0]=circle[n]=1;
        printf("Case #%d:\n",T);
        search(0);
        printf("\n");
    }
    return 0;
}
