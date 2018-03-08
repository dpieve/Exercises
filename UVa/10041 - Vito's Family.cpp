https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=982&mosmsg=Submission+received+with+ID+20896350

#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int tc;
    cin >> tc;

    while(tc--){
        int r;
        cin >> r;

        int x;
        vector<int> a;
        for(int i=0; i<r; i++){
            cin >> x;

            a.push_back(x);
        }
        sort(a.begin(), a.end());

        int house = a[ (r-1)/2 ];

        int sum = 0;
        for(int i=0; i < (int)a.size(); i++)
            sum += abs(house - a[i]);
        
        cout << sum << endl;
        
    }

  return 0;
}
