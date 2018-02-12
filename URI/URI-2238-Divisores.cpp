//https://www.urionlinejudge.com.br/judge/pt/problems/view/2238

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){

    ll a, b, c, d, ans=-1, rc;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    std::vector<ll> divisor;

    rc = sqrt(c);
    for(ll i=1; i<=rc; i++){
        if(c%i==0){
            divisor.push_back(i);
            divisor.push_back(c/i);
        }
    }
    sort(divisor.begin(), divisor.end()); // to get minimum
    
    for(int i=0; i<divisor.size(); i++){
        if(divisor[i]%a == 0 && divisor[i]%b!=0 && c%divisor[i]==0 && d%divisor[i]!=0){
            ans = divisor[i];
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
