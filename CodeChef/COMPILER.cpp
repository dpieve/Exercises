//https://www.codechef.com/MAY14/problems/COMPILER
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001
#define ll long long int

int t;
string s;

int main(){

	cin >> t;
	while(t--){
		cin >> s;

		int op = 0, out = 0;
		
		for(int i = 0; i < (int)s.size(); i++){
			if(s[i] == '<') 
				 op++; 
			else op--;

			if(op == 0) out = i+1;
			else if(op < 0) break;
		}
	
		cout << out << endl;

	}


   return 0;
}
