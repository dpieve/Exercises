https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=&problem=53&mosmsg=Submission+received+with+ID+20917572

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector< ii > vii;

vector< ii > G[40];

int Dijkstra(int s, int t){
    
    vector<int> dist(27, 1000000);
    priority_queue< ii, vector<ii>, greater<ii> > q;

    q.push(ii(0, s)); dist[s] = 0;
    while(!q.empty()){
        ii front = q.top();
        q.pop();

        int d = front.first;
        int u = front.second;

        if(d > dist[u]) continue;

        for(int j=0; j<(int)G[u].size(); j++){
            ii v = G[u][j];

            if( dist[v.second] > d + v.first){
                dist[v.second] = d + v.first;
                q.push(ii(dist[v.second], v.second));
            }
        }
    }

    return dist[t];
}

int main() {
 
    string path, final = "deadend";

    int total = 0;

    while(cin >> path){
        if(path == final){
            int v[100], p=0; v[0]=-1;

            for(int i=0; i<27; i++){
                int len = G[i].size();
                if(len % 2 != 0){
                    v[p++] = i;
                }
            }
            if(v[0] == -1)
                cout << total << endl;
            else{
                p=1;
                while(v[0] == v[p]) p++;
                cout << total + Dijkstra(v[0], v[p]) << endl;  
            } 

            for(int i=0; i<27; i++)
                G[i].clear();
            total = 0;
        }else{
            int w = path.length();

            int u = path[0]   -'a';
            int v = path[w-1] - 'a';

            G[u].push_back(make_pair(w, v));
            G[v].push_back(make_pair(w, u));

            total += w;
        }

        
    }


  return 0;
}
