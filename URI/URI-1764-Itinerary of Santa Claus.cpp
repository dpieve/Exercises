//https://www.urionlinejudge.com.br/judge/en/problems/view/1764

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

class UnionFind
{
    private:
        vi rank, p;
    public:
        UnionFind(int N){
            p.assign(N, 0);
            rank.assign(N, 0);

            for(int i=0; i<N; i++)
                p[i] = i;
        }
        int findSet(int i){
            return (p[i]==i)?i:(p[i]=findSet(p[i]));
        }
        bool isSameSet(int i, int j){
            return (findSet(i) == findSet(j));
        }
        void unionSet(int i, int j){
            if(!isSameSet(i, j)){
                int x = findSet(i);
                int y = findSet(j);
                if(rank[x] > rank[y])
                    p[y] = x;
                else{
                    p[x] = y;

                    if(rank[x] == rank[y])
                        rank[y]++;
                }
            }   
        }
};

vector< pair<int, ii> > city;

int kruskal(int m, int n){
    
    UnionFind UF(m);
    int mst_cost = 0;

    sort(city.begin(), city.end());

    for(int i=0; i<n; i++){
        pair<int, ii> front = city[i];
        int u = front.second.first;
        int v = front.second.second;
        int w = front.first;

        if(!UF.isSameSet(u, v)){
            mst_cost += w;
            UF.unionSet(u, v);
        }
    }
    return mst_cost;
}

int main() {

   //freopen("input.txt", "r", stdin);
   
   int m, n;
   while(scanf("%d %d", &m, &n), m, n){
        int u, v, w;
        for(int i=0; i<n; i++){
            scanf("%d %d %d", &u, &v, &w);
            city.push_back(make_pair(w, ii(u, v)));
        }
        int solve = kruskal(m, n);
        printf("%d\n", solve);
   
        city.clear();
   }    

  return 0;
}
