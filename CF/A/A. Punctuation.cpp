//http://codeforces.com/problemset/problem/147/A

#include <bits/stdc++.h>

using namespace std;

bool isPunctuation(char c){
    return (c == '!' || c == '?' || c == ',' || c == '.');
}

int main() {

    //freopen("input.txt", "r", stdin);
 
    string words;
    getline(cin, words);

    // (1 remove spaces)
    for(int i=1; i<(int)words.length(); i++){
        if(words[i] == ' ' && words[i-1] == ' '){
            words.erase(i-1, 1);
            i--;
        }
    }
    
    // (2 remove spaces before punctiation)
    for(int i=1; i<(int)words.length(); i++){
        if(isPunctuation(words[i]) && words[i-1] == ' '){
            words.erase(i-1, 1);
            
            if(i-2 >= 0)
                i-=2;
            else i--; 
        }
    }

    // (3 insert space after punctuation)
    for(int i=1; i<(int)words.length(); i++){    
        if(words[i] != ' ' && isPunctuation(words[i-1]) ){
            words.insert(i, " ");
        } 
    }
    cout << words << endl;

  return 0;
}
