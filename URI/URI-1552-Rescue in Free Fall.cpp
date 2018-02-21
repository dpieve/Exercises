//https://www.urionlinejudge.com.br/judge/en/problems/view/1552
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, vis[505];
vector< ii > point;
vector< pair<double, int>  > G[505];

priority_queue< pair<double, int> > pq;


void finish(){
    if(!pq.empty())
        while(!pq.empty())
            pq.pop();
    point.clear();
    for(int i=0; i<n; i++)
            G[i].clear();
}

void processar(int v){
    vis[v] = 1;
    for(int i=0; i<G[v].size(); i++){
        pair<double, int> u = G[v][i];
        if(!vis[u.second])
            pq.push(make_pair(-u.first, -u.second));
    }
}

void prims(){
    memset(vis, 0, sizeof vis);
    processar(0);

    double mst_cost=0;
    while(!pq.empty()){
        pair<double, int> front = pq.top(); pq.pop();

        int u = -front.second;
        double w = -front.first;

        if(!vis[u]){
            mst_cost += w;
            processar(u);
        }
    }
    mst_cost /= 100.0;
    printf("%.2lf\n", mst_cost);
}


double distance(int x1, int y1, int x2, int y2){
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}
void build_dist(){

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            double d = distance(point[i].first, point[i].second, point[j].first, point[j].second);
            G[i].push_back(make_pair(d, j));
            G[j].push_back(make_pair(d, i));
        }
    }

    prims();
}

int main() {

    int c;
    scanf("%d", &c);

    while(c--){
        scanf("%d", &n);

        int x, y;
        for(int i=0; i<n; i++){
            scanf("%d %d", &x, &y);

            point.push_back(make_pair(x, y));
        }
        build_dist();

        finish();

    }  

  return 0;
}
