//http://www.codcad.com/problem/70
// If number is divisible by 4, 9 and 25

#include <bits/stdc++.h>

using namespace std;

int main(){

    string s; cin >> s;
    long long int v=0, k=s.length();

    int af=0,f;         //make sure 0 is divisible by 4, 9 and 9
    for(long long int i=0; i<k; i++){
        v += (s[i]-'0');

        if(i == k-2 && k-2 >=0)
            af = s[i]-'0';
        if(i == k-1)
            f  = s[i]-'0';
    }

    int last_digits = af*10 + f; // ajust second digit
    if((last_digits %4 == 0) || (f==0 && af ==0))
        printf("S\n"); else printf("N\n");

    if(v%9 == 0)
        printf("S\n"); else printf("N\n");

    if(f == 0 && (af == 0 || af == 5))
         printf("S\n");
    else if(f == 5 && (af == 2 || af == 7))
         printf("S\n"); else printf("N\n");


    return 0;
}
