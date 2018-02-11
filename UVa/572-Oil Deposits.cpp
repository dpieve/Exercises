#include <bits/stdc++.h>

using namespace std;

int row[] = {-1, -1,-1,  0, 0, 1, 1, 1};
int col[] = {-1,  0, 1, -1, 1,-1, 0, 1};

char m[103][103];
int linha, coluna;

bool is_valid(int i, int j){
    return ( (i>=0) && (i<linha) && (j>=0) && (j<coluna) );
}

void DFS(int idx_i, int idx_j){

    if( !is_valid(idx_i, idx_j) ) return;
    if( m[idx_i][idx_j] == '*'  ) return;

    m[idx_i][idx_j] = '*';

    for(int i=0; i<8; i++){
        DFS(idx_i + row[i], idx_j + col[i]);
    }
}

int main(){

    while(scanf("%d %d", &linha, &coluna), linha, coluna){
        getchar();

        for(int i=0; i<linha; i++){
            for(int j=0; j<coluna; j++)
                scanf("%c", &m[i][j]);
            getchar();
        }
            
        int pocket=0;
        for(int i=0; i<linha; i++)
            for(int j=0; j<coluna; j++)
                if(m[i][j] != '*'){
                    pocket++;
                    DFS(i, j);
                }
        printf("%d\n", pocket);

    }
    return 0;
}
