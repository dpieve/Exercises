#include <bits/stdc++.h>

using namespace std;

int main(){
	
	//freopen("input.txt","r",stdin);

	int n,x;
	scanf("%d",&n);

	std::vector<int> v;
	for(int i=0; i<n; i++){
		scanf("%d", &x);

		if( v.size()==0 || v.back()<0 ){
			v.push_back(x);
		}
		else{
			if(v.back() >0){
				int q = x + v.back();
				v.pop_back();
				v.push_back(q);
			}else{
				v.push_back(x);
			}
		}
	}
	int sum=0, tmn=v.size();
	for(int i=0; i<tmn; i++)
		if(v[i]<0)
			sum+= abs(v[i]);

	printf("%d\n",sum);

	return 0;
}
