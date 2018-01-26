#include <bits/stdc++.h>

using namespace std;

int main(){

	//freopen("input.txt", "r", stdin);

	int n, igual=0;
	scanf("%d", &n); getchar();

	char c;
	std::vector<char> v;
	for(int i=1; i<=n; i++){
		scanf("%c",&c);
		if(v.size()==0 || v.back() != c)
			 v.push_back(c);
		else igual++;
	}
	printf("%d\n",igual);


	/* or
	int n;    cin >> n;
	string s; cin >> s;

	int i, iguais=0;
	std::vector<char> v;
	for(i=0;i<n;i++){
		if(v.size()==0 || v.back() != s[i])
			v.push_back( s[i] );
		else iguais++;
	}
	printf("%d\n", iguais);
	*/
  
	return 0;
}
