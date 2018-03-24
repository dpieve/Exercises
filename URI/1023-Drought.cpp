//https://www.urionlinejudge.com.br/judge/en/problems/view/1023

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

//average consumption = sum of each (total consumption) / sum of all residents

int main(){

    //freopen("input.txt", "r", stdin);

    int city = 1, n;

    while(scanf("%d", &n), n){

        int r, c;
        double total_r = 0, total_c = 0;

        priority_queue< ii, vii, greater<ii> > pq;

        for(int i = 0; i < n; i++){
            scanf("%d %d", &r, &c);
        
            total_r += r;
            total_c += c;

            pq.push(mp(c/r , r));
        }
        printf("Cidade# %d:\n", city);
        city++;

        ii f = pq.top(); pq.pop();
        int prev_c = f.first, prev_r = f.second, cur_c, cur_r, n_c =f.first, n_r = f.second;

        while(!pq.empty()){
            ii f = pq.top(); pq.pop();

            cur_c = f.first;
            cur_r = f.second;

            if(cur_c == prev_c){
                //n_c += cur_c;
                n_r += cur_r;
            }else{
                printf("%d-%d ", n_r, n_c);
                n_c = cur_c;
                n_r = cur_r;
            }
            prev_c = cur_c;
            prev_r = cur_r;

        }
        printf("%d-%d\n", n_r, n_c);

        double fp, ip;

        fp = (int) (modf ((double)total_c/total_r, &ip) * 100);

        if(fp < 10) printf("Consumo medio: %d.0%d m3.\n\n", (int)ip, (int)fp);
        else printf("Consumo medio: %d.%d m3.\n\n", (int)ip, (int)fp);
        
    }


    return 0;
}
