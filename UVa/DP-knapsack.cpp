
//problema das mochilas The Pursuit of the Perfect Body // clássica DP
//maximar numero de proteínas, dado o máximo peso que pode consumir e a quantidade de carnes

#include <bits/stdc++.h>

using namespace std;

long long int max_peso,n_carnes,peso[2500],proteina[2500],res[2500][2500];

int main() {
   
  int i,j;

  scanf("%lld %lld",&max_peso,&n_carnes);
  for(i=1;i<=n_carnes;i++)
    scanf("%lld %lld",&peso[i],&proteina[i]);
  
  for(i=0;i<=max_peso;i++)
    res[0][i]=0; 
  
  for(i=1;i<=n_carnes;i++){
    res[i][0]=0;
    for(j=1;j<=max_peso;j++){
      if(peso[i]>j){
        res[i][j]=res[i-1][j];
      }else{
        if(proteina[i]+res[i-1][j-peso[i]] > res[i-1][j]){
          res[i][j] = proteina[i] + res[i-1][j-peso[i]];
        }else{
          res[i][j] = res[i-1][j];
        }
      }
    }
  }
  printf("%lld\n",res[n_carnes][max_peso]);
  return 0;
}









