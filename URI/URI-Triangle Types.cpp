//https://www.urionlinejudge.com.br/judge/en/problems/view/1045
#include <bits/stdc++.h>

using namespace std;


bool cmp(double x, double y){
    return (x>y);
}
int main(){
    
    // just implement

    std::vector<double> v;

    double x;
    for(int i=1; i<=3; i++){
        cin >> x;

        v.push_back(x);
    }
    sort(v.begin(), v.end(), cmp);

    if(v[0] >= (v[1]+v[2])){
        cout << "NAO FORMA TRIANGULO" << endl;
    }else{
        if( v[0]*v[0] == (v[1]*v[1] + v[2]*v[2]) )
            cout << "TRIANGULO RETANGULO" << endl;
        else if( v[0]*v[0] > (v[1]*v[1] + v[2]*v[2]) )
            cout << "TRIANGULO OBTUSANGULO" << endl;
        else if( v[0]*v[0] < (v[1]*v[1] + v[2]*v[2]) )
            cout << "TRIANGULO ACUTANGULO" << endl;

        if( v[0] == v[1] && v[1] == v[2] )
            cout << "TRIANGULO EQUILATERO" << endl;
        else if(v[0] == v[1] || v[0] == v[2] || v[1] == v[2])
            cout << "TRIANGULO ISOSCELES" << endl;
    }
    return 0;
}
