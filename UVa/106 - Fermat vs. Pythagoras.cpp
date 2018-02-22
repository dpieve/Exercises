#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return (b == 0) ? a: (gcd(b, a%b));
}

int main() {

    short int table[1000001]={0};
   
    ll N, ans, count;
    while(scanf("%lld", &N) == 1){
        count = 0;

        for(int i=1; i*i <= N; i++)
            for(int j=i+1; j*j <= N; j+=2)
                if(gcd(i, j) == 1){
                    // They need to be coprime (gcd == 1)
                    //Pythagorean triple
                    ll x = 2*i*j;
                    ll y = j*j - i*i;
                    ll z = i*i + j*j;

                    if(z > N) 
                        break;
                    //para achar todos os possíveis menores que N, pega os múltiplos daqueles que são primos entre si
                    // find all
                    ll mx=x, my=y, mz=z;
                    while(mz <= N){
                        table[mx] = table[my] = table[mz] = 1;
                        mx += x; my += y; mz += z;
                    }
                    count++;
                }
        ans = N;
        
        //if table[i] == 1 then it's not part of our solution
        for(ll i=1; i<=N; i++){
            ans -= table[i];
            table[i] = 0;
        }
        printf("%lld %lld\n", count, ans);
    }
  return 0;
}
