//https://www.hackerrank.com/challenges/big-sorting/problem
#include <bits/stdc++.h>

using namespace std;

bool sorting(string s1, string s2){
	int t1 = s1.length();   //you can use .size();
	int t2 = s2.length();

	if(t1 == t2)
		return (s1<s2);

	return (t1<t2);
}
int main(){

	int n;
	cin >> n;

	std::vector<string> s(n);

	for(int i=0; i<n; i++)
		cin >> s[i];

	sort(s.begin(),s.end(), sorting);

	for(int i=0; i<n; i++)
		cout << s[i] << endl;

	return 0;
}
