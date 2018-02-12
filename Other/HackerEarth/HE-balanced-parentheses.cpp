//https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/little-monk-and-balanced-parentheses/description/

#include <bits/stdc++.h>

using namespace std;

int main(){
    
    //freopen("input.txt","r",stdin);

    int n;
    scanf("%d",&n);

    int b[n + 10];
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);

    int ans=0;
    stack<int> s; s.push(0);

    for(int i=1;i<=n;i++){
        if(b[i]>0) s.push(i);
        else{
            int idx = s.top(); s.pop();
            if(b[idx] == -b[i])
                 ans = max(ans,i-s.top());
            else s.push(i);
        } 
    }
    printf("%d\n",ans);

    return 0;
}
