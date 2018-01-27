#include <bits/stdc++.h>

using namespace std;

int k, r;

long long int pay(int price, int min_shovel){
	if(price%10==0 || (price%10 ==r))
		 return min_shovel;
	
	else{
		min_shovel++; price+=k;
		return pay(price, min_shovel);
	}
}

int main(){

	//freopen("input.txt","r",stdin);

	scanf("%d %d", &k, &r);

	long long int ans = pay(k, 1);
	cout << ans << endl;

	return 0;
}
