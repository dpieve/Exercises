//https://www.urionlinejudge.com.br/judge/en/problems/view/1031
#include <bits/stdc++.h>

using namespace std;

int main() {
 
    int n;
    while(scanf("%d", &n)==1 && n != 0){
        
        for(int m=1 ;; m++){
            vector<int> q(n);
        
            for(int i=0; i<n; i++)
                q[i] = i+1;

            int cur = 0;
            while((int)q.size() >= 1){
                if(q[cur] == 13)
                    break;

                q.erase(q.begin() + cur);
                cur += (m - 1);             //because (q[] < n)
                cur %= ((int)q.size());

            }
            if((int)q.size() == 1) {
                printf("%d\n", m);
                break;
            }
        }

    }


  return 0;
}
