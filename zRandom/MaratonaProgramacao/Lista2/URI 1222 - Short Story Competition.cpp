//https://www.urionlinejudge.com.br/judge/en/problems/view/1222


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

    int N, L, C;

    while(cin >> N >> L >> C){

        string word;
        int chars = 0, lines = 1, pages = 0;
        
        while(N--){
            cin >> word;
            
            // bool=> ( char!=0 ) is 0 or 1
            // It's because we have to calculate the chars ' '. So, we add 1 for each word-1.
            
            if((chars + (chars!= 0) + word.size()) <= C){
                chars += (word.size()+(chars != 0));
            }
            else{
                lines++;
                chars = word.size();
                
                if(lines > L){
                    lines = 1;
                    pages++;
                }
            }
        }
        pages++;
        cout << pages << endl;
    }

    return 0;
}
