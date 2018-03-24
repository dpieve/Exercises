//http://codeforces.com/problemset/problem/560/A

#include <iostream>

using namespace std;

int main(){

    int n, a;
    cin >> n;
    
    bool one = false;

    while(n--){
        cin >> a;
        if( a == 1)
            one = true;
    }
    if(one) cout << "-1" << endl;
    else cout << "1" << endl;


    return 0;
}
