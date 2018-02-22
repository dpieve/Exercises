//FIBONACCI PROBLEM

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
      
    int t, n;
    scanf("%d", &t);

    ll f[55];
    f[0] = 1; f[1] = 2;

    for(int i=2; i<=51; i++)
        f[i] = f[i-1] + f[i-2];

    for(int c=1; c<=t; c++){
        scanf("%d", &n);

        printf("Scenario #%d:\n", c);

        if(n==0)
            printf("0\n");
        else cout << f[n] << endl;

        printf("\n");
    }

  return 0;
}
