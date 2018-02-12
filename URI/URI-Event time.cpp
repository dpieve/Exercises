//https://www.urionlinejudge.com.br/judge/en/problems/view/1061

#include <bits/stdc++.h>

using namespace std;

int main(){
    
    //freopen("input.txt","r",stdin);

    string lixo;
    int d1, h1, m1, s1;
    int d2, h2, m2, s2;

    cin >> lixo >> d1 >> h1 >> lixo >> m1 >> lixo >> s1;
    cin >> lixo >> d2 >> h2 >> lixo >> m2 >> lixo >> s2;
    
    int t1, t2;
    t1 = s1 + m1*60 + h1*60*60 + d1*60*60*24;
    t2 = s2 + m2*60 + h2*60*60 + d2*60*60*24;

    int time =  t2 - t1;
    printf("%d dia(s)\n", time/(60*60*24)); time = time%(60*60*24);
    printf("%d hora(s)\n", time/(60*60)); time = time%(60*60);
    printf("%d minuto(s)\n", time/(60)); time = time%(60);
    printf("%d segundo(s)\n", time); 
    
    return 0;
}
