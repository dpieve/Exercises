#include <bits/stdc++.h>

using namespace std;

#define MAX 1123456789
#define ll long long int

int main(){

    ll N, B, H, W, P, beds;

    while(cin >> N >> B >> H >> W){

        ll low_price = MAX;

        for(int i = 0; i < H; i++){
            
            cin >> P;
            bool available = false;
            for(int j = 0; j < W; j++){
                cin >> beds;

                if(beds >= N)
                    available = true;

            }
            if(available && P < low_price && B >= P*N){
                low_price = P;
            }

        }

        if(low_price == MAX)
            cout << "stay home" << endl;
        else cout << N*low_price << endl;

    }

   return 0;
}
