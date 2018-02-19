#include <bits/stdc++.h>

using namespace std;

int main() {
   
    string A, B;
    cin >> A >> B;

    if( A == B ) printf("-1\n");
    else cout <<( (A.length() > B.length())? (A.length()):(B.length()) ) << endl;

  return 0;
}
