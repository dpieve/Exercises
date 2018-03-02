#include <bits/stdc++.h>

using namespace std;

int main() {
  
  string expression;
  while(cin >> expression){

    int parenthesis = 0;

    for(int i=0; i<expression.length(); i++){
      if(expression[i] == '(')
        parenthesis++;
      else if( expression[i] == ')' && (parenthesis <= 0) ) // It can't be possible, then
        parenthesis -= 100000;                              // ensure this is incorrect
      else if( expression[i] == ')' )
        parenthesis--;
    }

    if(parenthesis == 0) //balanced
      cout << "correct" << endl;
    else cout << "incorrect" << endl;

  }


  return 0;
}
