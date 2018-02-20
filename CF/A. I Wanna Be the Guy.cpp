//http://codeforces.com/contest/469/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int n, x, p;

    scanf("%d", &n);
   
    int levels[n+1];
    for(int i=0; i<=n; i++)
        levels[i] = 0;

    scanf("%d", &p);
    for(int i=0; i<p; i++){
        scanf("%d", &x);
        levels[x] = 1;
    }
    scanf("%d", &p);
    for(int i=0; i<p; i++){
        scanf("%d", &x);
        levels[x] = 1;
    }
    levels[0] = 1;
    for(int i=1; i<=n; i++)
        if(levels[i] == 0){
            levels[0] = 0;
            break;
        }
    if(levels[0] == 1)
         printf("I become the guy.\n");
    else printf("Oh, my keyboard!\n");

  return 0;
}
