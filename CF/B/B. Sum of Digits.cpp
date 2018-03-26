//http://codeforces.com/contest/102/problem/B

// SUM OF ALL DIGITS ( N <= 10^100000 )

#include <bits/stdc++.h>

#define LL long long int

using namespace std;

LL sum(LL n){

    LL tmp = 0;
    while(n != 0){
        tmp += n%10; 
        n = n/10;
    }

    return tmp;
}

int main(){

    string initial;
    cin >> initial;

    LL n = 0;

    int final = 0;
    
    if(initial.size() > 1){

        final++;
        
        //Num of digits are large just untill first sum digits;

        for(int i = 0; i < (int)initial.size(); i++)
            n += initial[i] - '0'; 

        while(n >= 10){
            n = sum(n);

            final++;
        }
        
    }

    cout << final << endl;

    return 0;
}
