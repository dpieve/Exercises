#include <bits/stdc++.h>

using namespace std;

int main() {
  
  //freopen("input.txt", "r", stdin);
  
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    long x;
    set<long> v;
    for(int i=0; i<n; i++){
      cin >> x;

      v.insert(x); 
    }
    long tmn = (long)v.size();
    cout << (n - tmn) << endl;
  }  

  return 0;
}
