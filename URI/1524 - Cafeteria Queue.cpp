//https://www.urionlinejudge.com.br/judge/en/problems/view/1524

#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define ll long long
const int MN = 1123;
const ll INF = 0x3f3f3f3f;

int N, K;
ll a[MN], memo[MN][MN];

ll solve (int s, int k) {
    if ( s >= N ){
        return ( (k == 0) ? 0 : (INF));
    }

    ll &p = memo[s][k];
    if(p + 1) return p;

    p = solve(s + 1, k) + (s == 0 ? a[s] : a[s] - a[s - 1]);
    if(k > 0) {
        p = min(p, solve(s + 1, k - 1)); 
    }
    return p;
}

int main() {
    FAST
    while(cin >> N >> K) {

        memset(memo, -1LL, sizeof memo);
        
        a[0] = 0;
        for (int i = 1; i < N; ++i) {
            cin >> a[i];
        }

        cout << solve(0, K - 1) << endl;
    
    }


    return 0;
}

