//Costa
//(OBI 2012, Fase 2, Nível 1)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1050;


int M, N;
string T[MAX];

bool is_costa(int i, int j){
    if( ( (i+1)>=M ) || ( (i-1)<0 ) )
        return true;
    if( ( (j+1)>=N ) || ( (j-1)<0 ) )
        return true;

    return ( (T[i-1][j] == '.') || (T[i+1][j] == '.') || (T[i][j+1] == '.') || (T[i][j-1] == '.'));
}

int main(){

    scanf("%d %d", &N, &M);

    getchar();

    for(int i=0; i<M; i++)
        getline(cin, T[i]);

    int costa=0;
    for(int i=0; i<M; i++){
        for(int j=0; j<T[i].size(); j++)
            if((T[i][j]=='#') && is_costa(i, j))
                costa++;
    }
    printf("%d\n", costa);
    return 0;
}
