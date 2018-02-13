#include <bits/stdc++.h>

using namespace std;
#define MAX 1000
#define MIN 100

vector <int> dna[26];
int flag[26], n, len;
char ans[MAX], str[MIN];

void dfs(int x){
    flag[x]=3;
    for(int i=0;i<dna[x].size();i++){
        if(flag[dna[x][i]]!=3) //check if it was visited
            dfs(dna[x][i]);
    }
    ans[len++]='a'+x;
}
int main(){
    
    while(cin>>n)
    {
        
        len=0;
        while(n--)
        {
            scanf("%s", &str);
            for(int i=0; i<strlen(str)-1; i++){
                dna[str[i]-'a'].push_back(str[i+1]-'a');
                flag[str[i+1]-'a']=2;
            }
            //first char is 1
            if(flag[str[0]-'a']!=2)
                flag[str[0]-'a']=1;
        }
        for(int i=0;i<26;i++){
            //start for all neighbors
            if(flag[i]==1)
                dfs(i);
        }
        for(int i=len-1;i>=0;i--)
            cout<<ans[i];
        cout<<endl;

    }
    return 0;
}
