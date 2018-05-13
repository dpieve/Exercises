//#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <set>
#include <utility>
#include <memory.h>
#include <stack>

#define MAX 1005

using namespace std;

int n, m, k, x, y;
vector< int > g[MAX];

int main() {

	int F[MAX], mark[MAX];

	while (cin >> n >> m >> k) {

		memset(F, 0, sizeof F);
		memset(mark, 0, sizeof mark);

		while (m--) {
			cin >> x >> y;

			g[x].push_back(y);
			g[y].push_back(x);

			F[x]++; F[y]++;
		}

		queue<int> q;
		
		// if he has < k friends
		for(int v = 1; v <= n; v++){
			if (F[v] < k) {
				mark[v] = 1; // mark as visited
				q.push(v);
			}
		}

		// BFS with all elems marked
		while (!q.empty()) {
			int u = q.front(); q.pop();

			for (auto v : g[u]) {
				if (!mark[v] && --F[v] < k) {
					q.push(v);
					mark[v] = 1;
				}
			}

		}

		// all elems with < k friends will be marked
		// ans now is just elems not visited

		vector<int> output;
		for (int i = 1; i <= n; i++) {
			if (!mark[i]) output.push_back(i);
		}

		if (!output.empty()) {
			cout << output[0];
			for (int j = 1; j < output.size(); j++)
				cout << " " << output[j];
			cout << endl;
		}
		else cout << 0 << endl;

		for (int i = 1; i <= n; i++)
			g[i].clear();


	}

	return 0;
}

