#include <bits/stdc++.h>
using namespace std;

#define FILE_IN freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define N 1505
#define ull unsigned long long

int k, n = 0;
char s[N], g[28];
pair< ull, ull > p[2123456];

int main () {   

    FILE_IN
    FAST_IO  

    scanf("%s", s);
    scanf("%s", g);
    scanf("%d", &k);

    for(int i = 0; s[i]; ++i){
    	int cnt = 0; 
    	ull h1 = 5181, h2 = 0;

    	for(int j = i; s[j]; ++j){
    		if(g[ s[j]-'a' ] == '0') ++cnt;
    		if(cnt > k) break;

    		h1 = h1 * 3311  + s[j];
    		h2 = h2 * 13111 + s[j];
    		p[n++] = {h1, h2};
    	}
    }
    sort(p, p+n);
    printf("%d\n", (int)(unique(p, p+n) - p));

    return 0;
}
