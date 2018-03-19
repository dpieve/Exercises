#include <stdio.h>

using namespace std;

void solve(int n){
    int h[n +5];
    for(int i=0; i<n; i++)
        scanf("%d", &h[i]);

    //because it's a loop
    h[n] = h[0]; h[n+1] = h[1];

    int peaks = 0;

    for(int i=1; i<=n; i++)
        if( (h[i]-h[i-1])*(h[i]-h[i+1]) >0 )
            peaks++;

    printf("%d\n", peaks);

}


int main() {
   
    int n;
    
    while(scanf("%d", &n), n)
        solve(n);    
    

  return 0;
}
