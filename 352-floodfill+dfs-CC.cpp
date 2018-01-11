#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdio>

using namespace std;

char a[30][30];
int dimension;
queue<int> q;

void dfs(int x,int y){
  q.push(x);
  q.push(y);

  while(!q.empty()){
    x = q.front(); q.pop();
    y = q.front(); q.pop();
    
    if(a[x-1][y] == '1'){
      q.push(x-1);
      q.push(y);
      a[x-1][y]='0';
    }
    if(a[x+1][y] == '1'){
      q.push(x+1);
      q.push(y);
      a[x+1][y]='0';
    }
    if(a[x][y+1] == '1'){
      q.push(x);
      q.push(y+1);
      a[x][y+1]='0';
    }
    if(a[x][y-1] == '1'){
      q.push(x);
      q.push(y-1);
      a[x][y-1]='0';
    }

    if(a[x-1][y-1] == '1'){
      q.push(x-1);
      q.push(y-1);
      a[x-1][y-1]='0';
    }
    if(a[x+1][y+1] == '1'){
      q.push(x+1);
      q.push(y+1);
      a[x+1][y+1]='0';
    }
    if(a[x-1][y+1] == '1'){
      q.push(x-1);
      q.push(y+1);
      a[x-1][y+1]='0';
    }
    if(a[x+1][y-1] == '1'){
      q.push(x+1);
      q.push(y-1);
      a[x+1][y-1]='0';
    }

  }
}

int main() {
   
//  freopen("input.txt","r",stdin);
 
  int cnt=0;
  while(scanf("%d",&dimension) != EOF){
    getchar();

    for(int i=0;i<dimension;i++)
      scanf("%s",a[i]);

    int comp=0;
    for(int i=0;i<dimension;i++)
      for(int j=0;j<dimension;j++)
        if(a[i][j] == '1'){
          comp++;
          dfs(i,j);
        }

    printf("Image number %d contains %d war eagles.\n",++cnt,comp);
  
  }
  return 0;
}
