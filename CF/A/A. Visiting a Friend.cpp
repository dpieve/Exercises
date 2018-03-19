//http://codeforces.com/contest/902/problem/A

#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
private:
    int p[105];
public:
    UnionFind(){
        for(int i=0; i<=101; i++)
            p[i] = i;
    }

    int Find(int x){        
        return (p[x] == x) ? x : (p[x] = Find(p[x]));
    }

    bool isSameSet(int i, int j){
        return (Find(i) == Find(j));
    }

    void UnionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = Find(i);
            int y = Find(j);

            p[x] = y;
        }
    }

};

int main() {

    //freopen("input.txt", "r", stdin);

    int n, m, a, b;
    cin >> n >> m;

    UnionFind UF;

    for(int i=0; i<n; i++){
        cin >> a >> b;

        for(int j=a; j<=b; j++)
            UF.UnionSet(a, j);
    }

    if(UF.isSameSet(0, m))
        cout << "YES" << endl;
    else cout << "NO" << endl;

  return 0;
}
