#include <bits/stdc++.h>

using namespace std;

int main() {
 
    int n, t, k, d;
    cin >> n >> t >> k >> d;

    int t1, c1=0;
    for(int i=1; ; i++){
        if(i%t == 0)
            c1 += k;

        if(c1 >= n){
            t1 = i;
            break;
        }
    }  

    int t2, c2=0;
    for(int i=1; ; i++){
        if(i%t==0)
            c2 += k;
        
        if(i>=(d+t) && ((i-d)%t == 0))
            c2 += k;

        if(c2 >= n){
            t2=i;
            break;
        }
    }
    cout << (t2 < t1 ? "YES":"NO") << endl;
  return 0;
}
