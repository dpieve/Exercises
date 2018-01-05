#include<bits/stdc++.h>

using namespace std;

int main(){

  int i,j,F,R;
  double d[10002],aux,ans;

  while(scanf("%d",&F),F){
      scanf("%d",&R);
      int m[103],n[103];
      for(i=0;i<F;i++) scanf("%d",&m[i]);
      for(j=0;j<R;j++) scanf("%d",&n[j]);

      int pos = 0;
      for(i=0;i<R;i++){
        for(j=0;j<F;j++){
          d[pos] = (double) n[i] / (double) m[j];
          pos++;
        }
      }
      ans = -2;
      sort(d,d+pos);
      for(i=0;i<pos-1;i++)
        ans = max(ans,d[i+1]/d[i]);

      printf("%.2lf\n",ans);
  }
  return 0;
}
