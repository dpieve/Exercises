//http://codeforces.com/contest/66/problem/B

#include <bits/stdc++.h>

using namespace std;

int main(){


    //freopen("input.txt", "r", stdin);
    
    int n, a[1005];
    
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int max_curr, ans = 0;

    for(int i = 0; i< n; i++){
        max_curr = 1;
        for(int j = i+1; j < n; j++){
            if(a[j-1] >= a[j] && (j-1 >= 0) && (j < n))
                max_curr++;
            else break;
        }

        for(int j = i-1; j >= 0; j--){
            if(a[j+1] >= a[j] && j >= 0)
                max_curr++;
            else break;
        }

        ans = max(ans, max_curr);

    }
    printf("%d\n", ans);

    return 0;
}
