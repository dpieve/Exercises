#include <bits/stdc++.h>

using namespace std;

bool cmp(const string& a, const string& b){
  return a.size() > b.size();
}

int main(){

  //freopen("input.txt", "r", stdin);

  int cases;
  cin >> cases; 
  cin.ignore();

  while(cases--){
    string line;
    getline(cin, line);

    vector< string > words;
    stringstream check1(line);

    string tmp;
    while(getline(check1, tmp, ' ')){
      words.push_back(tmp);
    }

    stable_sort(words.begin(), words.end(), cmp);

    cout << words[0];
    for(int i = 1; i < words.size(); i++){
      cout << " " << words[i];
    }
    cout << endl;

  }


    return 0;
}
