#include <bits/stdc++.h>

using namespace std;

int main(){
  
  //freopen("input.txt","r",stdin);

  int n, x, yes, solved;
  
  while(scanf("%d", &n) != EOF){

  solved=0;
  for(int i=0;i<n;i++){
    yes=0;
    for(int j=0;j<3;j++){
      scanf("%d", &x);

      if(x == 1) yes++;
    }
    if(yes >= 2) solved++;
  }
  printf("%d\n",solved);

  }

  return 0;
}
