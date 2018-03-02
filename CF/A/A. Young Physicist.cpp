//http://codeforces.com/contest/69/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int n, x, y, z;
    scanf("%d", &n);

    int s_z, s_y, s_x;
    s_z = s_y = s_x = 0;

    while(n--){
        scanf("%d %d %d", &x, &y, &z);

        s_x += x; s_y += y; s_z += z;
    }
    if(s_x == 0 && s_y == 0 && s_z == 0)
        printf("YES\n");
    else printf("NO\n");
  return 0;
}
