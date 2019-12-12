#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int N, K;
    scanf("%d %d", &N, &K);
    
    vector<int> v(N);
    
    for (int i = 0; i < N; ++i) {     
        scanf("%d", &v[i]);    
    }
    
    set<int> display;
    deque<int> remov;
    
    for (int i = 0; i < N; ++i) {
        
        int x = v[i];
        
        if (!display.count(x)) {
        
            if (display.size() < K) {
                display.insert(x);
                remov.push_front(x);
            }
            else {
        
                int y = remov.back();
                display.erase(y);
                remov.pop_back();
        
                display.insert(x);
                remov.push_front(x);
            
            /*
                for (int i = 0; i < (int)remov.size(); ++i) {
                    printf("%d ", remov[i]);
                }
                
                printf("\n");        
            */
            }
        
        
        }
    
    }
        
    int sz = (int)remov.size();
    
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++i) {
        printf("%d%c", remov[i], " \n"[i == sz -1]);
    }
    
    return 0;
}