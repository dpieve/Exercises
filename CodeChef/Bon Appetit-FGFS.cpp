//https://www.codechef.com/problems/FGFS


#include <bits/stdc++.h>

using namespace std;

#define ll long long int
typedef pair<int,int> ii;


map< int, priority_queue< ii, vector<ii>, greater<ii> > > m;
map< int, priority_queue< ii, vector<ii>, greater<ii> > >::iterator it;

int main(){

    int T, N, K, s, f, p, customers, curr_end;

    scanf("%d", &T);
    while(T--){  
        m.clear();
        scanf("%d %d", &N, &K);
        for(int i = 0; i < N; i++){
            scanf("%d %d %d", &s, &f, &p);
            m[p].push(make_pair(f,s));
        }

        it = m.begin();
        customers = 0;

        while(it != m.end()){
            curr_end = -2e9;
            while(!(*it).second.empty()){
                if((*it).second.top().second >= curr_end){
                    customers++;
                    curr_end = (*it).second.top().first;
                }
                (*it).second.pop();
            }
            it++;
        }

        cout << customers << endl;

    }



   return 0;
}
