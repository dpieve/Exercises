#include <bits/stdc++.h>

using namespace std;

int main(){

	//freopen("input.txt","r",stdin);

	string name;
	cin >> name;

	int rot=0; char atual = 'a';

	for(int i=0; i<name.size(); i++){
		if(abs(name[i]-atual) <= 13){
			rot = rot + abs(name[i]-atual);
			atual=name[i];
		}else{
			if(name[i]-atual > 13){
				rot = rot + (atual-'a') +1;
				atual='z';
				rot = rot + (atual-name[i]);
				atual=name[i];
			}else{
				rot = rot + ('z'-atual) +1;
				atual='a';
				rot = rot + (name[i]-atual);
				atual=name[i];
			}
		}
	}
	printf("%d\n",rot);

	return 0;
}
