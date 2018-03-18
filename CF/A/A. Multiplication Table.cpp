//http://codeforces.com/contest/577/problem/A
#include <bits/stdc++.h>

#define LL long long int

using namespace std;

int main() {
 

    int n; LL x;
    cin >> n >> x;

    int found = 0;
    for(int j = 1; j <= n; j++ ){
        if(x % j == 0 && x / j <= n)
            found++;
    }
    cout << found << endl;


  return 0;
}
