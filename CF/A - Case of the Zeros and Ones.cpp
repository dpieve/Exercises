#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int n;
    scanf("%d", &n);

    string num;
    cin >> num;

    //hint: queue = TLE

    int a=0, b=0, sz = num.size();
    for(int i=0; i<sz; i++){
        if(num[i] == '1')
            a++;
        else if(num[i] == '0')
            b++;
    }

    int ans = abs(a-b);
    printf("%d\n", ans);
  return 0;
}
