// URI 2800 Brincando de Consultas
// II Maratona de Programação do Norte

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

const int MAXN = 100010;

ordered_set elem_pos[MAXN];
int N, Q, A[MAXN], pos_elem[MAXN];

int main() {
	
	cin >> N >> Q;

	for(int i = 0; i < N; ++i) {
		cin >> A[i];
		elem_pos[A[i]].insert(i);
		pos_elem[i] = A[i];
	}

	while(Q--) {
		int op;
		cin >> op;

		if (op == 1) {  // update A[x] = W
			
			int X, W;
			cin >> X >> W;
			--X;

			int now = pos_elem[X];
			elem_pos[now].erase(X);

			pos_elem[X] = W;
			elem_pos[W].insert(X);

		}	
		else {			// query min_qt elem [X,Y] - W
			
			int X, Y, W;
			cin >> X >> Y >> W;
			--X; --Y;

			int L = elem_pos[W].order_of_key(X);
			int R = elem_pos[W].order_of_key(Y + 1);

			int T = Y - X + 1;
			int ans = T - (R - L);
			cout << ans << '\n';

		}
	}


	return 0;	
}
