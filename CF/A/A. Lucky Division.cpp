//http://codeforces.com/problemset/problem/122/A

#include <bits/stdc++.h>

using namespace std;

const int a[] = {4, 7, 44, 47, 74, 77, 444, 447, 477, 474, 744, 747, 774, 777};

bool lucky(int n){
    for(int i=0; i<14; i++)
        if(n % a[i] == 0)
            return true;

    return false;
}


int main() {
   
    int n;
    scanf("%d", &n);
    
    if(lucky(n))
        printf("YES\n");
    else printf("NO\n");

  return 0;
}
