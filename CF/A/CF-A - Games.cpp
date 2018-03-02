#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int main(){
	
	//freopen("input.txt","r",stdin);


	int n, i, j, g, h;
	scanf("%d", &n);

	std::vector< ii > color;
	
	for(i=0; i<n; i++){
		scanf("%d %d", &h, &g);
		color.push_back( make_pair(h,g) );
	}
	
	int guest_uniform=0;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if( i!=j && color[i].first == color[j].second )
				guest_uniform++;
		
	printf("%d\n", guest_uniform);

	return 0;
}
