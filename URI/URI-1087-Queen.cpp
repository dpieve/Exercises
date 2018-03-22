//https://www.urionlinejudge.com.br/judge/en/problems/view/1087

#include <bits/stdc++.h>

using namespace std;

int main(){

    //freopen("input.txt", "r", stdin);

    int a, b, c, d;

    while(scanf("%d %d %d %d", &a, &b, &c, &d), a, b, c, d){
        if(a == c && b == d)
            printf("0\n");
        else if(a == c || b == d)
            printf("1\n");
        else{
            int x = abs(c - a);
            int y = abs(d - b);

            if(abs(x - y) != 0)
                printf("2\n");
            else printf("1\n");
        }
    }

    return 0;
}
