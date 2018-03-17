//http://codeforces.com/contest/705/problem/A

#include <iostream>
#include <string>
using namespace std;

int main() {

    string feel = "I hate";
    string love = " that I love", hate = " that I hate";

    bool flag = true;

    int n;
    cin >> n;

    for(int i=1; i<n; i++){
        if(flag){
            feel += love;
            flag  = false;
        }
        else{
            feel += hate;
            flag = true;
        } 
    }
    feel += " it";
    cout << feel << endl;

  return 0;
}
