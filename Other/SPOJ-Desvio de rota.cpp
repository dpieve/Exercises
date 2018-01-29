#include <bits/stdc++.h>
#define INF 100000
using namespace std;

typedef pair<int,int> ii;
typedef std::vector<int> vi;
typedef std::vector<ii> vii;

int n;
std::vector< vii > g;

int dijkstra(int start, int dest){
    priority_queue< ii,vector<ii>,greater<ii> > pq; 
    pq.push(ii(0,start));

    vi dist(n+1, INF), vis(n+1, 0);
    dist[start]=0; vis[start]=1;

    while(!pq.empty()){
        ii front = pq.top(); pq.pop();
        int u = front.second;

        vis[u]= 1; if(u == dest) break;
        for(int j=0; j<g[u].size(); j++){
            ii v = g[u][j];

            if(vis[v.second] == 0){
                if(dist[v.second] > dist[u] + v.first){
                    dist[v.second]= dist[u] + v.first;
                    pq.push(ii(dist[v.second], v.second));
                }
            }
        }
    }

    return dist[dest];

}

int main (){

    while(1){

        int m, c, k;
        scanf("%d %d %d %d", &n, &m, &c, &k);


        if(n==0 && m==0 && c==0 && k==0) break;
        g.clear(); g.resize(n);

        int u, v, w;
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &u, &v, &w);

            if(u<c && v<c){
                if(u==v-1){
                    g[u].push_back(make_pair(w, v));
                }
                if(v==u-1){
                    g[v].push_back(make_pair(w, u));
                }
            }
            else{
                if(u<c && v>=c){
                    g[v].push_back(make_pair(w, u));
                }
                else if(v<c && u>=c){
                    g[u].push_back(make_pair(w, v));
                }
                else if(u>=c && v>=c){
                    g[u].push_back(make_pair(w, v));
                    g[v].push_back(make_pair(w, u));
                }
            }
        }
        int ans = dijkstra(k, c-1);
        cout << ans << endl;
    }

    return 0;
}
