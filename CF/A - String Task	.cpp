#include <bits/stdc++.h>

using namespace std;

bool is_vowel(char a){
    return ( (a == 'a') || (a == 'o') || (a == 'y') || (a == 'e') || (a == 'u') || (a == 'i') );
}

int main() {
   
    // 1 deletes all vowels a o y e u i
    // 2 insert . before consoant
    // 3 all lowercase

    string word;
    cin >> word;

    int len = word.length();

    for(int i=0; i<len; i++){
        word[i] = tolower(word[i]);
    }

    string ans = "";

    for(int i=0; i<len; i++){
        if(!is_vowel(word[i])){
            ans += '.';
            ans += word[i];
        }
    }

    cout << ans << endl;
    
  return 0;
}
