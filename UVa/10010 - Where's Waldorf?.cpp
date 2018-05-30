#include "stdafx.h"

#include <bits/stdc++.h>
using namespace std;

int m, n, sz;
string grid[51], word;

const int row[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
const int col[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

inline bool isOut(int r, int c) {
	return ( (r < 0) || (r >= m) || (c < 0) || (c >= n) );
}
inline bool comp(char a, char b) {
	return ( toupper(a) == toupper(b) );
}

bool solve2(int r, int c, int p, int a1, int a2) {

	if (p == sz)
		return true;

	if (isOut(r, c)) 
		return false;

	if (comp(grid[r][c], word[p])) {
		if (solve2(r + a1, c + a2, p + 1, a1, a2)) 
			return true;	
	}
	return false;
}
bool solve(int r, int c, int p) {

	if (p == sz)
		return true;

	if (isOut(r, c))
		return false;

	if (comp(grid[r][c], word[p])) {
		for (int i = 0; i < 8; i++) {
			if (solve2(r + row[i], c + col[i], p + 1, row[i], col[i]))
				return true;
		}
	}
	return false;
}


int main() {


	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int t, k;
	cin >> t;

	bool first = true;

	while (t--) {		
		if (!first) cout << endl; else first = false;
		cin >> m >> n;

		for (int i = 0; i < m; i++) {
			cin >> grid[i];
		}
		cin >> k;
		while(k--) {
			cin >> word;
			sz = word.size();

			if (n == 1 && m == 1) {
				cout << 1 << ' ' << 1 << endl;
				continue;
			}

			int s = -1, e = -1;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (comp(word[0], grid[i][j]) && solve(i, j, 0)) {
						s = i + 1; e = j + 1;
						break;
					}
				}
				if (s > 0 && e > 0) break;
			}
			cout << s << ' ' << e << endl;
		}
	}


	return 0;
}
