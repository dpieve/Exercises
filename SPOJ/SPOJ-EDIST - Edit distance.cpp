#include <bits/stdc++.h>

using namespace std;

int smaller(int a, int b, int c){
    return min( min(a,b), c);
}

string a, b;
int dp[2050][2050];

int edit_dist(int i, int j){
    
    if(dp[i][j] != -1) return dp[i][j];

    if(i == 0) return j;
    if(j == 0) return i;

    //iguais
    if(a[i-1] == b[j-1])
        return dp[i][j] = edit_dist(i-1, j-1);

    //min between replace, insert, remove
    return dp[i][j] = (1 + smaller( edit_dist(i-1, j-1), edit_dist(i-1, j), edit_dist(i, j-1)));

}

int main(){
 
    int t;
    scanf("%d", &t);

    while(t--){
        memset(dp, -1, sizeof dp);

        cin >> a >> b;

        int x = a.length(); 
        int y = b.length();

        printf("%d\n", edit_dist(x, y));
    }

   return 0;
}
