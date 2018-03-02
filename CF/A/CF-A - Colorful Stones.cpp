#include <bits/stdc++.h>

using namespace std;

int main(){
	
	//freopen("input.txt","r",stdin);

	string s, t;
	cin >> s;
	cin >> t;

	int pos=0;
	for(int i=0; i<t.length(); i++){
		if(t[i] == s[pos]) pos++;
	}
	printf("%d\n", pos+1);

	return 0;
}
