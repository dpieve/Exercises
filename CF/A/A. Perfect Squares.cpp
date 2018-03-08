//http://codeforces.com/contest/914/problem/A

#include <bits/stdc++.h>

using namespace std;

bool is_not_perfect(int x){
    int tmp = sqrt(x);

    if(tmp*tmp == x)
        return false;

    return true;
}

int main() {
   
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    sort(a, a+n); 

    for(int i=n-1; i>=0; i--){
        if(is_not_perfect( a[i] )){
            printf("%d\n", a[i]);
            break;
        }
    }

  return 0;
}
