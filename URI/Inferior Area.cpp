#include <bits/stdc++.h>

using namespace std;

int main() {
 
  int i, j;
  double M[13][13], sum=0, v;

  char op[5];
  scanf("%s", op);

  for(i=0; i<12; i++)
    for(j=0; j<12; j++){
      scanf("%lf", &v);

      if(i+j>11 && j<i)
        sum += v;
    }

  if(op[0] == 'M')
    printf("%lf\n", sum/( (144-12-12)/4) );
  else printf("%.1lf\n", sum);

  return 0;
}
