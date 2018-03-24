//http://codeforces.com/contest/782/problem/A

#include <bits/stdc++.h>

using namespace std;

int main(){


    int n, socks, size = 0;
    cin >> n;

    set<int> table;

    for( int i = 1; i <= 2*n; i++ ){
        cin >> socks;

        if(table.count( socks ) != 0)
        {
            size = max(size, (int)table.size());
            table.erase( socks );
        }
        else table.insert(socks);  
    }

    cout << size << endl;

    return 0;
}
