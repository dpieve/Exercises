//Saci Den
// percorre matrix pelo caminho estabelecido ( 2 -> 1 -> 1 -> .. -> 3 ) 

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m; 
    scanf("%d %d", &n, &m);

    int pos[2], toca[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &toca[i][j]);

            if(toca[i][j] == 2){
                pos[0] = i;
                pos[1] = j;
            }
        }
    }

    bool ok = false;
    int x=pos[0], y=pos[1], cont=1;

    while(!ok){
        if(toca[x+1][y] == 1 && x+1 < n){
            x++; cont++;
            toca[x][y] = 4;
        }
        else if(toca[x-1][y] == 1 && x-1 >=0){
            x--; cont++;
            toca[x][y] = 4;
        }
        else if(toca[x][y+1] == 1 && y+1 < m){
            y++; cont++;
            toca[x][y] = 4;
        }
        else if(toca[x][y-1] == 1 && y-1 >=0){
            y--; cont++;
            toca[x][y] = 4;
        }else{
            if((toca[x+1][y]==3 && x+1<n) || (toca[x-1][y]==3 && x-1>=0) || (toca[x][y+1] == 3 && y+1<m) || (toca[x][y-1] == 3 && y-1>= 0)){
                cont++;
                ok = true;
            }else{
                x = pos[0]; 
                y = pos[1];
                cont=1;
            }
        }
    }
    cout << cont << endl;
  return 0;
}
