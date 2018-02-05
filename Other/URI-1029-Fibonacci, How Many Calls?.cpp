#include <bits/stdc++.h>

using namespace std;

long long int calls;

long long int fib(int x){
    if(x==0) return 0;
    if(x==1) return 1;
        
    calls++;
    return (fib(x-1) + fib(x-2));
}
int main(){
    
    int n, x;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        calls=0;
        scanf("%d", &x);
        printf("fib(%d) = %lld calls = %lld\n", x, 2*calls, fib(x));
    }
    return 0;
}
