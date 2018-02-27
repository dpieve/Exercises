//http://codeforces.com/contest/225/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
  
  int n;
  scanf("%d", &n);

  int x;
  scanf("%d", &x);  

  int a, b, ans = 1;
  for(int i=0; i<n; i++){
    scanf("%d %d", &a, &b);

    if((a == (7-x) || a == x) || (b == (7-x) || (b == x)))
      ans = 0;
  }

  if(ans == 0) printf("NO\n");
  else printf("YES\n");

  return 0;
}
