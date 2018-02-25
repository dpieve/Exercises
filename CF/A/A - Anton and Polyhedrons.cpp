#include <bits/stdc++.h>

using namespace std;

int main(){
  
    int n; string p;

    long long int total = 0;

    cin >> n;    
    while(n--){
      cin >> p;

           if(p[0] == 'T') total+=4;
      else if(p[0] == 'C') total+=6;
      else if(p[0] == 'O') total+=8;
      else if(p[0] == 'D') total+=12;
      else if(p[0] == 'I') total+=20;
    }
    cout << total << endl;


  return 0;
}
