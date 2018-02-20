#include <bits/stdc++.h>

using namespace std;

string str[103];
int n, m, g[103][103];

bool is_ok(int i, int j){
    return( (i>=0) && (i<n) && (j>=0) && (j<m) && (str[i][j] != '*') && (g[i][j] != -1) );
}

void adiciona(int i, int j){
    
    //up
    if(is_ok(i-1, j))
        g[i-1][j]++;
    //down
    if(is_ok(i+1, j))
        g[i+1][j]++;
    
    //left
    if(is_ok(i, j-1))
        g[i][j-1]++;
    //right
    if(is_ok(i, j+1))
        g[i][j+1]++;

    //diag
    if(is_ok(i+1, j+1))
        g[i+1][j+1]++;
    if(is_ok(i-1, j-1))
        g[i-1][j-1]++;

    if(is_ok(i-1, j+1))
        g[i-1][j+1]++;
    if(is_ok(i+1, j-1))
        g[i+1][j-1]++;

}

void initialize(){
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            g[i][j]=0;
}
int main() {

    int field=1; bool flag = false;
   
    while(scanf("%d %d", &n, &m), n, m){

        initialize();
        if(!flag) flag=true; else puts("");
        
        for(int i=0; i<n; i++)
            cin >> str[i];

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(str[i][j] == '*'){
                    g[i][j] = -1;
                    adiciona(i, j);
                }

        

        printf("Field #%d:\n", field++);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(g[i][j] == -1)
                    printf("*");
                else printf("%d", g[i][j]);
            }
            printf("\n");
        }
    }

  return 0;
}
