#include <bits/stdc++.h>
#define MAXN 50002

using namespace std;

int n;
std::vector<int> m, v, sum;

int DFS(int u){
    v[u] = 1;

    int total =0;
    if(m[u] != -1 && !v[ m[u] ]){
        total += ( 1 + DFS( m[u] ));
    }
    v[u] = 0;
    return (sum[u] = total);
}
int main(){


    int t, x, y;
    scanf("%d", &t);

    for(int c=1; c<=t; c++){
        scanf("%d", &n);

        m.assign(n, -1); sum.assign(n, -1); v.assign(n, 0);
        for(int i=0; i<n; i++){
            scanf("%d %d", &x, &y);
            m[x-1] = y-1;
        }

        int rsp=0, max_martian=0;
        for(int i=0; i<n; i++){
            if(sum[i] == -1)
                DFS(i);
            if(sum[i] > max_martian){
                max_martian = sum[i];
                rsp = i;
            }
        }
        printf("Case %d: %d\n", c, ++rsp);
    }

    return 0;
}
