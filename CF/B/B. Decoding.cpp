http://codeforces.com/contest/746/problem/B

//include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
   
  int n;
  string encoded;

  cin >> n >> encoded;

  int *idx = new int[n], p = 0;

  if( n%2==0 ){
    for(int i=n-1; i>=1; i-=2)
      idx[p++] = i-1;
    for(int i=2; i<=n; i+=2)
      idx[p++] = i-1;
  }else{
    for(int i=n-1; i>=1; i-=2)
      idx[p++] = i-1;
    for(int i=1; i<=n; i+=2)
      idx[p++] = i-1;
  }

  for(int i=0; i<p; i++){
    cout << encoded[ idx[i] ];
  }
  cout << endl;

  delete[] idx;

  return 0;
}
