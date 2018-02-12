//Pangrams are sentences constructed by using EVERY letter of the alphabet at least once.

#include <bits/stdc++.h>

using namespace std;

int main(){
	
	//freopen("input.txt","r",stdin);

	char c;
	string s;
	getline(cin,s);

	map<char,int> m;
	for(int i=0;i<s.size();i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			c = tolower(s[i]);
			m[c] = 1;
		}
		else{ 
			if(s[i] >= 'a' && s[i] <= 'z'){
				c = s[i];
				m[c] = 1;
			}
		}
	}
	bool ok = true;
	for(char i='a';i<='z';i++)
		if(m.count(i) == 0)
			ok=false;
		
	if(ok) cout << "pangram"     << '\n';
	else   cout << "not pangram" << '\n'; 
	return 0;
		
}
