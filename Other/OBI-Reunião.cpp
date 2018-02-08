//http://olimpiada.ic.unicamp.br/passadas/OBI2010/res_fase1_prog/programacao_n2/
#include <bits/stdc++.h>
#define MAX 105
#define INF 10005

using namespace std;

int main(){
    
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);

    int distancia[MAX][MAX];

    memset (distancia, INF, sizeof distancia);
    for(int i=0; i<=n; i++) distancia[i][i]=0;

    for(int i=0; i<m; i++){
        scanf("%d %d %d", &u, &v, &w);
        
        //caso tenha caminho mais próximo ou a distancia está como INF então atualiza
        if(distancia[u][v] > w || distancia[u][v] > MAX)
           distancia[u][v] = distancia[v][u] = w;
    }
    
    // FW- menor distância de todos os vértices
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                distancia[i][j] = min(distancia[i][j], distancia[i][k]+distancia[k][j]);
    }
                        
    int menor = INF;
    for(int i=0; i<n; i++){
        int maior = -1;
        
        //qual está mais distante;
        for(int j=0; j<n; j++)
            maior = max(maior, distancia[j][i]);
        menor = min(menor, maior);
    }

    printf("%d\n", menor);
    return 0;
}
