#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 110;
const int INF  = 0x3f3f3f3f;

ll T, N, M, a[MAXN], dp[MAXN][MAXN];

ll solve (ll i, ll k) {

    if (i == N) {
        if (k == M) return 0;
        else return INF;
    }

    ll &p = dp[i][k];
    if (p + 1) return p;

    p = INF;

    for (int j = 1; j <= N; ++j) {
        if (i + j <= N) {
            p = min ( p, (a[i + j - 1] - a[i]) + solve (i + j, k + 1) );
        }
    }

    return p;
}



int main () {

    scanf("%lld", &T);
    for (int cc = 1; cc <= T; ++cc) {

        scanf("%lld %lld", &N, &M);
        
        for (int i = 0; i < N; ++i) scanf("%lld", a + i);

        sort (a, a + N);

        memset (dp, -1, sizeof dp);

        printf("Case #%d: %lld\n", cc, solve (0, 0));
    }





    return 0;
}
