//http://codeforces.com/contest/621/problem/A

// HINT: ODD - ODD = EVEN

// max_sum = sum of all numbers - small odd number (if sum of all is odd) 

#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
   
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    ll sum = 0, small = 1000000000;
    while(n--){
        
        ll x;
        cin >> x;

        sum += x;

        if(x&1 && x < small)
            small = x;

    }

    if(sum % 2 != 0)
        cout << sum-small << endl;
    else cout << sum << endl;


  return 0;
}
