#include <bits/stdc++.h>

using namespace std;

const string trad = "abcdefghijklmnopqrstuvwxyz";

int T; 
string M, sentence;

int main(){

	cin >> T >> M;
	map<char, char> translate;

	for(int i = 0; i < M.size(); i++){
		translate[ trad[i] ] = M[i];
		translate[ toupper(trad[i]) ] = toupper(M[i]);
	}
	translate['_'] = ' '; translate['.'] = '.';
	translate[','] = ','; translate['!'] = '!'; translate['?'] = '?';

	for(int i = 0; i < T; i++){
		cin >> sentence;

		string out = "";
		for(int i = 0; i < sentence.size(); i++){
			out += translate[ sentence[i] ];
		}
		cout << out << endl;
	} 


   return 0;
}
