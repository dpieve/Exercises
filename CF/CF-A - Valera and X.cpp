//http://codeforces.com/contest/404/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
  
  //freopen("input.txt", "r", stdin);

  string paper[305];

  int n;
  scanf("%d", &n); n--;

  for(int i=0; i<=n; i++)
    cin >> paper[i];

  bool check = true;
  char begin = paper[0][0];
  
  set < char > letters;
  
  for(int i=0; i<=n; i++){
    for(int j=0; j<=n; j++){

      char x = paper[i][j];
      letters.insert(x);

      if(letters.size() > 2)
        check = false;
      
      else if((i == j) && (x != begin))
        check = false;

      else if( ((i+j) == n) && (x != begin) )
        check = false; 
    
      else if( (i!=j) && (i+j!=n) && (x == begin))
        check = false;

      if(!check) break;
    }
    if(!check) break;
  }  
  if(check && letters.size() == 2) printf("YES\n");
  else printf("NO\n");

  return 0;
}
