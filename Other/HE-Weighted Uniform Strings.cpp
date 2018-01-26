#include <bits/stdc++.h>

using namespace std;

int main(){
	
	//freopen("input.txt","r",stdin);

	string S; cin >> S;

	bool reach[10000010];

	int val=0;
	for(int i=0; i<S.size(); i++){
		if(i>0 && S[i]!=S[i-1])
			val=0;
		val += (S[i]-'a'+1);
		reach[val] = true;
	}

	int x, N; cin >> N;
	for(int i=0; i<N; i++){
		scanf("%d",&x);
		if(reach[x]) cout << "Yes";
		else         cout << "No";
		puts("");
	}
	return 0;
		
}
