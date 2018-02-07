#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> ii;
typedef vector< int>  vi;
typedef vector< ii > vii;

vector< vii >  g;   vi dist1;
vector< vii > rg;   vi dist2;

void dijkstra(int s, vector<vii> &g, vector<int> &distance){
    distance[s]=0;

    priority_queue<ii, vii, greater<ii> > pq;
    pq.push(ii(0, s));

    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        for(int i=0; i<(int)g[u].size(); i++){
            ii v = g[u][i];

            if(distance[v.first] >  d + v.second){
                distance[v.first] = d + v.second;
                pq.push(ii(distance[v.first], v.first));
            }
        }
    }
}

int main(){

    int tc, n, m, k, s, t, u, v, w, rsp;

    cin >> tc;
    while(tc--){
        dist1=vi(10002, INF);
        dist2=vi(10002, INF);
   
        scanf("%d %d %d %d %d", &n, &m, &k, &s, &t);

        g = vector<vii> (n+1, vector<ii>());
        rg= vector<vii> (n+1, vector<ii>());
   
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &u, &v, &w);
             g[u].push_back(ii(v, w));
            rg[v].push_back(ii(u, w));
        }

        dijkstra(s,  g, dist1);
        dijkstra(t, rg, dist2);

        rsp = dist1[t];
        for(int i=0; i<k; i++){
            scanf("%d %d %d", &u, &v, &w);
            rsp = min(rsp, min(dist1[u]+w+dist2[v], dist1[v]+w+dist2[u]));
        }
        if(rsp == INF) printf("-1\n");
        else printf("%d\n", rsp);
    }

    return 0;
}
