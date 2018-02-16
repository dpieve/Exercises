#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    
    ll n, t;
    cin >> n >> t;

    ll A[n +1];                                     //we 'sum' until 't'
    for(int i=0; i<n; i++)                          //check best option we remove first, second, ...
        cin >> A[i];                                //update the value of the best if remove is a good idea

    int finish=0; ll sum=0;
    while(finish < n && sum+A[finish] <= t)
        sum += A[finish++];

    int best=finish;
    for(int start=0; start<n; start++){
        sum -= A[start];
        while(finish < n && sum+A[finish] <= t)
            sum+=A[finish++];
        best = max(best, (finish-start-1));
    }
    cout << best << endl;

    return 0;
}
