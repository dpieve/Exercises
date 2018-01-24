#include <bits/stdc++.h>

using namespace std;

int main() {
   
  int v,i,j,a[10]={};
  scanf("%d",&v);

  int mn=100005,qtd=0,dig;
  for(i=1;i<10;i++){
    scanf("%d",&a[i]);
    if(a[i] <= mn){
      mn=a[i];
      dig=i;
    }
  }
  qtd = v / mn;
  if(qtd==0) 
    printf("-1\n");
  else{
    string x = "";
    v-=(mn*qtd);
    for(i=1;i<10;i++)
      a[i]-=mn;

    for(i=0;i<qtd;i++){
      int max_dig=dig;
      for(j=1;j<10;j++){
        if(v==0) break;
        if(j>max_dig && v>=a[j])
          max_dig=j;
      }
      v-=a[max_dig];
      x+=(max_dig+'0');
    }
    cout << x << endl;
  }
  return 0;
}
