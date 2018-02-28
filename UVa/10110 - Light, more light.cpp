//How many factors does N have ?
//If there are Odd number of factors then output: Yes otherwise No.

//A number have Odd number of factors if and only if it is a Perfect Square.
//So, if (sqrt (N) = Integer) then output: Yes otherwise No.


#include <bits/stdc++.h>

using namespace std;

int main(){

	long long x, s;
 	while(cin >> x && x!=0){
        s = sqrt(x);
        if(s*s == x) 
        	 cout << "yes" << endl;
        else cout << "no" << endl;
 	}

    return 0;
}
