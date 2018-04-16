//http://codeforces.com/problemset/problem/61/D

#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define MAXN 100001
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vii G[ MAXN ];
bool vis[MAXN];

ll DFS( int u ){

    ll resp = 0;
    vis[ u ] = true;

    for(int j = 0; j < (int)G[u].size(); j++){
        ii v = G[ u ][ j ];
        if( !vis[ v.first ])
            resp = max(resp, DFS(v.first) + v.second);
    }

    return resp;
}

int main(){

//    freopen("input.txt", "r", stdin);

    ll ans = 0;
    int n, x, y, w;
    memset(vis, false, sizeof vis);
    
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> x >> y >> w;

        G[x].emplace_back( ii(y, w) );
        G[y].emplace_back( ii(x, w) );
        
        ans += 2 * w;
    }

    ans = ans - DFS( 1 );
    cout << ans << endl;


    return 0;
}
