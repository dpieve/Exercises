//https://www.hackerrank.com/challenges/lonely-integer/problem
//every element in A occurs exactly twice except for one unique element

#include <bits/stdc++.h>

using namespace std;

int main() {
  

  int n;
  cin >> n;

  //    x XOR x = 0;
  // if x XOR x (twice) it's not going to change the previous number

  // 1(0001) XOR (1001)9  = 1000.  1000 XOR (9)1001 = 0001;


  int x, rsp = 0;
  for(int i=0; i<n; i++){
    cin >> x;
    rsp ^= x;
  }  

  cout << rsp << endl;

  return 0;
}
