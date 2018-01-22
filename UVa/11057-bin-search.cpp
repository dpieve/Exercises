#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

long long int arr[10000],a,b,x,y;

int bs(int left,int right, int key){
  while(left <= right){
    int mid = (left + right)/2;
    if(arr[mid] < key)
      left = mid + 1;
    else if(arr[mid] > key)
      right = mid-1;
    else return mid;
  }
  return -1;
}
int main(){

  int n,i,j;
  
  while(scanf("%d",&n)==1){
    for(i=0; i<n; i++)
      scanf("%lld",&arr[i]);

    sort(arr,arr+n);
    long long int sum;
    scanf("%lld",&sum);

    a = -1001; b = 1000001;
    for(i=0;i<n-1;i++){
      j = bs(0,n-1,sum-arr[i]);
      if(j!=-1){
        x = arr[i]; y = arr[j];
        if((abs(y-x) < abs(b-a)) && (x+y==sum)){
          a=min(x,y);
          b=max(x,y);
        }
      }
    }

    if(a<=b)
      printf("Peter should buy books whose prices are %lld and %lld.\n",a,b);
    else
      printf("Peter should buy books whose prices are %lld and %lld.\n",b,a);

    puts("");
    getchar();
  }

  return 0;
}

/*solution(2)
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
 
  int n;
  long long int arr[10000],a,b;
  while(scanf("%d",&n)==1){
    for(int i=0; i<n; i++)
      scanf("%lld",&arr[i]);

    sort(arr,arr+n);
    long long int sum;
    scanf("%lld",&sum);

    a=-100; b= 1000001;
    bool ans = false;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(arr[i]+arr[j] == sum){
          if(arr[j]-arr[i] < b-a){
            a=arr[i];
            b=arr[j];
          }
        }
      }
    }
    printf("Peter should buy books whose prices are %lld and %lld.\n",a,b);
    puts("");
    getchar();
  }

  return 0;
}
*/
