// I used deque to implement the game the way it was
// http://codeforces.com/contest/381/problem/A

#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, x;
	deque<int> cards;

	scanf("%d", &n);
  
  //READ
	for(int i=0; i<n; i++){
		scanf("%d", &x);
		cards.push_back(x);
	}

	int S=0, D=0;
	bool she = true;  //She starts
	while(!cards.empty()){
		int first = cards.front();
		int last  = cards.back();

		if(she){
			if(first > last){
				S += first;
				cards.pop_front();
			}else{
				S += last;
				cards.pop_back();
			}
			she = false; // Dima now!
		}else{
			if(first > last){
				D += first;
				cards.pop_front();
			}else{
				D += last;
				cards.pop_back();
			}
			she = true; //Sereja now!
		}	
	}

	printf("%d %d\n", S, D);
	return 0;
}
