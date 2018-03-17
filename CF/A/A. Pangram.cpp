//http://codeforces.com/contest/520/problem/A
#include <set>
#include <string>
#include <ctype.h>
#include <iostream>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    string s;
    cin >> s;

    set<char> w;

    for(int i=0; (int)i<s.length(); i++){
        w.insert( tolower(s[i]) );
    }

    if(w.size() == 26)
        cout << "YES" << endl;
    else cout << "NO" << endl;


  return 0;
}
