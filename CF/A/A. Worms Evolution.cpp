//http://codeforces.com/problemset/problem/31/A

#include <bits/stdc++.h>

using namespace std;

int main() {
 
  int n, a[150];
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%d", &a[i]);

  int x=-1, y, z;
  for(int i=1; i<=n && (x==-1); i++){
  for(int j=1; j<=n && (x==-1); j++){
    if( i != j )
    for(int k=j+1; k<=n; k++)
      if( (a[i] == a[k] + a[j])  && (k != i)){
        x = i; y = j; z = k;
      }
    }
  }

  if(x != -1)
    printf("%d %d %d\n", x, y, z);
  else printf("%d\n", x);

  return 0;
}
