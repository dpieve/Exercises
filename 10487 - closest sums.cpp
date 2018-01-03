#include<bits/stdc++.h>

using namespace std;

int main(){

  bool flag;
  int cnt=0,v,n,q,i,j,sum,ask,ans,a[1002];
  while(scanf("%d",&n)==1){
    if(!n) break;
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);

    sort(a,a+n);
    printf("Case %d:\n",++cnt);
    scanf("%d",&q);
    for(ask=0;ask<q;ask++){
      scanf("%d",&v);
      flag=false;
      ans =-15000;
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          if(i!=j){
            sum = a[i]+a[j];
            if(sum == v){
              ans = sum;
              flag= true;
              break;
            }
            if(abs(v-sum)<abs(v-ans))
              ans=sum;
          } 
        }
       if(flag) break;
      }
      printf("Closest sum to %d is %d.\n",v,ans);
    }

  }
  return 0;
}
