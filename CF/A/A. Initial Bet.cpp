//http://codeforces.com/problemset/problem/478/A

#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define MAXN 100000
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){

    //freopen("input.txt", "r", stdin);

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    if( (a+b+c+d+e)%5 != 0 || (a+b+c+d+e)==0)
        cout << "-1" << endl;
    else cout << (a+b+c+d+e)/5 << endl;

    return 0;
}
