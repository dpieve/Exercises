// URI - Caminhoes - Trucks
// Dilson Pieve - UNIFEI 2018
// https://www.urionlinejudge.com.br/judge/en/problems/view/1476

#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
const int MAX = 100001;
typedef pair<int, int> ii;

struct Edge {
	int a, b, w;
};
int cmp(const Edge& a, const Edge& b) {
	return a.w > b.w;
}

Edge edge[MAX];
vector< ii > g[MAX];

int n, m, s;

/*-----------------------------*/
int p[MAX], sz[MAX];

int find(int x) {
	return ( p[x] == x ) ? x : ( p[x] = find(p[x]) );
}

inline bool isSame(int x, int y) {
	return find(x) == find(y);
}

void Union(int x, int y) {
	x = find(x); y = find(y);
	if (x != y) {
		if (sz[x] < sz[y]) swap(x, y);
		sz[x] += sz[y];
		p[y] = x;
	}
}
void UnionInit() {
	for (int i = 0; i <= n; i++) {
		p[i] = i;
		sz[i] = 1;
	}
}
/*-----------------------------*/

int lvl[MAX], vis[MAX], parent[MAX], cost[MAX];

void DFS(int u) {
	vis[u] = 1;
	for (int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i].first;
		int w = g[u][i].second;

		if (!vis[v]) {
			cost[v] = w;
			parent[v] = u;
			lvl[v] = lvl[u] + 1;
			DFS(v);
		}
	}
}
void DfsInit() {
	for (int i = 0; i <= n; i++) {
		vis[i] = 0;
		lvl[i] = 0;
		cost[i] = 0;
		parent[i] = -1;
	}
}
/*--------------------------------------*/

int LCA(int a, int b) {
	int pp = INF;
	while (a != b) {
		if (lvl[a] > lvl[b]) {
			pp = min(pp, cost[a]);
			a = parent[a];
		}
		else {
			pp = min(pp, cost[b]);
			b = parent[b];
		}
	}
	return pp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (cin >> n >> m >> s) {
		
		for (int i = 0; i < m; i++) {
			cin >> edge[i].a >> edge[i].b >> edge[i].w;
			edge[i].a--; edge[i].b--;
		}
		sort(edge, edge + m, cmp);
		
		UnionInit();
		for (int i = 0; i < m; i++) {
			
			int a = edge[i].a;
			int b = edge[i].b;
			int w = edge[i].w;

			if (!isSame(a, b)) {
				Union(a, b);
				g[a].push_back(ii(b, w));
				g[b].push_back(ii(a, w));
			}
		}
		DfsInit();
		DFS(0);

		int a, b;
		for (int i = 0; i < s; i++) {
			cin >> a >> b;
			cout << LCA(a - 1, b - 1) << endl;
		}

		for (int i = 0; i < n; i++) g[i].clear();
	}

    return 0;
}

