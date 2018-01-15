#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    numSets = N;
    p.assign(N, 0);
    rank.assign(N, 0);
    setSize.assign(N, 1);
    for (int i = 0; i <= N; i++)
      p[i] = i;
  }
  int findSet(int i){
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
  }
  void unionSet(int i, int j){
    if (!isSameSet(i, j)){
      numSets--;
      int x = findSet(i);
      int y = findSet(j);

      if (rank[x] > rank[y]){
        p[y] = x;
        setSize[x] += setSize[y];
      }else{
        p[x] = y;
        setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
}
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i)  { return setSize[findSet(i)]; }
};

int main() {

  freopen("input.txt", "r", stdin);

  int n,m,k,ok=0;
  vector< pair<int, ii> > EdgeList;
  while(scanf("%d",&n)==1){
    int u,v,w,total=0;
    for(int i=0;i<(n-1);i++){
      scanf("%d %d %d",&u,&v,&w);
      total+=w;
    }
    if(ok) puts(""); ok=1;
    printf("%d\n",total);

    scanf("%d",&k);
    for(int i=0;i<k;i++){
      scanf("%d %d %d",&u,&v,&w);
      EdgeList.push_back(make_pair(w, ii(u, v)));
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
      scanf("%d %d %d",&u,&v,&w);
      EdgeList.push_back(make_pair(w, ii(u, v)));
    }
    sort(EdgeList.begin(), EdgeList.end());


  int mst_cost = 0;
  UnionFind UF(n);
  for (int i = 0; i < k+m; i++) {
    pair<int, ii> front = EdgeList[i];
    if (!UF.isSameSet(front.second.first, front.second.second)) {
      mst_cost += front.first;
      UF.unionSet(front.second.first, front.second.second);
  } }

  printf("%d\n", mst_cost);
  EdgeList.clear();
  }

  return 0;
}
/* simple
#include <algorithm>
#include <cstdio>
#include <vector>

#define MAX 1000001
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vi p;
vector< pair<int, ii> > EdgeList;

int n;
void initialize(){
  p.assign(n, 0);
  for (int i = 0; i <= n; i++)
      p[i] = i;
}
int findSet(int i){
    if(p[i] == i)
      return i;
    else return p[i] = findSet(p[i]);
}
int main() {

int m,k,u,v,w,ok=0;
  
  while(scanf("%d",&n)==1){
    int total=0;
    for(int i=0;i<(n-1);i++){
      scanf("%d %d %d",&u,&v,&w);
      total+=w;
    }
    if(ok) puts(""); ok=1;
    printf("%d\n",total);

    scanf("%d",&k);
    for(int i=0;i<k;i++){
      scanf("%d %d %d",&u,&v,&w);
      EdgeList.push_back(make_pair(w, ii(u, v)));
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
      scanf("%d %d %d",&u,&v,&w);
      EdgeList.push_back(make_pair(w, ii(u, v)));
    }
    sort(EdgeList.begin(), EdgeList.end());
  
    initialize(); total=0;
    for (int i = 0; i < (k+m); i++) {
      u = EdgeList[i].second.first;
      v = EdgeList[i].second.second;
      w = EdgeList[i].first;
      if (findSet(u) != findSet(v)){
        total += w;
        int x = findSet(u);
        int y = findSet(v);
        p[y]=x;
      } 
    }
    printf("%d\n", total);
    EdgeList.clear();
  }

  return 0;
}
*/
