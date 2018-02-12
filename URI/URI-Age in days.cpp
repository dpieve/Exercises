#include <bits/stdc++.h>

using namespace std;

int main(){
    
    //freopen("input.txt","r",stdin);
    int d;
    scanf("%d", &d);

    int y, m;
    y = d/365;
    d = d%365;

    m = d/30;
    d = d%30;

    printf("%d ano(s)\n", y);
    printf("%d mes(es)\n", m);
    printf("%d dia(s)\n", d);

    return 0;
}
