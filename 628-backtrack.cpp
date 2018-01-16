#include <iostream>
#include <stdio.h>

using namespace std;

string rules;
string word[101];
char output[300];
int n_words,sz_rules,idx_word;

void password(int idx){
    if(idx==sz_rules){
        for(int i=0;i<sz_rules;i++){
            if(output[i]=='#')cout << word[idx_word];
            else printf("%c", output[i]);
            }
        cout << endl;
    }
    else 
        if(rules[idx]=='#'){
            output[idx]='#';
            password(idx+1);
        }else{
            for(int i=0;i<=9;i++){
                output[idx]=i+'0';
                password(idx+1);
            }
    }
}
int main(){
    
    //freopen("input.txt", "r", stdin);

    while(scanf("%d", &n_words)==1){
        cout<<"--"<<'\n';
        for(int i=0;i<n_words;i++)
            cin >> word[i];

        int n_rules;
        scanf("%d", &n_rules);
        for(int i=0;i<n_rules;i++){
            cin >> rules;
            sz_rules = rules.size();

            for(int j=0;j<n_words;j++){
                idx_word = j;
                password(0);
            }
        }
    }
    return 0;
}
