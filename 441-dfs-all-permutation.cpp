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
/* iterative way
#include<bits/stdc++.h>

using namespace std;

int main(){

  freopen("input.txt","r",stdin);

  int k,loto[14];
  while(scanf("%d",&k), k){
    for(int i=0;i<k;i++)
      scanf("%d",&loto[i]);

    for(int i=0;i<k;i++)
      for(int i2=i+1;i2<k;i2++)
        for(int i3=i2+1;i3<k;i3++)
          for(int i4=i3+1;i4<k;i4++)
            for(int i5=i4+1;i5<k;i5++)
              for(int i6=i5+1;i6<k;i6++){
                printf("%d %d %d %d %d %d\n",loto[i],loto[i2],loto[i3],loto[i4],loto[i5],loto[i6]);
              }

    printf("\n");
  }

  return 0;
}
*/
