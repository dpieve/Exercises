#include <bits/stdc++.h>

using namespace std;

int find(int p, int arr[]){
    int i;
    for (i = 0; i < 8; ++i)
    {
        if( p == arr[i] ){
            break;
        }
    }
    return i;
}

int main(){
    int n,m,i,constraints[20][3];
    while(scanf("%d %d",&n,&m), n || m){
        for(i=0;i<m;i++)
            scanf("%d %d %d",&constraints[i][0],&constraints[i][1],&constraints[i][2]);
        int ans=0;
        int arr[8] = {0,1,2,3,4,5,6,7};
        do{
            bool nots=true;
            for (i = 0; i < m; i++){
                int pos1 = find(constraints[i][0],arr);
                int pos2 = find(constraints[i][1],arr);

                if(constraints[i][2] < 0){
                    if(abs(pos1 - pos2) < -constraints[i][2]){
                        nots=false;
                        break;
                    }
                }
                if(constraints[i][2] > 0){
                    if(abs(pos1 - pos2) > constraints[i][2]){
                        nots=false;
                        break;
                    }
                }
            }
            if(nots) ans++;
        }while(next_permutation(arr,arr+n));
        cout << ans << '\n';
    }
    return 0;
}
