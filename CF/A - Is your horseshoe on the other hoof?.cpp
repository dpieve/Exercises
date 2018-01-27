#include <bits/stdc++.h>

using namespace std;

int main(){

	int i, j, cont=0, fake=-1;
	long long int a[5];

	for(i=0; i<4; i++){
		cin >> a[i];
		for(j=0; j<i; j++)
			if(a[i] == a[j]){
				a[j]=fake;  // mark as visited
				fake--;
				cont++;
			}
	}	
	cout << cont << endl;
	return 0;
}
