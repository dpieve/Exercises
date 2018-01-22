#include <bits/stdc++.h>

using namespace std;

typedef struct{
  int right,left;
}date;

date s[100005];

int main() {
   
  int S,B,L,R;
  while(scanf("%d %d",&S,&B),S || B){
    for(int i=1;i<=S;i++){
      s[i].left = i-1;
      s[i].right= i+1;
    }
    s[S].right=0;
    for(int i=0;i<B;i++){
      scanf("%d %d",&L,&R);
      if(s[L].left){
        printf("%d ",s[L].left);
      }else{
        printf("* ");
      }
      if(s[R].right){
        printf("%d",s[R].right);
      }else{
        printf("*");
      }
      printf("\n");
      s[s[L].left].right = s[R].right;
      s[s[R].right].left = s[L].left;
    }
    printf("-\n");
  }
  return 0;
}
