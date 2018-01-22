#include <bits/stdc++.h>

using namespace std;

int ans(int x){
    if(x<=1)
        return 1;

    if(x&1) return (ans((x+1)/2)-1) *2; // if x is odd
    else    return (ans( x/2))      *2;
}

int main(){
    
    freopen("input.txt","r",stdin);

    int n;
    while(scanf("%d",&n),n){
        printf("%d\n", ans(n));
    }

    return 0;
}


/* TIME LIMITE
#include <bits/stdc++.h>

using namespace std;

int f(int n){
    if(n<=1)
        return 1;

    queue<int> last;
    for(int x=1;x<=n;x++)
        last.push(x);

    while(last.size()!=1){
        last.pop();
        last.push(last.front());
        last.pop();
    }
    return (last.front());
}
int main(){
    
    //freopen("input.txt","r",stdin);

    int n;
    while(scanf("%d",&n),n){
        printf("%d\n",f(n));
    }

    return 0;
}

*/
