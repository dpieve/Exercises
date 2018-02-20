
//http://codeforces.com/contest/770/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int n, k, f;
    scanf("%d %d", &n, &k);
    

    f = k-1;
    string rsp;

    while(n--){
        rsp += (f + 'a');
        f--;

        if(f < 0)
            f = k-1;
    }
    cout << rsp << endl;


  return 0;
}
