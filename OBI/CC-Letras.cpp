//http://www.codcad.com/problem/129
//LIS problem. 

//Podemos inserir um número em uma pilha se seu topo **não for menor ou igual ao número**,
//ou seja, basta repetirmos exatamente o mesmo código trocando o lower_bound pelo **upper_bound**.

//lower_bound -> retorna um ponteiro para a posição mais à esquerda do array que não é menor que x.

#include <bits/stdc++.h>

using namespace std;

int LIS(string s){
    std::vector<char> pilha;    
    std::vector<char>::iterator it;


    for(int i=0; i<s.length(); i++){
        
        it = upper_bound(pilha.begin(), pilha.end(), s[i]);
        
        if(it == pilha.end())       //não há ninguém maior
            pilha.push_back(s[i]);  //então coloco na pilha
        else *it = s[i];            //senão atual passa a ser topo 
    }

    return pilha.size();
}
int main(){
 

    string s; cin >> s;
    cout << LIS(s) << endl;

    return 0;
}
