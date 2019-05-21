// URI Maratona Mineira 2018 Palindromo 
// https://www.urionlinejudge.com.br/judge/en/problems/view/2795

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
const int INF = 0x3f3f3f3f;

string s;
int n, K, dp[MAXN][MAXN], m[MAXN][MAXN];

int calc (int start, int end) {
	
	int cnt = 0;
	
	while (start <= end) {
		char x = s[start];
		char y = s[end];

		if (x > y) swap (x, y);

		int p = y - x;
		int q = ('z' - y) + 1 + (x - 'a');

		cnt += min (p, q);

		start++; end--;
	}

	return cnt;

}

void build () {
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			m[i][j] = calc (i, j);
		}
	}
	memset(dp, -1, sizeof dp);
}

int solve (int i, int k) {

	if (i >= n) return 0;
	if (k == 1) return m[i][n-1];

	int &p = dp[i][k];
	if (p + 1) return p;

	p = INF;

	for (int j = i; j < n; ++j) p = min(p, m[i][j] + solve (j + 1, k - 1));
	
	return p;
}



int main () {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> K >> s; 

	build ();

	cout << solve (0, K) << '\n';


	return 0;
}
