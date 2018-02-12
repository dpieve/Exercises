//https://www.urionlinejudge.com.br/judge/en/problems/view/1112

#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

typedef long long int ll;

int n, m, p;
ll tree[MAX][MAX];

void update(int x, int y, ll v) {
    for (int id_x = x; id_x <= n; id_x += (id_x & -id_x)) {
        for (int id_y = y; id_y <= m; id_y += (id_y & -id_y)) {
            tree[id_x][id_y] += v;
        }
    }
}

ll query(int x, int y) {
    ll ans = 0LL;
    for (int id_x = x; id_x > 0; id_x -= (id_x & -id_x)) {
        for (int id_y = y; id_y > 0; id_y -= (id_y & -id_y)) {
            ans += tree[id_x][id_y];
        }
    }
    return ans;
}
int main(){

    char c;
    int q, x1, y1, x2, y2, v;

    while(scanf("%d %d %d", &n, &m, &p)==3){
        if(!n && !m && !p) break;

        scanf("%d", &q);
        while(q--){
            scanf(" %c", &c);
            if(c == 'A'){
                scanf("%d %d %d", &v, &x1, &y1);
                update(x1+1, y1+1, v);
            }else{
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1++; y1++; x2++; y2++;
                if(x1 > x2) swap(x1, x2);
                if(y1 > y2) swap(y1, y2);

                ll ans = p* (query(x2, y2)- query(x2, y1-1)-query(x1-1, y2)+query(x1-1, y1-1));
                printf("%lld\n", ans);
            }
        }
        memset(tree, 0, sizeof(tree));
        printf("\n");
    }
    return 0;
}
