// https://codeforces.com/contest/877/problem/E
// Euler Tour + Lazy

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 212345;

vector <int> g[MAXN];

int n, p[MAXN], a[MAXN];
int tin[MAXN], tout[MAXN], timer;

void dfs (int u) {
	tin[u] = ++timer;
	for (int v : g[u]) dfs (v);
	tout[u]= timer;
}

int t[4 * MAXN], lz[4 * MAXN];

void build (int i, int l, int r) {
	if (l == r) t[i] = a[l];
	else {
		int m = (l + r) / 2;
		build (2*i, l, m);
		build (2*i + 1, m + 1, r);
		t[i] = t[2*i] + t[2*i + 1];
	}
}


void push (int i, int l, int r) {
	if (lz[i]) {
		t[i] = (r - l + 1) - t[i];
		if (l < r) {
			lz[2*i] ^= 1;
			lz[2*i + 1] ^= 1;
		}
		lz[i] = 0;
	}
}

int ask (int i, int l, int r, int ql, int qr) {
	push (i, l, r);
	if (ql <= l && r <= qr) return t[i];
	if (r < ql || qr < l)   return 0;

	int m = (l + r) / 2;
	return ask (2*i,         l, m, ql, qr) +
		   ask (2*i + 1, m + 1, r, ql, qr);
}

void upd (int i, int l, int r, int ql, int qr) {
	push (i, l, r);

	if (r < ql || qr < l)   
		return;
	
	if (ql <= l && r <= qr) {
		lz[i] ^= 1;
		push(i, l, r);
		return;
	}

	int m = (l + r) / 2;

	upd (2*i,         l, m, ql, qr);
	upd (2*i + 1, m + 1, r, ql, qr);
	
	t[i] = t[2*i] + t[2*i + 1];
}

int main () {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;

	for (int i = 2; i <= n; ++i) {
		cin >> p[i];
		g[p[i]].push_back(i);
	}

	dfs (1);

	for (int i = 1; i <= n; ++i) cin >> a[tin[i]];

	build (1, 1, n);

	int q;
	cin >> q;

	while (q--) {
		int v;
		string op;
		cin >> op >> v;

		if (op == "get") {
			cout << ask (1, 1, n, tin[v], tout[v]) << '\n';
		}
		else {
			upd (1, 1, n, tin[v], tout[v]);
		}

	}


	return 0;
}
