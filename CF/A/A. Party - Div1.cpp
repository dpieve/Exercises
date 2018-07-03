http://codeforces.com/contest/115/problem/A
Codeforces Beta #87 Editorial

#include <bits/stdc++.h>
using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    #define ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
}

#define MAX 2010
#define INF 0x3f3f3f3f
#define ll long long

int n, p[MAX];

int main(){

    init();
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    memset(p, -1, sizeof p);

    cin >> n;

    for(int i = 1, x; i <= n; ++i){
        cin >> x;
        p[i] = x;
    }

    int ans = 0;

    for(int i = 1; i <= n; ++i){

        int cnt = 0;
        for(int x = i; x != -1; x = p[x]) { ++cnt; }
        ans = max(ans, cnt);

    }

    cout << ans << endl;

    return 0;
}
