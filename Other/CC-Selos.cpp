#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long int x){
    if(x == 1)
        return true;

    for(long long int i=2; i*i <= x; i++)
        if(x%i == 0)
            return false;

    return true;
}
int main(){

    long long int x;
    scanf("%lld", &x);

    cout << (isPrime(x)?'N':'S') << endl;

    return 0;
}
