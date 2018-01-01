#include <cstdio>
using namespace std;

int Fib[5001][500]={0};

int main()
{
    Fib[1][0]=1;
    for (int i=2; i<=5000; i++){
        for (int j=0; j<500; j++){
            Fib[i][j] += Fib[i-1][j]+Fib[i-2][j];
            if (Fib[i][j]>=1000){
                Fib[i][j] -= 1000;
                Fib[i][j+1]++;
            }
        }
    }
    int n;
    while (scanf("%d",&n)!=EOF){
        printf("The Fibonacci number for %d is ",n);
        if (!n) printf("0\n");
        else {
            int i=500;
            while (Fib[n][--i]==0);
            printf("%d",Fib[n][i--]);
            for (; i>=0; i--) printf("%.3d",Fib[n][i]);
            printf("\n");
        }
    }
    return 0;
}
