//#include "stdafx.h"

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define scanf scanf_s
#endif

#define MAX 112345
#define LL double
#define watch(x) cout << (#x) << " is " << x << endl

struct Point {
	LL x, y;
	Point(LL _x, LL _y): x{_x}, y{_y} {}
};

LL dist(Point a, Point b) {
	return ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

LL L, C, R1, R2;
bool two_cylinders(Point& p1, Point& p2) { 
	return ( (dist(p1, p2) >= (R1 + R2)*(R1 + R2)) && (min(L, C) >= 2 * max(R1, R2)) ); 
}

int main() {

	while (scanf("%lf %lf %lf %lf", &L, &C, &R1, &R2), L, C, R1, R2) {
		if (R1 > R2) swap(R1, R2);
		Point p1{ C - R1, L - R1 }, p2{ R2, R2 };
		printf("%c\n", two_cylinders(p1, p2) ? 'S' : 'N');
	}
	return 0;
}
