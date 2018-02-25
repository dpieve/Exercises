#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
   
    int n; 

    string op;
    ll x, d, distress=0;

    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> op >> d;

        if(op == "-"){
            if(x < d) distress++;
            else x -= d;
        }else    x += d;

    }
    cout << x << " " << distress << endl;

  return 0;
}
