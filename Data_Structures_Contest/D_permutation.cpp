#include <bits/stdc++.h>

using namespace std;

void solver() {
    
    int K;
    scanf("%d", &K);
    
    vector <int> pos(K);
    
    for (int i = 0; i < K; ++i) {
        scanf("%d", &pos[i]);
    }
    
    vector <int> ans(K);
  
    for (int i = 1; i <= K; ++i) {
        ans[i - 1] = i;
    }
    
    for (int i = 0; i < K; ++i) {
        printf("%d%c", ans[pos[i]], " \n"[i == K - 1]);
        ans.erase(ans.begin() + pos[i]);
    }
    
}

int main(){
    
    int T;
    scanf("%d", &T);
    
    while(T--) {
        solver();
    }
    
    return 0;
}