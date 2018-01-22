#include <stdio.h>
#include <bitset>

using namespace std;

const int MAX = 26;

char get_token(){
  char c;
  while(scanf("%c",&c)){
    if((c >= 'A' && c <= 'Z') || c == '*')
      return c;
  }
  return 0;
}
int main(){

  int tc;
  scanf("%d",&tc);

  while(tc--){
    char a;
    int num_edge = 0;
    bitset<MAX> connected;
    while(true){
      a = get_token();
      if(a == '*') break;                // this read just one *
      num_edge++;
      connected.set(a - 'A');            // set true for a - 'A' == number
      connected.set(get_token() - 'A');  // bset.set(pos) makes bset[pos] = 1
    }
    int num_vertices = 0;
    int num_acorn = 0;

    char s[250];
    fgets(s,250,stdin);
    fgets(s,250,stdin);                   //this read the vertices A,B,C...

    for(int i=0;s[i];i++){
      if(s[i] < 'A' || s[i] > 'Z')
        continue;
      num_vertices++;
      if(!connected[s[i]-'A'])
        num_acorn++;
    }
    int tree = num_vertices - num_edge - num_acorn;
    printf("There are %d tree(s) and %d acorn(s).\n",tree,num_acorn);
  }

  return 0;
}

