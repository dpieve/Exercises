//@pieve
//https://www.urionlinejudge.com.br/judge/en/problems/view/1767

#include <bits/stdc++.h>

using namespace std;

int t, n, w[100], qt[100], dp1[100], dp2[100], dp3[100];

int main () {

	scanf("%d", &t);

	while (t--) {

		scanf("%d", &n);

		for (int i = 0; i < n; ++i) scanf("%d %d", &qt[i], &w[i]);

		memset(dp1, 0, sizeof dp1);
		memset(dp2, 0, sizeof dp2);
		memset(dp3, 0, sizeof dp3);

		for (int i = 0; i < n; ++i) {
			for (int j = 50; j >= w[i]; j--) {

				if (dp1[j] < qt[i] + dp1[j - w[i]]) {
					dp1[j] = qt[i] + dp1[j - w[i]];
					dp3[j] = w[i]  + dp3[j - w[i]];
					dp2[j] = 1 + dp2[j - w[i]];
				}

			}
		}
		printf("%d brinquedos\n", dp1[50]);
		printf("Peso: %d kg\n", dp3[50]);
		printf("sobra(m) %d pacote(s)\n\n", n - dp2[50]);
		
	}


	return 0;
}
