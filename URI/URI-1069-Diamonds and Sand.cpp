#include <bits/stdc++.h>

using namespace std;

int main() {
  
  int n;
  scanf("%d", &n);

  getchar();

  while(n--){
    
    char obj;
    int diamonds = 0, open = 0;

    for(;;){
      scanf("%c", &obj);
      if(obj == '\n' || obj == '\0')
        break;

      if(obj == '<'){
        open++;
      }else{
        if((obj == '>') && (open > 0)){
          open--;
          diamonds++;
        }
      }
    }
    printf("%d\n", diamonds);

  }
  return 0;
}
