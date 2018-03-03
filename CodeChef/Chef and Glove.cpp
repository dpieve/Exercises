#include <bits/stdc++.h>

using namespace std;

int main() {
   //freopen("input.txt", "r", stdin);

  int tc, n;
  cin >> tc;

  while(tc--){
    cin >> n;

    vector<long long> finger(n, 0);
    for(int i=0; i<n; i++)
      cin >> finger[i];

    vector<long long> glove(n, 0);
    for(int i=0; i<n; i++)
      cin >> glove[i];

    bool front = true;
    for(int i=0; i<n; i++)
      if(glove[i] < finger[i]){
        front = false;
        break;
      }

    bool back = true;

    reverse(glove.begin(), glove.end());
    
    for(int i=0; i<n; i++)
      if(glove[i] < finger[i]){
        back = false;
        break;
      }

    if(front == true && back == true)
      cout << "both" << endl;
    else if(front == true)
      cout << "front" << endl;
    else if(back == true)
      cout << "back" << endl;
    else cout << "none" << endl;

  }

  return 0;
}
