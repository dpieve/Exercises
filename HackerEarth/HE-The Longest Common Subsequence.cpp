#include <bits/stdc++.h>

using namespace std;

vector<int> A, B;

void LCS(int n, int m){

    int i, j, L[n +5][m +5];

    for(i=0; i<=n; i++){
        for(j=0; j<=m; j++){
            if(i == 0 || j == 0)
                 L[i][j] = 0;
            else if(A[i-1] == B[j-1])
                 L[i][j] = L[i-1][j-1] + 1;
            else L[i][j] = max( L[i-1][j], L[i][j-1] );
        }
    }

    int idx = L[n][m];
    int lcs[idx + 1];

    i = n; j = m;
    while(i>0 && j>0){
        if(A[i-1] == B[j-1]){
            lcs[idx-1] = A[i-1];
            i--; j--; idx--;
        }else{
            if(L[i-1][j] > L[i][j-1])
                 i--;
            else j--;
        }
    }
    for(int i=0; i<L[n][m]; i++)
        printf("%d ", lcs[i]);
    printf("\n");
    return;
}

int main() {
   
    int n, m, x;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        scanf("%d", &x);
        A.push_back(x);
    }
    for(int j=0; j<m; j++){
        scanf("%d", &x);
        B.push_back(x);
    }

    LCS(n, m);

  return 0;
}
