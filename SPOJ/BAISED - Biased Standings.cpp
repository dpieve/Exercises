//http://www.spoj.com/problems/BAISED/

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001
#define ll long long int

string team;
set<int> places;
vector<int> wait;

int t, n_team, preferred;

int main(){

    cin >> t;
    while(t--){
        cin >> n_team;

        for(int i = 1; i <= n_team; i++)
            places.insert(i);

        while(n_team--){
            cin >> team >> preferred;

            if(places.count(preferred) == 0){
                wait.push_back(preferred);
            }
            places.erase(preferred);
        }

        int i = 0;
        ll sum = 0;

        sort(wait.begin(), wait.end());
        set<int>::iterator it = places.begin();

        for(; it != places.end(); it++){
            if(i >= wait.size())
                break;

            sum += abs(*it-wait[i++]);
        }

        cout << sum << endl;

        wait.clear(); places.clear();
    }


   return 0;
}
