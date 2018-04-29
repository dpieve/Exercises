//http://codeforces.com/problemset/problem/344/D
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001
#define ll long long int

int transform(int pos, char comp){
	if(pos&1){
		if(comp == '-')
			return 1;
		else return 0;
	}
	else{
		if(comp == '-')
			return 0;
		else return 1;
	}
}

int main(){

	string s;
	cin >> s;

	int A = 0, B = 0;
	for(int i = 0; i < s.size(); i++){
		if(transform(i, s[i]) == 1) B++;
		else A++;
	}

	if(A == B)
		cout << "Yes" << endl;
	else cout << "No" << endl;
	
   return 0;
}
