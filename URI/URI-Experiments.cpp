//https://www.urionlinejudge.com.br/judge/en/problems/view/1094

#include <bits/stdc++.h>

using namespace std;

int main(){

    //freopen("input.txt","r",stdin);

    int e, x, c=0, r=0, s=0;
    scanf("%d", &e);

    while(e--){
        string y;

        cin >> x >> y;

        if(y[0] == 'C')
            c+=x;
        else if(y[0] == 'R')
            r+=x;
        else if(y[0] == 'S')
            s+=x;
    }

    int total = (c+r+s);
    printf("Total: %d cobaias\n", total);

    printf("Total de coelhos: %d\n", c);
    printf("Total de ratos: %d\n",   r);
    printf("Total de sapos: %d\n",   s);

    double pc = (c*100.00)/total, pr = (r*100.00)/total, ps = (s*100.00)/total;
    printf("Percentual de coelhos: %.2lf %\n", pc);
    printf("Percentual de ratos: %.2lf %\n",   pr);
    printf("Percentual de sapos: %.2lf %\n",   ps);

    return 0;
}
