//http://codeforces.com/problemset/problem/540/C

#include <bits/stdc++.h>

using namespace std;

char cave[505][505];

int n, m, r1, c1, r2, c2, ans;

void DFS(int r, int c){
  if(cave[r][c] == 'X'){
    if((r == r2) && (c == c2))
      ans = 1;
  }
  else{
    if((r >= 1) && (r <= n) && (c >= 1) && (c <= m)){
      cave[r][c] = 'X';
      DFS(r+1, c); DFS(r-1, c);
      DFS(r, c-1); DFS(r, c+1);
    }
  }
}

int main() {
 
//  freopen("input.txt", "r", stdin);

  ans = 0;
  cin >> n >> m;

  for(int i=1; i<=n; i++)
  for(int j=1; j<=m; j++)
    cin >> cave[i][j];

  cin >> r1 >> c1;
  cin >> r2 >> c2;

  cave[r1][c1] = '.';
  DFS(r1, c1);

  cout << ( (ans == 1) ? ("YES"):("NO") ) << endl;

  return 0;
}
