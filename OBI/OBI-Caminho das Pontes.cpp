#include <bits/stdc++.h>
#define INF 99999999

using namespace std;

typedef pair<int, int> ii;
typedef vector< ii >  vii;

int Dijkstra( vector< vii > &P, int N){
    int b[N+2];

    for(int i=0; i<=N; i++)
        b[i] = INF;

    b[0] = 0;
    priority_queue<ii, vii, greater<ii> > q;
    q.push( ii(0, 0) );                           //DIST - SOURCE
                                                  //Going to 0->(N)
    while(!q.empty()){                            // b mean buracos (minimize this number)
        ii top = q.top(); q.pop();                  

        int d = top.first;
        int u = top.second;

        for(int i=0; i<(int)P[u].size(); i++){
            ii v = P[u][i];
            if( b[v.second] > d  + v.first ){
                b[v.second] = d  + v.first;
                q.push( ii(b[v.second], v.second) );
            }
        }
    }

    return b[N];

}
int main(){
    
    int N, M, S, T, B;
    scanf("%d %d", &N, &M);

    vector < vii > P(N+2, vector<ii>());

    for(int i=0; i<M; i++){
        scanf("%d %d %d", &S, &T, &B);
        P[S].push_back(ii(B, T));
        P[T].push_back(ii(B, S));
    }

    cout << Dijkstra(P, N+1) << endl;

    return 0;
}
