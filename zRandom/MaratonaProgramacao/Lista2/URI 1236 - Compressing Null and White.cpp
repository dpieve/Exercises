//https://www.urionlinejudge.com.br/judge/en/problems/view/1236
//Compressing Null and White

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


string compress(char toCompress, int times){
    string result;

    if(times > 2){

        char compressC = toCompress == '0'?'#':'$';

        while(times > 2){
            result.pb(compressC);
            result.pb( (char)min(255, times));
            times -= 255;
        }
    }
    else result.append(times, toCompress);

    return result;
}

int main(){


   // freopen("input.txt", "r", stdin);

    int N;
    cin >> N;
    cin.ignore();

    while(N--){
        string line, res="";

        getline(cin, line);

        int lS = -1;

        for(int j = 0; j < line.size(); j++){
            if(lS != -1 && line[j] != line[j-1]){
                res += compress(line[j-1], j - lS);
                lS = -1;
            }

            if(line[j] == '0' || line[j] == ' '){
                lS = lS == -1 ? j:lS;
            }else res.pb(line[j]);
        }
        if(lS != -1){
            res += compress(line[ lS ], line.size() - lS);
        }

        cout << res << endl;

    }   

    return 0;
}
