//http://codeforces.com/contest/749/problem/A

#include <iostream>

using namespace std;

int main() {
 
    int n;
    cin >> n;

    cout << n/2 << endl;

    for(int j=0; j<n/2 -1; j++)
        cout << "2 ";
    if(n & 1) cout << "3" << endl;
    else cout << "2" << endl;

  return 0;
}
