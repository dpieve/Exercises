#include<bits/stdc++.h>

//here_first possui qual time está na frente da fila
using namespace std;

int teamBelong[1000001];
queue<int> teamQueue[1001];

int main(){

  int i,t,elem,num,numTeam,numElem,cases=0;

  while(cin >> numTeam, numTeam){
    for(t=0;t<numTeam;t++){
      while(!teamQueue[t].empty())
          teamQueue[t].pop();

      cin >> numElem;
      while(numElem--){
          cin >> elem;
          teamBelong[elem]=t;
        }     
    }
    string op;
    queue<int> here_first;

    printf("Scenario #%d\n",++cases);
    while(cin >> op, op[0]!='S'){
      if(op[0]=='E'){
        cin >> num;
        int team = teamBelong[num];
        if(teamQueue[team].empty()){
          here_first.push(team);
        }
        teamQueue[team].push(num);
      }else{
        int team = here_first.front();
        cout << teamQueue[team].front() <<'\n';
        teamQueue[team].pop();

        if(teamQueue[team].empty())
          here_first.pop();
      }
    }
    printf("\n");
  }

  return 0;
}
