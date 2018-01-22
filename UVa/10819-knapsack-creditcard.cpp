#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string.h>

using namespace std;

int money,items;
int memo[1500][110];
int price[1000],favour[1000];

int buy(int m,int n){
  if(m > money && money < 1800)
    return -10002;
  if(m > money  + 200)
    return -10002;
  if(n == items){
    if(m > money && m<=2000)
      return -10002;
    return 0;
  }
  if(memo[m][n] != -1)
    return memo[m][n];

  return memo[m][n] = max(buy(m,n+1),favour[n]+buy(m+price[n],n+1));  
}
int main(){

  freopen("input.txt","r",stdin);

  while(scanf("%d %d",&money,&items)==2){
    for(int i=0;i<items;i++)
      scanf("%d %d",&price[i],&favour[i]);
    memset(memo,-1,sizeof memo);
    printf("%d\n",buy(0,0));
  }
  return 0;
}

