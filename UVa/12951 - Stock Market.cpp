#include <stdio.h>
#include <algorithm>

#define MAX 200005

using namespace std;

int N,C;
int p[MAX],memo[MAX][2];

int answer(){

  memo[N][false] = memo[N][true] = 0;

  for(int day = N-1; day>=0; --day){
    memo[day][false] = max(0,               -(p[day]+C) + memo[day + 1][true ]);
    memo[day][false] = max(memo[day][false],              memo[day + 1][false]);
    memo[day][true]  = max(0,                (p[day])   + memo[day + 1][false]);
    memo[day][true]  = max(memo[day][true],               memo[day + 1][true ]);
  }
  return memo[0][false];
}
int main(){

  //freopen("input.txt","r",stdin);

  while(scanf("%d %d",&N,&C) != EOF){
    for(int i=0;i<N;i++) scanf("%d",&p[i]);
    printf("%d\n",answer());
  }

  return 0;
}
