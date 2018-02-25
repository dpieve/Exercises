//codeforces.com/contest/80/problem/A
#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x){
  if(x == 2)
    return true;
  if((x % 2) == 0 || (x<=1))
    return false;

  for(int i=3; i*i<= x; i+=2)
    if(x%i == 0)
      return false;

  return true;
}

int main(){
 
  int n, m;
  cin >> n >> m;

  int ans = 0;
  for(int i=n+1; i<60; i++){
    if(is_prime(i)){
      if(i == m){
        ans = 1; 
        break;
      }else break;
    }
  }
  if(ans == 1) printf("YES\n");
  else printf("NO\n");

  return 0;
}
