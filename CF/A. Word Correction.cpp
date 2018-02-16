//http://codeforces.com/contest/938/problem/A

#include <bits/stdc++.h>

using namespace std;

bool vowel(char x){
    return ( (x=='a') || (x=='e') || (x=='i') || (x=='o') || (x=='u') || (x=='y') );
}
int main(){

    int n; 
    scanf("%d", &n);

    string s;
    vector<char> v;

    cin >> s;
    for(int i=0; i<n; i++)
        v.push_back(s[i]);

    for(int i=v.size()-1; i>=1; i--){
        if(vowel(v[i]) && vowel(v[i-1]))
            v.erase( v.begin() + i);
    }
    for(int i=0; i<v.size(); i++)
        cout << v[i];
    cout << endl;

    return 0;
}
