#include <iostream>
#include <stdio.h>

using namespace std;

int k;
int S[14],ans[6];

void dfs(int idx,int i){
  if(idx == 6){
    printf("%d",ans[0]);
    for(i=1;i<6;i++)
      printf(" %d",ans[i]);
    puts("");
    return;
  }
  for(;i<k;i++){
    ans[idx] = S[i];
    dfs(idx+1,i+1); 
  }
}
int main(){


  //freopen("input.txt","r",stdin);
  
  bool ok = false;
  while(scanf("%d",&k),k){
    if(ok) puts("");
    for(int i=0;i<k;i++)
      scanf("%d",S+i); //another way &S[i]
    dfs(0,0);
    ok=true;
  }
  
  return 0;
}
