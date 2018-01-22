#include<bits/stdc++.h>

using namespace std;

int main(){

  int i,j,n,T;
  int s[1010];

  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    int sum=0;
    for(i=0;i<n;i++){
      scanf("%d",&s[i]);
      if(i>0)
        for(j=0;j<i;j++)
          if(s[j]<=s[i])
            sum++;
    }
    printf("%d\n",sum);
  }
  return 0;
}

