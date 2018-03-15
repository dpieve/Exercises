#include <bits/stdc++.h>

using namespace std;

int main() {
   
    //freopen("input.txt", "r", stdin);
    int x, y;
    while(cin >> x >> y){
        int a = x, b = y;

        if(a > b)
            swap(a, b);

        int max_cycle = 0;
        while(a <= b){
            int tmp = a, cycle = 1;
            while(tmp != 1){
                if(tmp % 2 == 0)
                    tmp = tmp/2;
                else tmp = 3*tmp + 1;

                cycle++;
            }
            max_cycle = max(max_cycle, cycle);
            a++;
        }
        cout << x << " " << y << " " << max_cycle << endl;

    }


  return 0;
}
