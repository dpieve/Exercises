#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define MAXN 10005
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll Dijkstra(int start, int end, int V, vii G[]){
    vector< ll > dist(V+1, INF);
    dist[start] = 0;

    priority_queue< ii, vii, greater<ii> > q;

    q.push(mp(0, start));

    while(!q.empty()){
        ii front = q.top();
        q.pop();

        int u = front.second, d = front.first;

        if(d > dist[u])
            continue;


        for(int i=0; i<(int)G[u].size(); i++){
            ii v = G[u][i];

            if(dist[ v.second ] > v.first + dist[u]){
                dist[v.second ] = v.first + dist[u];

                q.push(mp(dist[v.second], v.second)); 
            }
        }

    }
    return dist[end];
}


int main(){

    //freopen("input.txt", "r", stdin);

    int cases;
    scanf("%d", &cases);

    while(cases--){

        int V, K;
        scanf("%d %d", &V, &K);

        vii G[MAXN];
        int u, v, w;

        for(int i=0; i<K; i++){
            scanf("%d %d %d", &u, &v, &w);

            G[u].push_back(mp(w, v));
        }

        int A, B;
        scanf("%d %d", &A, &B);

        ll ans = Dijkstra(A, B, V, G);

        if(ans == INF)
            printf("NO\n");
        else printf("%lld\n", ans);

    }
    return 0;
}
