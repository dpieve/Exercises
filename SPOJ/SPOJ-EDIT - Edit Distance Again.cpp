#include <bits/stdc++.h>

using namespace std;

string s;
int dp[1003][3];

bool is_lower(char x){
    return (x>='a' && x<='z');
}
bool is_upper(char x){
    return (x>='A' && x<='Z');
}

int edit_dist(int i, int op){

    if(op == 0){
        if(is_lower(s[i])){
            if(i == 0) return 0;
            return (dp[i][op] = edit_dist(i-1, 1));
        }
        else{
            if(i == 0) return 1;
            return (dp[i][op] = edit_dist(i-1, 1) + 1);
        }
    }
    if(is_upper(s[i])){
        if(i == 0) return 0;
        return (dp[i][op] = edit_dist(i-1, 0));
    }else{
        if(i == 0) return 1;
        return (dp[i][op] = edit_dist(i-1, 0) + 1);
    }

}

int solved(){
    int x = s.length();
    return min( edit_dist(x-1, 0), edit_dist(x-1, 1) );
}

int main(){
    
    while(cin >> s){
        memset(dp, 0, sizeof dp);
        cout << solved() << endl;
    }
    
    return 0;
}
