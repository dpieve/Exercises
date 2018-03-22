// Dado K e N calcule Fibonacci começando com K vezes o numero 1 e somando os K anteriores 

// F[i] = somatório F[i-k]+ ... F[i-1]

#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define MAXN 100000
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){

    int k, n;

    cin >> k >> n;

    int F[10500];

    if(n < k){
        cout << "1" << endl;
    }else{
        for(int i=0; i<=n; i++){
            if(i < k)
                F[i] = 1;
            else if( i == k ) 
                F[i] = k;


            //BASTA OLHAR PARA A INTERSEÇÃO
            else F[i] = F[i-1] + F[i-1] - F[i-k-1];

        }

        cout << F[n-1] << endl;
    }

    


    return 0;
}
