#include <bits/stdc++.h>

using namespace std;

int main() {
   
    string word, copy;
    cin >> word >> copy;

    reverse(copy.begin(), copy.end());

    if(copy != word) 
         printf("NO\n");
    else printf("YES\n");

  return 0;
}
