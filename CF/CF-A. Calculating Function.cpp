//http://codeforces.com/contest/486/problem/A

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool odd(ll x){
  return (x & 1);
}

// PA SUM WITH S1=> r = -2, a = -1;  S2=> r = -2, a = 2;

ll S1(ll n){
  return -(n*n);
}
ll S2(ll n){
  return n*(n+1);
}
int main(){
 
  ll n;
  cin >> n;

  if(odd(n))
  {
    //divide by 2
    n = n >> 1;    
    ll a = S1(n+1);
    ll b = S2(n);

    cout << (a+b) << endl;
  }
  else{
    n = n >> 1;
    ll a = S1(n);
    ll b = S2(n);

    cout << (a+b) << endl;
  }

  return 0;
}
