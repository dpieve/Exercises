//http://codeforces.com/contest/466/problem/A
#include <bits/stdc++.h>

#define INF 100000

using namespace std;

int n, m, a, b, memo[1001];
    
int solve(int ride){
    
    if(memo[ride] != -1)
        return memo[ride];

    if(ride >= n)
        return memo[ride] = 0;

    return memo[ride] = min( b+solve(ride+m), a+solve(ride+1));

}

int main() {
 
//    freopen("input.txt", "r", stdin);

    memset(memo, -1, sizeof memo);

    cin >> n >> m >> a >> b;

    cout << solve(0) << endl;


  return 0;
}
