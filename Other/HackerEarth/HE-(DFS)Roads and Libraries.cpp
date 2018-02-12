#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

int nodes;
bool vis[MAX];
std::vector<int> road[MAX];

void dfs(int u){
  nodes++;
  vis[u] = true;

  for(vector<int>::iterator i = road[u].begin(); i != road[u].end(); i++)
    if(!vis[*i])
      dfs(*i);
}

int main(){

  //freopen("input.txt","r",stdin);

  int tc; cin >> tc;
  while(tc--){

    int n,m,cLib,cRoad;
    cin >> n >> m >> cLib >> cRoad;

    int u,v;
    for(int i=0;i<m;i++){
      scanf("%d %d",&u,&v);
      road[u].push_back(v);
      road[v].push_back(u);
    }

    memset(vis,false,sizeof vis);

    long cost=0;
    for(int i=1;i<=n;i++){
      if(!vis[i]){
        nodes=0;dfs(i);

        cost += cLib;                  //there is min=1 lib
        if(cLib > cRoad)
             cost += cRoad*(nodes-1);  //what's the best? Lib or Road for each city
        else cost += cLib* (nodes-1);
      }
    }

    cout << cost << '\n';

    for(int i=0;i<=n;i++)
      road[i].clear();
  }
  return 0;
}
