#include <bits/stdc++.h>

using namespace std;

typedef queue<int> qi;

int N;
char img[27][27];

qi q;
void dfs(int i, int j){

  q.push(i);
  q.push(j);

  while(!q.empty()){
    i = q.front(); q.pop();
    j = q.front(); q.pop();

    if(img[i-1][j] == '1'){
      q.push(i-1);
      q.push(j);
      img[i-1][j] = '0';
    }
    if(img[i+1][j] == '1'){
      q.push(i+1);
      q.push(j);
      img[i+1][j] = '0';
    }
    if(img[i][j-1] == '1'){
      q.push(i);
      q.push(j-1);
      img[i][j-1] = '0';
    }
    if(img[i][j+1] == '1'){
      q.push(i);
      q.push(j+1);
      img[i][j+1] = '0';
    }
    if(img[i+1][j+1] == '1'){
      q.push(i+1);
      q.push(j+1);
      img[i+1][j+1] = '0';
    }
    if(img[i-1][j-1] == '1'){
      q.push(i-1);
      q.push(j-1);
      img[i-1][j-1] = '0';
    }
    if(img[i-1][j+1] == '1'){
      q.push(i-1);
      q.push(j+1);
      img[i-1][j+1] = '0';
    }
    if(img[i+1][j-1] == '1'){
      q.push(i+1);
      q.push(j-1);
      img[i+1][j-1] = '0';
    }
  }
}

int main() {
   
   //freopen("input.txt","r",stdin);

  int num_img=1;
  while(scanf("%d",&N) != EOF){
    getchar();

    for(int i=0;i<N;i++)
      scanf("%s",img[i]);

    int war=0;
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        if(img[i][j] == '1'){
          dfs(i,j);
          war++;
        }
    printf("Image number %d contains %d war eagles.\n", num_img++,war);
  }
  return 0;
}
