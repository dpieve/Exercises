//https://www.urionlinejudge.com.br/judge/en/problems/view/1152

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

vi p, ranks;
vector< pair<int, ii> > byteland;

void initialize(int M){
    
    p.assign(M, 0);
    ranks.assign(M, 0);
    byteland.clear();

    for(int i=0; i<M; i++)
        p[i] = i;

}
int FindSet(int i){
    return (p[i] == i ) ? i:( p[i] = FindSet(p[i]));
}
bool isSameSet(int i, int j){
    return (FindSet(i) == FindSet(j));
}

void UnionSet(int i, int j){
    
    if(!isSameSet(i, j)){
        int x = FindSet(i);
        int y = FindSet(j);

        if(ranks[x] > ranks[y])
            p[y] = x;
        else{
            p[x] = y;

            if(ranks[x] == ranks[y])
                ranks[y]++;
        }
    }

}
int kruskal(int N){
    
    int mst_cost = 0;    
    sort(byteland.begin(), byteland.end());

    for(int i=0; i<N; i++){
        pair<int, ii> front = byteland[i];
        
        int u = front.second.first; 
        int v = front.second.second;
        int w = front.first;

        if(!isSameSet(u, v)){
            mst_cost += w;
            UnionSet(u, v);
        }
    }

    return mst_cost;
}

int main() {
   
    //freopen("input.txt", "r", stdin);

    int m, n, x, y, z;
    
    while(scanf("%d %d", &m, &n), m, n){
        
        initialize(m);

        int total = 0;
        for(int i=0; i<n; i++){
            scanf("%d %d %d", &x, &y, &z);
            total += z;

            byteland.push_back(make_pair(z, ii(x, y)));
        }

        int save = (total - kruskal(n));
        printf("%d\n", save);
    }
  return 0;
}
