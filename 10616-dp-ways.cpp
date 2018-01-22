#include <bits/stdc++.h>

using namespace std;

//N numbers, choose M of them. How many have a sum divisible by D?

int N,M,Q,D;
int number[205],memo[205][205][15];

int ways(int n,int sum,int m){
  if(m==M && sum==0)
    return 1;
  if((m==M && sum!=0) || (n==N))
    return 0;
  if(memo[n][sum][m]!=-1)
    return memo[n][sum][m];

  //ans = ways without add the number + ways with the number
  return memo[n][sum][m] = ways(n+1,sum%D,m)+ways(n+1,(sum+number[n])%D,m+1);
}
int main() {
   
  int cases=0;
  while(scanf("%d %d",&N,&Q),N,Q){
    for(int i = 0; i < N; i++){
      scanf("%d",&number[i]);
    }
    printf("SET %d:\n",++cases);
    for(int i = 0; i < Q; i++){
      scanf("%d %d",&D,&M);
      memset(memo,-1,sizeof memo);
      printf("QUERY %d: %d\n",i+1,ways(0,0,0));
    }
  }
  return 0;
}
