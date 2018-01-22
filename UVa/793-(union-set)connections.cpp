#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define N 1000000

using namespace std;

int parent[N];

int find(int x){
    if(parent[x] == x)
         return x;
    else return parent[x] = find(parent[x]); 
}

int main(){

  int tc,n;
  scanf("%d",&tc);

  bool space = false;
  while(tc--){
    scanf("%d",&n); getchar();
    for(int i=0;i<N;i++) parent[i]=i;
    
    char c;
    int c1,c2,yes=0,no=0;
    while( (c=getchar()) && isalpha(c) ){
        scanf("%d %d",&c1,&c2); getchar();
        c1 = find(c1);
        c2 = find(c2);

        if(c == 'c')
            parent[c1]=c2;
        else{
            if(c1 == c2) yes++;
            else no++;
        }
    }
    if(space) printf("\n"); space=true;
    printf("%d,%d\n",yes,no);
  }    
  

  return 0;
}
