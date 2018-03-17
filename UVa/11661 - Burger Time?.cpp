#include <bits/stdc++.h>

#define MAX 2000000
#define LL long long int

using namespace std;

int main() {
   

    //freopen("input.txt", "r", stdin);

    LL len;
    while(cin >> len, len){

        string positions;
        cin >> positions;
    
        LL dist = MAX, D = MAX, R = -MAX; 
        for(LL i=0; i<(int)positions.size(); i++){
            if(positions[i] == 'Z'){
                dist = 0;
                break;
            }

            if(positions[i] == 'D'){
                D = i;
            }else{
                if(positions[i] == 'R')
                    R = i;
            }

            dist = min(dist, abs(D-R));
            
        }
        cout << dist << endl;
    }

  return 0;
}
