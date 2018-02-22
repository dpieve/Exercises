#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f_exp(ll x, ll y, ll n){
    
    if(y == 0) return 1;
    if(x == 1 || y == 1) return x;

    ll resp = f_exp(x, y/2, n);
    resp *= resp;

    if(y%2==1) resp *= x;
    return (resp%n);
}
int main() {
    

    int c, x, y, n;
    while(scanf("%d", &c), c){    
        while(c--){
            scanf("%d %d %d", &x, &y, &n);
            cout << (f_exp(x, y, n))%n << endl;
        }
    }
  return 0;
}
