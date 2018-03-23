//https://www.urionlinejudge.com.br/judge/en/problems/view/1147

#include <bits/stdc++.h>

using namespace std;

int in(int a){
    return (a>=1 && a<=8);
}
int pos_num(char a){
    return (9 - (a-'0'));
}
int pos_letra(char a){
    return ((a - 'a')+1) ;
}

int main(){

    //freopen("input.txt", "r", stdin);

    int cases = 1;
    string knight;

    while(cin >> knight, knight != "0"){

        int moves = 8;

        int M[20][20];
        for(int i=0; i<=9; i++)
            for(int j=0; j<=9; j++)
                M[i][j] = 0;

        M[ pos_num(knight[0])][ pos_letra(knight[1]) ] = 2;

        if(in( pos_num(knight[0])+2 ) && in( pos_letra(knight[1])+1 ))
            M[ pos_num(knight[0])+2 ][ pos_letra(knight[1]) +1] = 1;
        else moves--;

        if(in( pos_num(knight[0])+1 ) && in( pos_letra(knight[1])+2 ))
            M[ pos_num(knight[0])+1 ][ pos_letra(knight[1]) +2] = 1;
        else moves--;

        if(in( pos_num(knight[0])+2 ) && in( pos_letra(knight[1])-1 ))
            M[ pos_num(knight[0])+2 ][ pos_letra(knight[1]) -1] = 1;
        else moves--;

        if(in( pos_num(knight[0])+1 ) && in( pos_letra(knight[1])-2 ))
            M[ pos_num(knight[0])+1 ][ pos_letra(knight[1]) -2] = 1;
        else moves--;

        if(in( pos_num(knight[0])-2 ) && in( pos_letra(knight[1])-1 ))
            M[ pos_num(knight[0])-2 ][ pos_letra(knight[1]) -1] = 1;
        else moves--;

        if(in( pos_num(knight[0])-1 ) && in( pos_letra(knight[1])-2 ))
            M[ pos_num(knight[0])-1 ][ pos_letra(knight[1]) -2] = 1;
        else moves--;

        if(in( pos_num(knight[0])-1 ) && in( pos_letra(knight[1])+2 ))
            M[ pos_num(knight[0])-1 ][ pos_letra(knight[1]) +2] = 1;
        else moves--;

        if(in( pos_num(knight[0])-2 ) && in( pos_letra(knight[1])+1 ))
            M[ pos_num(knight[0])-2 ][ pos_letra(knight[1]) +1] = 1;
        else moves--;

        /*
        for(int i = 1; i <= 8; i++){
            for(int j = 1; j <= 8; j++)
                cout << M[i][j] << " ";
            cout << endl;
        }
        */

        string pawn;

        for(int i = 0; i < 8; i++){
            cin >> pawn;

            if( in( pos_num(pawn[0]) +1) && in( pos_letra(pawn[1]) -1) ){
                if( M[pos_num(pawn[0])+1][pos_letra(pawn[1]-1)] == 1){
                    moves--;
                    M[pos_num(pawn[0])+1][pos_letra(pawn[1]-1)] = 0;
                }
            }

            if( in( pos_num(pawn[0]) +1) && in( pos_letra(pawn[1]) +1) ){
                if( M[pos_num(pawn[0])+1][pos_letra(pawn[1]+1)] == 1){
                    moves--;
                    M[pos_num(pawn[0])+1][pos_letra(pawn[1]+1)] = 0;
                }
            }
        }

        cout << "Caso de Teste #" << cases << ": "<< moves << " movimento(s)." << endl;
        cases++;
    }

    return 0;
}
