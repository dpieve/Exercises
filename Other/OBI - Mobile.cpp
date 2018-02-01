//OBI http://www.codcad.com/problem/103
#include <bits/stdc++.h>

using namespace std;

bool ok;
std::vector< vector<int> > mobile;

int DFS(int u){
    int total=1, curr, weight;

    for(int i = 0; i<mobile[u].size(); i++){
        int v = mobile[u][i];

        curr = DFS(v);
        if(i == 0) weight = curr;
        else    if(weight!= curr) ok=0;

        total += curr;
    }
    return total;
}
int main() {
 
      int n, x, y;
      scanf("%d", &n);

      mobile.resize(n+1);
      for(int i=0; i<n; i++){
        scanf("%d %d", &x, &y);
        mobile[y].push_back(x);
      }
      ok=1; DFS(0);
      cout << (ok==true?"bem":"mal") << endl;

 return 0;
}
