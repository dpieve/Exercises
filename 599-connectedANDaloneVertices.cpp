#include<bits/stdc++.h>

using namespace std;

char get_token(){
  char c;
  while(scanf("%c",&c)){
    if( (c>='A' && c<='Z') || c == '*')
      return c;
  }
  return 0;
}
int main(){

  int tc;
  scanf("%d",&tc);

  while(tc--){
    char a;
    int num_edges=0;
    bitset<26> connected;
    while(true){
      a = get_token();
      if(a == '*') break;
      num_edges++;
      connected.set(a-'A');
      connected.set(get_token() - 'A');
    }

    char s[250];
    fgets(s,250,stdin); /// ***
    fgets(s,250,stdin);

    int num_vertices=0; int num_acorn=0;
    for(int i=0;s[i];i++){
      if(s[i]<'A' || s[i]>'Z') continue;
      if(!connected[s[i]-'A']) num_acorn++;
      num_vertices++;
    }
    int num_tree = num_vertices - num_edges - num_acorn;
    printf("There are %d tree(s) and %d acorn(s).\n",num_tree,num_acorn);
  }

  return 0;
}
