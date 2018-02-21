#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    scanf("%d", &n);

    string name;
    map< string, int > teams; 

    for(int i=0; i<n; i++){
        cin >> name;

        teams[ name ]++;
    }

    
    string ans;
    int points = 0;

    map< string, int >::iterator it;
    for(it = teams.begin(); it !=teams.end(); it++){
        if( it->second > points){
            ans = it->first;
            points= it->second;
        }
    }
    cout << ans << endl;

  return 0;
}
