#include <bits/stdc++.h>

using namespace std;

int main() {
    
    // n - number of oranges
    // b - max size of the orange
    // d - condition when the waste section should be emptied.

    int n, b, d;
    scanf("%d %d %d", &n, &b, &d);

    int cont=0;
    long long int a, sum=0;
    for(int i=0; i<n; i++){
        cin >> a;

        if(a <= b){
            sum += a;
            if(sum > d){
                cont++;
                sum=0;
            }
        }   
    }   
    printf("%d\n", cont);

  return 0;
}
