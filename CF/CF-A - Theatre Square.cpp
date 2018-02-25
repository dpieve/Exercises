//codeforces.com/contest/1/problem/A 
// number of 'a' needed to cover all area 'n*m'

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

int main(){

  ll n, m, a;
  cin >> n >> m >> a;

  cout << ((m+a-1)/a)*((n+a-1)/a);

  return 0;
}
