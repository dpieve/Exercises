#include <stdio.h>
#include <vector>
#include <cstdio>
#include <string.h>

#define MAX 100001

using namespace std;


int v,cats_max,cnt,restaurant;
int cat_here[MAX],vis[MAX];

std::vector<int> path[MAX];

void dfs(int u,int qtd){
    vis[u]=1;
    if(qtd > cats_max) 
        return;
    bool leaf=true;
    for(int i=0;i<path[u].size();i++){
        int v = path[u][i];
        if(!vis[v]){
            leaf=false;  
            if(cat_here[v])
                 dfs(v,qtd+1);
            else dfs(v,0);
        }
    }
    if(leaf) restaurant++;
}

int main(){
    
    //freopen("input.txt","r",stdin);

    scanf("%d %d",&v,&cats_max);

    int temp,i;
    for(i=1;i<=v;i++){
        scanf("%d",&temp);
        cat_here[i]=temp;
    }
    
    int x,y;
    for(i=1;i<v;i++){
        scanf("%d %d",&x,&y);
        path[x].push_back(y);
        path[y].push_back(x);
    }
    restaurant = 0;
    memset(vis,0,sizeof vis);
    
    dfs(1,cat_here[1]);
    printf("%d\n",restaurant);

    return 0;
}
