#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

struct point {

    int z, o, t;    
    
    point(int a = 0, int b = 0, int c = 0) {
        z = a; 
        o = b; 
        t = c;
    }
    
    point operator + (const point &b) {
        return point(z + b.z, o + b.o, t + b.t);
    }
    
};

int lz[4 * MAXN];
point t[4 * MAXN];

void propaga(int i) {
    
    int a = t[i].z; 
    int b = t[i].o; 
    int c = t[i].t; 
    int d;
    
    d = c;
    c = b;
    b = a;
    a = d;
    
    t[i] = point(a, b, c);
}

void push(int i, int l, int r) {
    lz[i] %= 3;
    
    if (lz[i]) {
        if (l != r) {
            lz[2 * i] = (lz[2 * i] + lz[i]) % 3;
            lz[2 * i + 1] = (lz[2 * i + 1] + lz[i]) % 3;
        }
        
        while(lz[i] > 0) {
            propaga(i);
            --lz[i];
        }

    }
}


void upd(int i, int l, int r, int ql, int qr) {
    push(i, l, r);

    if (qr < l || r < ql) {
        return;
    }

    if (ql <= l && r <= qr) {
        lz[i] += 1;
        lz[i] %= 3;
        push(i, l, r);
        return;
    }

    int m = (l + r) / 2;
    upd(2 * i, l, m, ql, qr);
    upd(2 * i + 1, m + 1, r, ql, qr);
    t[i] = t[2 * i] + t[2 * i + 1];

}

void build(int i, int l, int r) {
    if (l == r) {
        t[i] = point(1, 0, 0);
    }
    else {
        int m = (l + r) / 2;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        t[i] = t[2 * i] + t[2 * i + 1];
    }
}

point ask(int i, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
        return point(0, 0, 0);
    }
    if (ql <= l && r <= qr) {
        return t[i];
    }
    int m = (l + r) / 2;
    return ask(2 * i, l, m, ql, qr) + 
            ask(2 * i + 1, m + 1, r, ql, qr);
}

void solver() {

    int N, K;
    scanf("%d %d", &N, &K);

    memset(lz, 0, sizeof (lz));
    build(1, 1, N);
            
    while(K--) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        
        x += 1;
        y += 1;
        
        if (op == 0) {
            upd(1, 1, N, x, y);
        }
        else {
            printf("%d\n", ask(1, 1, N, x, y).z);
        }
    }
}


int main() {
    
    int T;
    scanf("%d", &T);
    
    for (int i = 1; i <= T; ++i) {
        printf("Case %d:\n", i);
        solver();
    }
    
    return 0;
}