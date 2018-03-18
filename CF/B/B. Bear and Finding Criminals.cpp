//http://codeforces.com/contest/680/problem/B


#include <bits/stdc++.h>

using namespace std;

int main() {
 
    //freopen("input.txt", "r", stdin);

    int n, a;
    cin >> n >> a;

    int t[n +2];

    for(int i = 1; i <= n; i++)
        cin >> t[i];

    int count = 0;

    if(t[a] == 1)
        count = 1;

    int j = 1;
    for(int i=a+1; i<=n; i++){
        if(t[i] == 1){
            if( (a-j)>0 && t[a-j] == 1 )
                count += 2;
            else if(a-j <= 0)
                count++;
        }
        j++;
    }
    while(a-j > 0){
        if(t[a-j] == 1)
            count++;
        j++;
    }

    cout << count << endl;

  return 0;
}
