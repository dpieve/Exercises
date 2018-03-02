#include <bits/stdc++.h>

using namespace std;

bool is_odd(int x){
  return ( (x % 2 == 0)?(false):(true) );
}

int main() {

  int n;
  cin >> n;

  vector<int> odd, even;

  while(n--){
    int x;
    cin >> x;

    if(is_odd(x))
      odd.push_back(x);
    else even.push_back(x);

  }  
  
  sort(even.begin(), even.end());  
  sort( odd.begin(), odd.end() );

  reverse(odd.begin(), odd.end());

  for(int i=0; i<(int)even.size(); i++)
    cout << even[i]<< endl;

  for(int i=0; i<(int)odd.size(); i++)
    cout << odd[i]<< endl;

  return 0;
}
