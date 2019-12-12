//https://www.codechef.com/problems/LEPERMUT

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int inversions(int A[], int n){
    int i, j, n_inversions = 0;

    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if(A[i] > A[j])
                n_inversions++;

    return n_inversions;
}

int local_insersions(int A[], int n){
    int i, local = 0;

    for(i=1; i<n; i++)
        if(A[i-1] > A[i])
            local++;

    return local;
}

int main() {

    int t, n, A[105];

    scanf("%d", &t);
    while(t--){

        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d", &A[i]);
        
        if( inversions(A, n) == local_insersions(A, n) )
            printf("YES\n");
        else printf("NO\n");


    }



  return 0;
}
