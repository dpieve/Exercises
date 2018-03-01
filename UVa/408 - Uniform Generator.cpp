#include <bits/stdc++.h>

using namespace std;

int main() {
   
  int step, mod;

  while(scanf("%d %d", &step, &mod) == 2){
    
    bool good[100000];
    memset(good, false, sizeof good);

    good[0] = 1;

    int seed = 0;

    for(;;){
      seed = (seed + step)%mod;

      if( good[seed] == true )
        break;

      good[seed] = true;
    }

    bool ans = true;
    for(int i=0; i<mod; i++){
      if(!good[i]){
        ans = false;
        break;
      }
    }

    if(ans == true)
      printf("%10d%10d    Good Choice\n", step, mod);
    else
      printf("%10d%10d    Bad Choice\n", step, mod);
    
    printf("\n");

  }



  return 0;

}
