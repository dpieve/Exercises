//https://www.urionlinejudge.com.br/judge/en/problems/view/1049
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    //freopen("input.txt","r",stdin);

    string a, b, c;
    cin >> a >> b >> c;
    
    if( a == "vertebrado" ){
        if(b == "ave"){
            if(c == "carnivoro")
                printf("aguia\n");
            else if(c == "onivoro")
                printf("pomba\n");
        }else{
            if(b == "mamifero"){
                if(c == "onivoro")
                    printf("homem\n");
                else if(c == "herbivoro")
                    printf("vaca\n");
            }
        }
    }else{
        if( a == "invertebrado" ){
            if(b == "inseto"){
                if(c == "hematofago")
                    printf("pulga\n");
                else if(c == "herbivoro")
                    printf("lagarta\n");
            }else{
                if(b == "anelideo"){
                    if(c == "hematofago")
                        printf("sanguessuga\n");
                    else if(c == "onivoro")
                        printf("minhoca\n");
                }
            }
        }
    }


    return 0;
}
