//https://www.codechef.com/MARCH18B/problems/BIGSALE

#include <bits/stdc++.h>

using namespace std;

int main() {
   
  //freopen("input.txt", "r", stdin);
  
  int t, n;
  scanf("%d", &t);

  while(t--){
    cin >> n;

    double price, new_price, qtd, discount, lost = 0;
    for(int i=0; i<n; i++){
      scanf("%lf %lf %lf", &price, &qtd, &discount);

      new_price = price;
      new_price = new_price + new_price*(discount/100);
      new_price = new_price - new_price*(discount/100);

      lost += (qtd*(price - new_price));
    }
    printf("%.8lf\n", lost);
  }


  return 0;
}
