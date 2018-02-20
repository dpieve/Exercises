//http://codeforces.com/contest/490/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int n, gift;
    scanf("%d", &n);

    stack<int> p1, p2, p3;

    for(int i=1; i<=n; i++){
        scanf("%d", &gift);
    
             if(gift == 1) p1.push(i);
        else if(gift == 2) p2.push(i);
        else               p3.push(i);
    }

    vector<int> ans;
    int a, b, c, n_teams=0;

    while(!p1.empty() && !p2.empty() && !p3.empty()){
        n_teams++;

        a = p1.top();
        b = p2.top();
        c = p3.top();
        p1.pop(); p2.pop(); p3.pop();

        ans.push_back(a);
        ans.push_back(b);
        ans.push_back(c);
    }

    printf("%d\n", n_teams);
    for(int i=0; i<ans.size(); i++){
        printf("%d ", ans[i]);

        if( ((i+1) % 3) == 0 )
            printf("\n");
    }

  return 0;
}
