//https://www.codechef.com/problems/HORSES

#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);

    int t, n;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        ll v[5010];
        for(int i=0; i<n; i++)
            scanf("%lld", &v[i]);

        sort(v, v+n);
        ll min_dif = abs(v[1]-v[0]);
    
        for(int i=2; i<n; i++)
            min_dif = min(min_dif, v[i]-v[i-1]);

        printf("%lld\n", min_dif);
    }

  return 0;
}
