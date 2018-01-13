#include <bits/stdc++.h>

using namespace std;

int main() {

  int cases,n,i,temp;
  scanf("%d",&cases);

  while(cases--){
    int ans[10];
    for(i=0;i<10;i++) ans[i]=0;

    scanf("%d",&n);
    for(i=1;i<=n;i++){
      temp = i;
      while(temp){
        ans[temp%10]++;
        temp /= 10;
      }
    }
    for(i=0;i<9;i++)
      printf("%d ",ans[i]);
    printf("%d\n",ans[9]);
  }

  return 0;
}
