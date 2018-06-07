
#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define scanf scanf_s
#endif


const int MAX = 700;

int N, T, D[MAX], P[MAX], dp[MAX][MAX];

int solve(int idx, int time) {
	//if (time < 0) return -1000000;
	if (time == 0 || idx == 0) return 0;

	int &p = dp[idx][time];
	if (p + 1) return p;

	int do_not = solve(idx - 1, time);

	if (time >= D[idx]) {
		int do_it = solve(idx, time - D[idx]) + P[idx];
		return p = max(do_it, do_not);
	}

	return p = do_not;
}



int main(){

	int H = 1; //bool first = true;
	while (scanf("%d %d", &N, &T), N) {
		//if (!first) puts(""); else first = false;
		
		for (int i = 1; i <= N; i++) {
			scanf("%d %d", &D[i], &P[i]);
		}

		memset(dp, -1, sizeof dp);
		int ans = solve(N, T);

		printf("Instancia %d\n", H++);
		printf("%d\n\n", ans);
	}
    return 0;
}

