#include <bits/stdc++.h>

using namespace std;

#define ll long long int

bool checkValue(int a, int b){

    map<int, int> m;

    while(a){
        m[a%10]++;
        a/=10;
    }

    while(b){
        m[b%10]++;
        b/=10;
    }

    if(m.size() != 10)
        return false;

    for(auto x : m){
        if(x.second  != 1)
            return false;
    }

    return true;
}

int main(){

    bool nline = false;

    int N, abcde, c, d;

    while(scanf("%d", &N), N){
        
        bool marked = false;
        
        if(!nline) nline = true;
        else printf("\n");

        for(int fghij = 1234; fghij < 98765; fghij++){
            abcde = N * fghij;

            if(abcde > 98765)
                break;
            
            if(abcde < 10000) c = abcde*10;
            else c = abcde;

            if(fghij < 10000) d = fghij*10;
            else d = fghij;

            if(checkValue(c, d)){
                marked = true;

                if(abcde < 10000)
                    printf("0%d / %d = %d\n", abcde, fghij, N);
                if(fghij < 10000)
                    printf("%d / 0%d = %d\n", abcde, fghij, N);
                else printf("%d / %d = %d\n", abcde, fghij, N);
            
            }
        }

        if(!marked) printf("There are no solutions for %d.\n", N);
    }

   return 0;
}
