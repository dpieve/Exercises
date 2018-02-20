//pay attention! recursion or while solution 

#include <bits/stdc++.h>

using namespace std;

int problem(int x){
    if( x == 1 )
        return 1;
    if( x%2 == 0 )
         return 1 + problem(x/2);
    else return 1 + problem(3*x + 1);
}

int solved(int a, int b){
    if(a > b)
        swap(a, b);
    int ans = 0;

    while(a <= b){
        ans = max(ans, problem(a));
        a++;
    }
    return ans;
}

int main() {
   
    int i, j;
    while(scanf("%d %d", &i, &j) != EOF){
        int result = solved(i, j);
        printf("%d %d %d\n", i, j, result);
    }
  return 0;
}
