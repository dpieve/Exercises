#include <bits/stdc++.h>

using namespace std;

struct cmp
{
    bool operator()(const int &a, const int &b){
        return (a>b);
    }
};

int main() {
   
    int n, x, y, start;
    
    scanf("%d", &n);

    start  = n;

    set<int, cmp> snacks;
    set<int, cmp>::iterator it;

    for(int i=0; i<n; i++){
        scanf("%d", &x);
        snacks.insert(x);

        if(x == start){
            while(!snacks.empty()){
                start--;   
                y = *snacks.begin();
                cout << y << " ";
                snacks.erase(snacks.begin());

                if(y != *snacks.begin() +1)
                    break;
            }
        }
            

        printf("\n");
    }
  return 0;
}
