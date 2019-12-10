//https://olimpiada.ic.unicamp.br/pratique/p2/2017/f1/botas/

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

    int N;
    cin >> N;

    char L;
    int M, vD[ 65 ] = {0} , vE[ 65 ] = {0};

    for(int i = 0; i < N; i++){
        
        cin >> M >> L;

        if( L == 'D' ) 
             vD[M]++;
        else vE[M]++;
    }

    int total = 0;

    for(int i = 30; i <= 60; i++)
        total += min(vD[i], vE[i]);

    cout << total << endl;

    return 0;
}
