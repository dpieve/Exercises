#include <bits/stdc++.h>

using namespace std;

int N;
string S;

set <int> used[30];

void print() {
    for (int i = 0; i < 28; ++i) {
        if (!used[i].empty()){
            cout << char(i + 'a') << ":";
            for (int x : used[i]) {
                cout << " " << x;
            }
            cout << endl;
        }
    }
}

void upd() {
    int pos;
    char c;
    
    cin >> pos >> c;
    
    for (int i = 0; i < 28; ++i) {
        if (!used[i].empty()) {
            auto it = used[i].lower_bound(pos);
            if ((*it) == pos) {
                used[i].erase (it);
                break;
            }        
        }
    }
    
    used[c-'a'].insert (pos);
    
}

void query() {
    int L, R;
    cin >> L >> R;
    
    int resp = 0;
    
    for (int i = 0; i < 28; ++i) {
        if(!used[i].empty()) {
            auto it = used[i].lower_bound (L);
            if (it == used[i].end())
                continue;
                
            resp += ((*it) <= R);
        }
    }
    
    cout << resp << '\n';
}


int main () {
    ios_base :: sync_with_stdio (0); cin.tie (NULL);
    
    cin >> S;
    N = S.size();

    for (int i = 0; i < N; ++i) {
        used[S[i] - 'a'].insert (i + 1);
    }
            
    //print();        
            
    int Q;
    cin >> Q;
    
    while (Q--) {
        int op;
        cin >> op;
        
        if (op == 1) {
            upd();
        }
        else {
            print();
            query();
        }
    }
    
    return 0;
}