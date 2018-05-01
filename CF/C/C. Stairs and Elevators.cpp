//http://codeforces.com/contest/967/problem/C
#include <bits/stdc++.h>

using namespace std;

#define INF 999999999
#define ll long long int


int main(){

	    ll floors,   sections,   n_stairs,   n_elevators,   v;
	cin >> floors >> sections >> n_stairs >> n_elevators >> v;

	std::vector< ll > stairs(n_stairs), elevators(n_elevators);

	for(int i = 0; i < n_stairs; i++){
		cin >> stairs[i];
		stairs[i]--;
	}
	for(int i = 0; i < n_elevators; i++){
		cin >> elevators[i];
		elevators[i]--;
	}
	
	ll q, x1, y1, x2, y2; 
	cin >> q;

	while(q--){
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		x1--; x2--; y1--; y2--;

		ll ans = 1e18;

		if(x1 == x2) ans = abs(y2 - y1);

		if(n_stairs != 0){
			auto  it1 = lower_bound(stairs.begin(), stairs.end(), y1);
			
			if(it1 != stairs.begin()){
				ll use = *(it1-1);
				ll d   = abs(use-y1)+abs(x2-x1)+abs(use-y2);
				ans = min(ans, d);
			}
			if(it1 != stairs.end()){
				ll use = *(it1);
				ll d   = abs(use-y1)+abs(x2-x1)+abs(use-y2);
				ans = min(ans, d);
			}
		}

		if(n_elevators != 0){
			auto  it1 = lower_bound(elevators.begin(), elevators.end(), y1);
			
			if(it1 != elevators.begin()){
				ll use = *(it1-1);
				ll d   = abs(use-y1)+(abs(x2-x1)+v-1)/v+abs(use-y2);
				ans = min(ans, d);
			}
			if(it1 != elevators.end()){
				ll use = *(it1);
				ll d   = abs(use-y1)+(abs(x2-x1)+v-1)/v+abs(use-y2);
				ans = min(ans, d);
			}
		}
		cout << ans << endl;
	}
	


   return 0;
}
