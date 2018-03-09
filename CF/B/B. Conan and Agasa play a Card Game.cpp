#include <bits/stdc++.h>

using namespace std;


bool odd(map<int,int> freq){
    map<int, int>::iterator it;

    for(it = freq.begin(); it != freq.end(); it++){
        if(it->second % 2 != 0)
            return true;
    }

    return false;
}

int main() {
   
    //freopen("input.txt", "r", stdin);

    int n, x;
    scanf("%d", &n);

    map<int, int> freq;
    for(int i=0; i<n; i++){
        scanf("%d", &x);

        freq[x]++;
    }

    if(odd(freq))
        printf("Conan\n");
    else printf("Agasa\n");


  return 0;
}
