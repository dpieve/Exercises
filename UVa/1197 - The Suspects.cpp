#include <stdio.h>

using namespace std;

int parent[30005];

int find(int x){
    if(parent[x] == x)
        return x;
    else return parent[x] = find(parent[x]);
}
int main(){

    int n,m,i,j;
    while(scanf("%d %d",&n,&m)==2 && (n || m)){
        for(i=0;i<30005;i++) parent[i]=i;

        int k,p,q,x,first;
        for(i=0;i<m;i++){
            scanf("%d",&k);
            scanf("%d",&first);
            for(j=1;j<k;j++){
                scanf("%d",&x);
                p = find(x);
                q = find(first);
                parent[p] = q;
            }
        }
        int suspect=0;
        for(i=0;i<30000;i++)
            if(find(0) == find(i))
                suspect++;
        printf("%d\n",suspect);

    }

  return 0;
}
