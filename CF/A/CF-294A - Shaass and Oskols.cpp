#include <bits/stdc++.h>
#define MAXN 102

using namespace std;

int main() {
    
    // when shot -> bird right go to i+1 and bird left go to i-1
    // x (wire) and y (bird) 

    int n, m, x, y, bird[MAXN]; 

    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &bird[i]);

    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &x, &y);

        if(x == 1 || x == n)
        {
            if(x == 1)
                bird[x+1] += (bird[x]-y);
            else if(x == n)
                bird[x-1] += (y-1);
        }else
        {
            bird[x+1] += (bird[x]-y);
            bird[x-1] += (y-1);
        }
        bird[x] = 0;
    }
    for(x=1; x<=n; x++)
        printf("%d\n", bird[x]);
    
  return 0;
}
