//http://www.spoj.com/problems/MTOTALF/
#include <bits/stdc++.h>
#define INF 1000000

using namespace std;

typedef vector<int> vi;

vi p;
int f, s, t, res[100][100];

void augment(int v, int minEdge){
  if(v == s){
    f = minEdge;
    return;
  }
  else if(p[v] != -1){
    augment(p[v], min(minEdge, res[p[v]][v]));
    res[p[v]][v] -= f;
    res[v][p[v]] += f;
  }
}

int main() {

  int n;
  scanf("%d", &n);

  char x, y;
  int u, v, w, s, t;

  for(int i=0; i<n; i++){
    cin >> x >> y >> w;
    
    if(x < 93)
      u = x-65;
    else u = x-71;

    if(y < 93)
      v = y-65;
    else v = y-71;

    res[u][v] += w;
    res[v][u] += w;

  }  

  int mf = 0;
  s = 0; t = 25;

  while(1){
    f = 0;
    queue<int> q;
    q.push(s);

    p.assign(60, -1);
    int vis[100];
    memset(vis, false, sizeof vis);

    while(!q.empty()){
      u = q.front();
      q.pop();

      if(u == t) break;

      for(int v = 0; v < 52; v++){
        if(res[u][v] > 0 && vis[v] == false){
          q.push(v);
          vis[v]=true;
          p[v] = u;
        }
      }
    }

    augment(t, INF);
    if(f == 0) break;
    mf += f;
  }

  printf("%d\n", mf);
  return 0;
}
