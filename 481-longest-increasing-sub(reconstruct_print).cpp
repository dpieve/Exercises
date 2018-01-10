#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int best_end;
int arr[1000000], lis[1000000], prev[1000000];

void reconstruct_print(int end){
  if(end<0) return;
  reconstruct_print(prev[end]);
  printf("%d\n",arr[end]);
}
int loong(int n){

  int max_len=1;
  lis[0]=1; prev[0]=-1;

  for(int i=1;i<n;i++){
    lis[i]=1; prev[i]=-1;

    for(int j=0;j<i;j++){
      if(arr[i] > arr[j] && lis[i] <= lis[j]+1){
        lis[i] = lis[j]+1;
        prev[i]= j;
      }
    }
    // '>=' Because -> More than one LIS, output print the one that occurs LAST. 
    if(lis[i] >= max_len){
      best_end=i;
      max_len = lis[i];
    }
  }

  return max_len;
}

int main(){

  //freopen("input.txt","r",stdin);

  int pos=0,num;
  while(cin >> num)
    arr[pos++]=num;
  
  printf("%d\n-\n",loong(pos));
  reconstruct_print(best_end);

  return 0;
}
/*
another way to print
void reconstruct_print(int end){
  int x = end;
  stack<int> s;

  for(;prev[x]>=0; x=prev[x]){
    s.push(arr[x]);
  }
  s.push(arr[x]);

  for(;!s.empty();s.pop()){
      cout << s.top() << endl;
  }
}*/

