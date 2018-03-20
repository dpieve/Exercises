//https://www.codechef.com/INOIPRAC/problems/INOI1601

#include <bits/stdc++.h>

#define pb push_back

#define MAXN 100001
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi P[MAXN];
int ans, W[MAXN];

void DFS(int u, int mx){

    ans = max(ans, mx - W[u]);
    mx  = max(mx , W[u]);

    vi::iterator it;

    for(it = P[u].begin(); it != P[u].end(); it++)
        DFS(*it, mx);
}

int main(){

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for(int j=1; j<=n; j++)
        cin >> W[j];

    int c, s;
    for(int j=1; j<=n; j++){
        cin >> c;

        if(c == -1)
            s = j;
        else P[c].pb(j);
    }

    ans = 0;
    vi::iterator it;

    for(it = P[s].begin(); it != P[s].end(); it++){
        DFS(*it, W[s]);
    }

    cout << ans << endl;
    
    return 0;
}
