#include <bits/stdc++.h>

/* Matrix
n is the number of rows/columns of the matrix
Problem's solution with this operations:
i == j           diagonal
i < j            above main diagonal
i > j            below main diagonal
i+j == n-1       secondary diagonal
i+j < n-1        above secondary diagonal
i+j > n-1        below secondary diagonal
*/

using namespace std;

int main(){
 
    string s;

    int i, j;
    double x, sum=0;

    cin >> s;
    for(i=0; i<12; i++)
        for(j=0; j<12; j++){
            cin >> x;
            if(i+j>11)
                sum += x;
        }

    if(s[0] == 'M')
        printf("%.1lf\n", sum/66.0);
    else printf("%.1lf\n", sum);
    return 0;
}
