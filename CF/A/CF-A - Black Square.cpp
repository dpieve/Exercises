#include <bits/stdc++.h>

using namespace std;

int main(){
	
	//freopen("input.txt","r",stdin);

	int a[6];

	for(int i=1; i<=4; i++)
		scanf("%d",&a[i]);

	string n;
	cin >> n;

	string::size_type sz;

	long long int sum =0;
	for(int i=0; i<n.size(); i++){
		int pos  = n[i]-'0';
		sum += a[pos];
	}

	printf("%lld\n", sum);
	

	return 0;
}
