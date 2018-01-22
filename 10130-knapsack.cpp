#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int people;
int memo[3050][1005];
int price[1005],weight[1005];

int knapsack(int W,int n){
  if(memo[W][n] != -1)
    return memo[W][n];
  if(n<0 || W<0)
    return -100000;
  if(n == 0 || W == 0)
    return 0;
  
  if(weight[n-1] > W)
    return    memo[W][n] =      knapsack(W,n-1);
  else return memo[W][n] = max( knapsack(W,n-1), price[n-1]+knapsack(W-weight[n-1],n-1) );
}
int main(){

  freopen("input.txt","r",stdin);

  int N,G,cases,i;
  scanf("%d",&cases);
  while(cases--){
      scanf("%d",&N);
      for(i=0;i<N;i++)
        scanf("%d %d",&price[i],&weight[i]);

      int total=0;
      memset(memo,-1,sizeof memo);

      scanf("%d",&G);
      for(i=0;i<G;i++){
        scanf("%d",&people);
        total+=knapsack(people,N);
      }
      printf("%d\n",total);
  }

  return 0;
}
