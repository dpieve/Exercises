//http://codeforces.com/contest/448/problem/A

#include <iostream>

using namespace std;

int main() {
   
    //freopen("input.txt", "r", stdin);

    int n, x, s1 = 0, s2 = 0;

    for(int i=0; i<6; i++){
        cin >> x;

        if(i > 2){
            s2 += x;
            continue;
        }
        
        s1 += x;
    }

    cin >> n;

    int qA = 0, qB = 0;
    if(s1 > 5){
        qA = s1 / 5;

        if(s1 % 5 != 0)
            qA++;
    }else{
        if(s1 != 0)
            qA++;
    }
    if(s2 > 10){
        qB = s2 / 10;

        if(s2 % 10 != 0)
            qB++;
    }else{ 
        if(s2 != 0)
            qB++;
    }

    if(qA + qB > n)
        cout << "NO" << endl;
    else cout << "YES" << endl;

  return 0;
}
