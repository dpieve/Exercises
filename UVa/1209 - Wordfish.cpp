#include <bits/stdc++.h>

using namespace std;

int valueOf(string &x){

  int rsp=0;
  for(int i=1; i<x.size(); i++){
    int dist = abs(x[i] - x[i-1]);

    if(rsp==0) rsp = dist;
    else rsp = min(rsp, dist);
  }

  return rsp;

}

int main(){

  string input;
  pair< string, int > rsp;

  while(getline(cin, input)){
    string tmp(input);

    rsp.first  = tmp;
    rsp.second = valueOf(tmp);

    int count=0;
    while(prev_permutation(tmp.begin(), tmp.end())){
      count++;
      int tmp_value = valueOf(tmp);
      if(tmp_value >= rsp.second){
        rsp.first =  tmp;
        rsp.second = tmp_value;
      }

      if(count>=10)
        break;
    }

    count=0;
    while(next_permutation(input.begin(), input.end())){
      count++;

      int tmp_value = valueOf(input);
      if(tmp_value > rsp.second){
        rsp.first = input;
        rsp.second= tmp_value;
      }
      if(count>=10)
        break;
    }
    cout << rsp.first << rsp.second << endl;
  }
  return 0;
}
