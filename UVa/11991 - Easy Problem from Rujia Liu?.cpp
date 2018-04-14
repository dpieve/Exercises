#include <cstdio>
#include <vector>

using namespace std;

int main(){

    //freopen("input.txt", "r", stdin);

    int n, m, v, k, i; 
    vector< vector<int> > G;

    while(scanf("%d %d", &n, &m) != EOF){
        
        G.assign(1000000, std::vector<int>());

        for(i = 1; i <= n; i++){
            scanf("%d", &v);

            G[v].push_back(i);
        }
        for(i = 0; i < m; i++){
            scanf("%d %d", &k, &v);

            if( k-1 < (int)G[v].size())
                 printf("%d\n", G[v][k-1]);
            else printf("0\n");
        }
    }

    return 0;
}
