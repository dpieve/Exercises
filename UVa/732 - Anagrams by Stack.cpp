#include <bits/stdc++.h>

using namespace std;

string a, b;
int input_size;

deque< char > s, actions;
vector < deque<char> > result;

void solve(int i, int j){

  if( (i == input_size) && (j == input_size) ){
    result.push_back(actions);
    return;
  }

  if( i < input_size ){
    s.push_back(a[i]);
    actions.push_back('i');
    solve(i + 1, j);

    s.pop_back();
    actions.pop_back();
  }
  if( !s.empty() && s.back() == b[j] ){
    char tmp = s.back();
    s.pop_back();

    actions.push_back('o');
    solve(i, j+1);

    s.push_back(tmp);
    actions.pop_back();
  }

}
int main() {
   

  while(getline(cin, a)){
    getline(cin, b);

    result.clear();

    string tmp1(a);
    string tmp2(b);

    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end());
    
    if(tmp1 != tmp2){
      cout << "[" << endl << "]" << endl;
      continue;
    }   

    input_size = a.size();

    solve(0, 0);

    cout << "[" << endl;
    for(int i=0; i<result.size(); i++){
      
      bool first = true;

      while(!result[i].empty()){
        if(!first) 
          cout << " ";
        first = false;

        cout << result[i].front();
        result[i].pop_front();
      }
      cout << endl;
    }
    cout << "]" << endl;
  }

  return 0;
}
