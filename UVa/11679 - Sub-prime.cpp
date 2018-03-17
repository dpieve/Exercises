#include <bits/stdc++.h>

using namespace std;

int main() {
   
   // freopen("input.txt", "r", stdin);

    int b, n;
    while(cin >> b >> n, b, n){

        int r[b +5];
        for(int i=0; i<b; i++)
            cin >> r[i];

        int d, c, v;
        for(int j=0; j<n; j++){
            cin >> d >> c >> v;
        
            r[c-1] += v;
            r[d-1] -= v;
        }

        int ans = 1;
        for(int i=0; i<b; i++)
            if(r[i] < 0)
                ans = 0;

        if(ans == 0) cout << "N" << endl; 
        else cout << "S" << endl;

    }

  return 0;
}
