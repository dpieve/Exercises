#include <bits/stdc++.h>

using namespace std;

//inverte numero!
int inverte(int n){
    int r = 0;

    while(n != 0){
        r += n%10;
        n /= 10;

        if(n == 0) 
            break;
        r *= 10;
    }

    return r;

}

bool is_palindromo(int x){
    return (x == inverte(x));
}


int main() {
 
    //freopen("input.txt", "r", stdin);

    int tc, n;
    cin >> tc;

    while(tc--){

        cin >> n;

        int count = 0;
        while(!is_palindromo(n)){
            n += inverte(n);
            count++;
        }

        cout << count << endl;

    }


  return 0;
}
