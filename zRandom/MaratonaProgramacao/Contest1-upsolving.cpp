#include <bits/stdc++.h>

using namespace std;

bool solve(int x){

  set<int> dig;
  while(x != 0){
    if(dig.count( (x%10) ) != 0)
      return false;
    dig.insert(x%10);
    x = x/10;
  }

  return true;

}

int main() {
   
  int n;
  cin >> n;

  while(n--){
    int a, b;
    cin >> a >> b;

    int ans = 0;
    for(int i=a; i<=b; i++)
      if(solve(i))
        ++ans;

    cout << ans << endl;
  }


  return 0;
} 
