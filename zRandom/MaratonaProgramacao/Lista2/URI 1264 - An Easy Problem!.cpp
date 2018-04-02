#include <bits/stdc++.h>

using namespace std;

int main(){

    map<char, int> value;

    // 0 -> 10
    for(char a = '0';  a <= '9'; a++)
        value[ a ] = a - '0';
    
    // 10 -> 35
    for(char a = 'A';  a <= 'Z'; a++)             /* ASCII table */
        value[ a ] = a - 55;                // A == 65   (65 - 55) = 10 
    
    // 36 -> 62
    for(char a = 'a';  a <= 'z'; a++)       // a == 97   (97 - x ) = 36 => x = 61
        value[ a ] = a - 61;                  

    string num;
    while(getline(cin, num)){
        
        int max_value = 0, count = 0;
        
        for(int i = 0; i < num.length(); i++){
            if(num[i] != '-') 
                max_value = max(max_value, value[ num[i] ]);

            count += value[ num[i] ];
        }

        if(max_value != 0){
            while(max_value < 62){
                if(count % max_value == 0)
                    break;
                max_value++;
            }
        }

        if(count == 0)
            cout << "2" << endl;
        else{ 
            if(max_value >= 62)
                cout << "such number is impossible!" << endl;
            else cout << max_value+1 << endl;
        }
    } 

    return 0;
}
