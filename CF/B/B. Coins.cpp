//http://codeforces.com/contest/47/problem/B

#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main(){

   int i, V[ 10 ];
   for(i = 0; i < 10; i++)
      V[ i ] = 0;

   char line[ 10 ];
   for(i = 0; i < 3; i++){
      scanf("%s", line);

      if(line[ 1 ] == '>'){
         V[ line[0]-'A' ]++; V[ line[2]-'A' ]--;
      }else{
         V[ line[0]-'A' ]--; V[ line[2]-'A' ]++;
      }
   }

   int a = V[0], b = V[1], c = V[2];

   if(a == b || a == c || b == c)
      printf("Impossible\n");
   else{
      sort(V, V+3);
      for(int i = 0; i < 3; i++){
         if(a == V[i])
            printf("A");
         else if(b == V[i])
            printf("B");
         else if(c == V[i])
            printf("C");
      }
      printf("\n");
      
   }



   return 0;
}
