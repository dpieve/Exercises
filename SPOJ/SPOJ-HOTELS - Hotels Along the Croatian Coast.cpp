// We want to buy a sequence of consecutive hotels, 
//such that the sum of the values of these consecutive, but not greater than m

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    
    ll n, m;
    scanf("%lld %lld", &n, &m);

    ll a[n +1]; a[n]=0;  // because I'll use i->n
    for(ll i=0; i<n; i++)
        scanf("%lld", &a[i]);

    ll start=0, temp=a[0], best=a[0];
    for(ll i=1; i<=n; i++){
        //if sum>m then we remove the element 'a[start]', this way we will keep the 'best' (sum<=m).
        while( (temp>m) && (start<i-1) )
        {
            temp -= a[start];
            start++;
        }

        best  = max(best, temp);
        temp += a[i];
    }
    printf("%lld\n", best);
    return 0;
}
