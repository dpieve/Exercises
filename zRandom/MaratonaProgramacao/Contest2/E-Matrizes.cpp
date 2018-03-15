//multiply AxB = C

#include <bits/stdc++.h>

#define MAXN 100001 

using namespace std;

int main() {
 
    //freopen("input.txt", "r", stdin);

    int n;

    while(cin >> n){
        if(n == 1)
            break;

        int p, q, r, s, x, y, lin, col;

        cin >> p >> q >> r >> s;
        cin >> x >> y >> lin >> col;

        int a[MAXN], b[MAXN];
        
        for(int j=1; j<=n; j++)
            a[j] = (p*lin + q*j)%x;

        for(int i=1; i<=n; i++)
            b[i] = (r*i + s*col)%y;

        int sum = 0;
        for(int i=1; i<=n; i++)
            sum += (a[i]*b[i]);

        printf("%d\n", sum);

    }    


  return 0;
}
