#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200001;

int t[MAXN + 1];

int sum (int k) {
    int r = 0;

    while (k > 0) {
        r += t[k];
        r %= 2;
        
        k -= ( k & (-k) );
    }
    
    return r;
}

void upd (int k, int v) {
    while (k < MAXN) {
        t[k] += v;
        t[k] %= 2;
        
        k += ( k & (-k) );
    }  
}

char S[MAXN + 1];

void solver () {
    
    scanf("%s", &S[1]);
    
    int Q;
    scanf("%d", &Q);
    
    while (Q--) {
        getchar();
        
        char OP;
        scanf("%c", &OP);
        
        if (OP == 'I') {
            
            int L, R;
            scanf("%d %d", &L, &R);
            
            upd (L, 1);
            upd (R + 1, -1);
        
        }
        
        else {
            int P;
            scanf("%d", &P);
            
            int x = sum (P);
            int v = (S[P] - '0') % 2;
            
            printf ("%d\n", (x & 1 ? (!v) : (v)));
        }
    }    
    
}

int main () {
    
    int T;
    scanf("%d", &T);
    
    for (int c = 1; c <= T; ++c) {
       memset (t, 0, sizeof (t));
       
       printf ("Case %d:\n", c);
       solver ();
    }
    
    return 0;
}