// Just next_permutation

#include <bits/stdc++.h>

using namespace std;


int main(){

    string word, copy;
    while(cin >> word && word != "#")
    {
        copy = word;
        next_permutation(copy.begin(), copy.end());

        if(copy<=word)
            cout << "No Successor" << endl;
        else cout << copy << endl;
    }
    return 0;
}
