#include <bits/stdc++.h>
#define MAXN 105

using namespace std;

char G[MAXN][MAXN];

int n;
int row[]= {1,-1,0, 0,1, 1,-1,-1};
int col[]= {0, 0,1,-1,1,-1,-1, 1};


bool is_valid(int x, int y){
    return( (x>=0) && (x<n) && (y>=0) && (y<n) );
}
void DFS(int idx_i, int idx_j){
    G[idx_i][idx_j] = '.';
    for(int i=0; i<4; i++){

        int r = idx_i + row[i];
        int c = idx_j + col[i];

        if( G[r][c] != '.' && is_valid(r, c))
            DFS(r, c);
    }
}
int main(){

    int t;
    scanf("%d", &t);

    for(int c=1; c<=t; c++){
        scanf("%d", &n);

        for(int i=0; i<n; i++)
            scanf("%s", G[i]);

        int A=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(G[i][j] == 'x' || G[i][j] == 'X'){
                   A++; DFS(i, j);
                }
        printf("Case %d: %d\n", c, A);
    }

    return 0;
}
