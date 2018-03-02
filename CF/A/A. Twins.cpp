//http://codeforces.com/contest/160/problem/A

#include <bits/stdc++.h>

using namespace std;

bool cmp(const int &a, const int &b){ return (a > b); }

int main() {
    
    int n;
    scanf("%d", &n);

    int a[n], total=0;
    for(int i=0; i<n; i++){
        cin >> a[i];

        total += a[i];
    }

    sort(a, a+n, cmp);  

    int i=0, sum=0, coins=0;
    
    while(sum <= total/2){
        coins++;
        sum += a[i++];
    }
    printf("%d\n", coins);

  return 0;
}
