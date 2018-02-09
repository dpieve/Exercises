#include <bits/stdc++.h>

using namespace std;

int prefix_function(string B, int n){
    int i, j;

    vector<int> P(n + 1);
    P[0] = -1, i = 1, j = -1;

    while(B[i]){
        while(j>=0 && B[j+1]!=B[i])
            j = P[j];
        if(B[j+1] == B[i])
            ++j;
        P[i] = j; ++i;
    }
    return j;

}
int main(){

    string s;
    while(cin >> s){
        if(s[0] == '.' && s[1] == '\0')
            break;
        int n  = s.length();
        int ans= prefix_function(s, n);

        if(n%(n-ans-1) == 0)
            cout << n/(n-ans-1) << endl;
        else cout << "1" << endl;
    }
    return 0;
}
