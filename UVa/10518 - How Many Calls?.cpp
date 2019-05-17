// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1459&mosmsg=Submission+received+with+ID+23349368
// UVa 10518  How Many Calls Solution

#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

ll n, mod;

struct matrix {
	ll mat[5][5];
	matrix () {  memset (mat, 0, sizeof mat); }

	matrix operator * (const matrix& b) {
		matrix a;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					a.mat[i][j]=((a.mat[i][j])+(((mat[i][k]%mod)*(b.mat[k][j]%mod))%mod));
					// a.mat[i][j] += ( mat[i][k] * b.mat[k][j] );
				}	
			}
		}
		return a;
	}

	/*
	void print () {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				printf ("%d ", mat[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	*/
};


matrix fexp (matrix b, ll e) {
	if (e == 1) return b;
	if (e & 1) return b * fexp (b, e - 1);
	matrix aux = fexp (b, e / 2);
	return (aux * aux);
}

ll solve () {

	if (n == 0) return 1 % mod;
	if (n == 1) return 1 % mod;

	matrix fib;

	fib.mat[0][0] = 1;
	fib.mat[0][1] = 1;
	fib.mat[1][0] = 1;
	fib.mat[1][1] = 0;
	
	matrix x;
	x.mat[0][0] = 1; // fib 1 = 1
	x.mat[0][1] = 0; // fib 0 = 0

	matrix mult = fexp (fib, n + 1);
	
	// printf("%lld -> %lld\n", n, mult.mat[1][0]);
	// mult.print();

	ll resp = (mult.mat[1][0] * 2 - 1 + mod) % mod;

	return resp;
}


int main () {

	int cc = 1;
	while (scanf("%lld %lld", &n, &mod), (n || mod)) {	
		ll resp = solve ();
		printf("Case %d: %lld %lld %lld\n", cc++, n, mod, resp);
	}
	

	return 0;
}
