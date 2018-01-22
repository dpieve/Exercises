#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef long long ll;

bool prime(int number){
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;
}
int main(){

  //freopen("input.txt","r",stdin);

  ll n;
  while(scanf("%lld",&n),n){
    ll n1,n2;
    if(n%2 == 0){
      for(ll x=2;x<=n;x++){
        if(prime(x) && prime(n-x)){
          n2 = n-x;
          n1 = x;
          break;
        }
      }
      printf("%lld = %lld + %lld\n",n,n1,n2);
    }else{
      printf("Goldbach's conjecture is wrong.\n");
    }
  }

  return 0;
}
