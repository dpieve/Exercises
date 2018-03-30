//https://www.urionlinejudge.com.br/judge/en/problems/view/1136

#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define MAXN 100000
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){

    //freopen("input.txt", "r", stdin);

    int N, B;
    
    while(cin >> N >> B, N, B){
        vi b(B), vis(N+1, 0);

        for(int i = 0; i < B; i++){
            cin >> b[i];

            vis[ b[i] ] = 1;
        }

        for(int i = 0; i < b.size(); i++){
            for(int j = i+1; j < b.size(); j++){
                int v = abs(b[i] - b[j]);
                if( vis[ v ] == 0 )
                    vis[ v ] = 1;
            }
        }

        bool ans = true;
        for(int i = 0; i <= N; i++)
            if(vis [ i ] == 0 ){
                ans = false;
                break;
            }
        if(ans) cout << "Y" << endl;
        else cout << "N" << endl;

    }

    return 0;
}
