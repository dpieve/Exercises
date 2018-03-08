http://codeforces.com/gym/101510/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int s[10];
    for(int i=0; i<5; i++)
        scanf("%d", &s[i]);

    sort(s, s+5);

    int ways = 0;
    for(int i=0; i<5; i++)
        for(int j=0; j<5 && i!=j; j++)
            for(int k=j+1; k<5 && k!=i; k++)
                if(s[i] < s[j]+s[k])
                    ways++;

    printf("%d\n", ways);

  return 0;
}
