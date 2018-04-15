#include <bits/stdc++.h>

#define LL long long int
#define BitTst(arg,bit) ((arg) & (1<<bit))

using namespace std;

int main(){

    LL x;
    cin >> x;

    int count = 0;
    
    for(int i = 0; i < 32; i++){
        if(BitTst(x,i))
            count++;
    }
    cout << count << endl;
    
    return 0;
}
