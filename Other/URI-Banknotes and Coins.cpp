//https://www.urionlinejudge.com.br/judge/en/problems/view/1021
#include <bits/stdc++.h>

using namespace std;

int main(){

    //notes 100, 50, 20, 10, 5, 2
    //coins 1, 0.50, 0.25, 0.10, 0.05 and 0.01

    //Make it easy xD
    //notes 10000, 5000, 2000, 1000, 500, 200
    //coins 100, 50, 25, 10, 5 and 1

    double N;
    cin >> N;

    int n = N*100;

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", n/10000); n = n%10000;
    printf("%d nota(s) de R$ 50.00\n",  n/5000);  n = n%5000;
    printf("%d nota(s) de R$ 20.00\n",  n/2000);  n = n%2000;
    printf("%d nota(s) de R$ 10.00\n",  n/1000);  n = n%1000;
    printf("%d nota(s) de R$ 5.00\n",   n/500);   n = n%500;
    printf("%d nota(s) de R$ 2.00\n",   n/200);   n = n%200;
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", n/100);    n = n%100;
    printf("%d moeda(s) de R$ 0.50\n", n/50);    n = n%50;
    printf("%d moeda(s) de R$ 0.25\n", n/25);   n = n%25;
    printf("%d moeda(s) de R$ 0.10\n", n/10);  n = n%10;
    printf("%d moeda(s) de R$ 0.05\n", n/5);  n = n%5;
    printf("%d moeda(s) de R$ 0.01\n", n); 


    return 0;
}
