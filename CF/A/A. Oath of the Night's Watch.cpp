#include <bits/stdc++.h>

#define MAX 1000000001
#define MIN -1

using namespace std;

typedef long long int ll;

int main() {
   
    int n;
    scanf("%d", &n);

    ll low = MAX, high = MIN, steward[n +1];

    for(int i=0; i<n; i++){
        cin >> steward[i];

        if(steward[i] < low)
            low = steward[i];
        else if(steward[i] > high)
            high = steward[i];
    }

    int ans=0;
    for(int i=0; i<n; i++){
        if(low < steward[i] && steward[i] < high)
            ans++;
    }
    printf("%d\n", ans);
  return 0;
}

