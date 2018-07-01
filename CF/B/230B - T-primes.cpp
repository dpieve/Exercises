#include <bits/stdc++.h>
using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    #define ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
}

#define ll long long
#define MAX 1000001

set< ll > ss;
bool prime[MAX + 100];

void calc(){

    memset(prime, true, sizeof prime);

    for(ll p = 2; p*p <= MAX; ++p){
        if(prime[p]){ 
            for(ll i = p*2; i <= MAX; i +=p ){
                prime[i] = false;
            }
        }
    }

    for(ll p=2; p <= MAX; ++p)
        if(prime[p]) ss.insert(p*p);

}

template<typename T>
bool contains(const std::set<T>& a, const T& elem){
    return ( a.find(elem) != a.end() ) ;
}

int main(){


   // init();

    calc();

    ll n, x;

    cin >> n;

    while(n--){
        cin >> x;
        if(contains(ss, x)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}

