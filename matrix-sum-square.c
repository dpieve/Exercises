#include <stdio.h>

//sum of all the numbers in the rectangle (1,1) to X,Y.
//sum = elem + previous - intersection(commun between previous). 
//S(x,y) = a(x,y) + S(x-1,y) + S(x,y-1) - S(x-1,y-1);

int main(){

  int lin,col,q,x,y,i,j;
  scanf("%d %d",&lin,&col);

  int m[lin+2][col+2];

  for(i=0;i<=lin;i++)
    m[i][0]=0;
  for(i=0;i<=col;i++)
    m[0][i]=0;

  for(i=1;i<=lin;i++)
    for(j=1;j<=col;j++){
      scanf("%d",&x);
      m[i][j] = (m[i][j-1] + m[i-1][j] - m[i-1][j-1]) + x;
    }

  scanf("%d",&q);
  while(q--){
    scanf("%d %d",&x,&y);
    printf("%d\n",m[x][y]);
  }
  
  return 0;
}
