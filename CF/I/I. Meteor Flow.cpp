CodeForces - 100247 I 
http://codeforces.com/gym/100247/problem/I

#include <bits/stdc++.h>

using namespace std;

#define MAX 200003
#define ll long long int

int n, t[MAX], d[MAX];

int main(){

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &t[i], &d[i]);

	priority_queue<int> q;

	ll damage = 0; int shot = 0;
	for(int i = 0; i < n; i++){
		q.push(d[i]);
		damage += d[i];

		while(t[i]==t[i+1] && i<n-1){
			i++;
			q.push(d[i]);
			damage+=d[i];
		}
    
    // if you need to use a shot, use with the one who has the most damage
    // then the number of shot will be minimum - this is the answer
    
		int top;
		while(damage > t[i] && !q.empty()){
			top = q.top(); q.pop();
			damage -= top;
			shot++;
		}
	}

	printf("%d\n", shot);

   return 0;
}
