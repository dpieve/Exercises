/* Dilson Pieve - UNIFEI 2018 */

#include <bits/stdc++.h>
using namespace std;

#define WATER '.'
#define LAND  '*'
const int MAX = 55;
typedef pair<int,int> ii;

/*------------------------------------------------------------------*/
void init(){	
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt","w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
}
/*------------------------------------------------------------------*/

struct grid{
	string s[MAX];
	grid(){}
};

grid g;
int N, M, K, vis[MAX][MAX];
vector< pair<int,ii> > lakes;

inline bool isOut(int x, int y){
	return (x < 0 || y < 0 || x >= N || y >= M || g.s[x][y] == LAND || vis[x][y]==1);
}
void solve(int x, int y){
	if(isOut(x, y))
		return;
	vis[x][y] = 1;
	g.s[x][y] = LAND;

	solve(x+1, y);
	solve(x-1, y);
	solve(x, y-1);
	solve(x, y+1);
}
int mark(int x, int y){
	if(isOut(x, y)) 
		return 0;
	
	int cnt = 1;
	vis[x][y] = 1;
	cnt += mark(x+1, y); 
	cnt += mark(x-1, y);
	cnt += mark(x, y+1); 
	cnt += mark(x, y-1);
	return cnt;
}

inline void mark_all(){
	for(int i = 0; i < N; i++){
		if(!vis[i][0] && g.s[i][0] == WATER){
			mark(i,0);
		}
		if(!vis[i][M-1] && g.s[i][M-1] == WATER){
			mark(i,M-1);
		}
	}
	for(int j = 0; j < M; j++){
		if(!vis[0][j] && g.s[0][j] == WATER){
			mark(0,j);
		}
		if(!vis[N-1][j] && g.s[N-1][j] == WATER){
			mark(N-1, j);
		}
	}
}
int main()
{
	
	init();

	cin >> N >> M >> K;
	for(int i = 0; i < N; i++){
		cin >> g.s[i];
	}

	memset(vis, 0, sizeof vis);

	mark_all(); /*mark ocean as visited*/

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(g.s[i][j] == WATER && !vis[i][j]){
				int cc = mark(i, j); /* count lakes */
				lakes.push_back({cc,{i,j}});
			}
		}
	}

	memset(vis, 0, sizeof vis);
	sort(lakes.begin(), lakes.end());

	int n_lakes = 0;

	for(int i = 0, u, v, w; i < (int)lakes.size() - K; i++){
		w = lakes[i].first;
		u = lakes[i].second.first;
		v = lakes[i].second.second;
    
    /*transform WATER to LAND*/
		n_lakes += w; solve(u, v);
	}
	cout << n_lakes << endl;
  
	for(int i = 0; i < N; i++){
		cout << g.s[i] << endl;
	}
	return (0);
}

