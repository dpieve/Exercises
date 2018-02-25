//http://codeforces.com/contest/807/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int a, b, n, rated=0, low = 5000;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &a, &b);

        if(a != b) 
            rated = 1; 
        else{
            if(a > low && rated != 1)
                rated = -1;
            if(a < low)
                low = a;
        }
    }

    if(rated == 1) printf("rated\n");
    else if(rated == -1) printf("unrated\n");
    else printf("maybe\n");
  return 0;
}
