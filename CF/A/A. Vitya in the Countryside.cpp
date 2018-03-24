//http://codeforces.com/problemset/problem/719/A

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, a, p;
    
    cin >> n;
    cin >> a;

    if(n == 1){
        if(a == 15)
            cout << "DOWN" << endl;
        else if(a == 0)
            cout << "UP" << endl;
        else cout << "-1" << endl;
    }
    else{
        for(int i = 1; i < n-1; i++){
            cin >> a;
        }

        cin >> p;

        if(p == 15){
            cout << "DOWN" << endl;
        }else{
            if(p == 0){
                cout << "UP" << endl;
            }
            else if( p > a )
                cout << "UP" << endl;
            else if( p < a )
                cout << "DOWN" << endl;
        }
    }

    

    return 0;
}
