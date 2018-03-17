//http://codeforces.com/contest/158/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
   
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;

    int a[ n + 1 ], v = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];

        if(i == k-1)
            v = a[i];
    }

    sort(a, a+n);

    int count = 0;
    for(int i=0; i<n; i++)
        if(a[i] >= v && a[i] != 0)
            count++;

    cout << count << endl;

  return 0;
}
