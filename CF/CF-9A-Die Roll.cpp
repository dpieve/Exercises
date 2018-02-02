#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int y, w, d=0, total=6;
    scanf("%d %d", &y, &w);
   
    for(int i=1; i<=total; i++)
        if(i>=y && i>=w)
            d++;

    while(d%2==0 && total%2==0){
        d = d/2;
        total = total/2;
    }
    while(d%3==0 && total%3==0){
        d = d/3;
        total = total/3;
    }
    printf("%d/%d\n", d, total);
    
  return 0;
}
