#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int n;
    
    while(scanf("%d", &n), n){

        vector<double> a;

        double x, total = 0, pos = 0, neg = 0;

        for(int i=0; i<n; i++){
            scanf("%lf", &x);
            a.push_back(x);

            total += x;
        }

        total = total / n;
        for(int i=0; i<n; i++){
            double dif = (double) (long) ((a[i] - total)*100.0)/(100.0);
            if( dif > 0 ) pos += dif;
            else neg += dif;
        }

        printf("$%.2lf\n", abs( max(pos, abs(neg))));

    }


  return 0;
}
