//(OBI 2011, Fase 2, Nível 2)
#include <bits/stdc++.h>
#define MAXN 502
using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

int parent[MAXN], ranks[MAXN];
std::vector<pair<int, ii> > rodovia;

int find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
bool isSameSet(int x, int y){
    return (find(x) == find(y));
}
void union_set(int i, int j){
    int x = find(i);
    int y = find(j);

    if(ranks[x] > ranks[y])
        parent[y] = x;
    else parent[x]= y;

    if(ranks[x]==ranks[y])
        ranks[y]++;
}
void initialize(int n){
    for(int i=0; i<=n; i++){
       ranks[i]  = 0;
       parent[i]= i;
    }
    sort(rodovia.begin(), rodovia.end());
}
int main(){

    int n, m, u, v, w;
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++){
        scanf("%d %d %d", &u, &v, &w);
        rodovia.push_back(make_pair(w, ii(u, v)));
    }
    initialize(n);

    ll mst=0;
    for(int i=0; i<m; i++){
        pair<int, ii> menor = rodovia[i];
        if(!isSameSet(menor.second.first, menor.second.second)){
            mst += menor.first;
            union_set(menor.second.first, menor.second.second);
        }
    }

    cout << mst << endl;
    return 0;
}
