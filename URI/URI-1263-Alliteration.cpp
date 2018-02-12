//https://www.urionlinejudge.com.br/judge/en/problems/view/1263
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){

    //freopen("input.txt","r",stdin);

    string str; 
    while(getline(cin, str)){
         ll ans=0;
         
         char first= tolower(str[0]), calculado=' ';
         
         for(ll i=1; i<str.length(); i++){
            if(str[i-1] == ' '){
                if(tolower(str[i]) == tolower(calculado)) 
                    continue;
                if(tolower(str[i]) == tolower(first)){
                    calculado = first;
                    ans++;
                }else{
                    first = tolower(str[i]);
                    calculado = ' ';
                }
            }
         }

         cout << ans << endl;   

    }

    return 0;
}
