//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1869&mosmsg=Submission+received+with+ID+20859851

#include <bits/stdc++.h>

using namespace std;


int main() {

 // freopen("input.txt", "r", stdin);

  int n, p;
  map< int,int > vis;

  char v[10001];

  scanf("%d", &n);

  while(n--){
    scanf("%d\n", &p);

    vis.clear();

    int ans = 100000;
    for(int i=1; i<=p; i++){
      fgets(v, 10001, stdin);

      int n_vis = 1;
      for(int j=0; v[j] != '\0' ; j++)
        if(v[j] == ' ')
          n_vis++;

      vis[i] = n_vis;
      ans = min(ans, n_vis);

    }
    bool first = true;
    for(int i=1; i<=p; i++)
      if(vis[i] == ans){
        if(!first)
          printf(" ");
        first = false;

        printf("%d", i);
      }

    printf("\n");
  }


  return 0;
}
