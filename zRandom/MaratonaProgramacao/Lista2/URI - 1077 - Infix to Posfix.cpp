//Infix to Posfix
//https://www.urionlinejudge.com.br/judge/en/problems/view/1077

#include <bits/stdc++.h>

using namespace std;

bool isOperator(char a){
    return ( (a=='+') || (a=='-') || (a=='*') || (a=='/') || (a=='^') );
}

int priority(char a){

    switch(a){
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;

        default:
            return 0;
    }
}

int main(){

    //freopen("input.txt", "r", stdin);

    int N;
    cin >> N;

    while(N--){

        string exp;
        cin >> exp;

        stack<char> s;
        string res = "";

        for(int i = 0; i < (int)exp.size(); i++){
            
            if( isOperator(exp[i])){
                while(!s.empty() && priority(s.top()) >= priority(exp[i])){
                    res += s.top();
                    s.pop();
                }
                s.push(exp[i]);
            }
            else{
                if(exp[i] == '(')
                    s.push(exp[i]);
                else{
                    if(exp[i] == ')'){
                        while( s.top() != '(' ){
                            res += s.top();
                            s.pop();
                        }
                        s.pop();
                    }else res+=exp[i];
                }
            }
        }

        while(!s.empty()){ res += s.top(); s.pop(); }
    
        cout << res << endl;

    }

    return 0;
}
