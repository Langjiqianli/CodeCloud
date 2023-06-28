#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=100+5;
int s[maxn][maxn];
int d[maxn*maxn][4];
int dp[maxn*maxn][4];
int m,n;
int solve(int i,int j){
    dp[i][j]=0;
    int big=0;
    if(d[i][0] and j!=1)big=max(big,solve(i-n,0)+1);
    if(d[i][1] and j!=0)big=max(big,solve(i+n,1)+1);
    if(d[i][2] and j!=3)big=max(big,solve(i-1,2)+1);
    if(d[i][3] and j!=2)big=max(big,solve(i+1,3)+1);
    return dp[i][j]=big;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        string name;
        cin>>name;
        cin>>m>>n;
        int id=0;
        memset(s,0,sizeof(s));
        for(int y=0;y<m;y++)for(int x=0;x<n;x++)cin>>s[y][x];
        memset(d,0,sizeof(d));
        for(int i=0;i<m*n;i++){
            int x=i%n;
            int y=i/n;
            if(y-1>=0 and s[y][x]<s[y-1][x])d[i][0]=1;
            if(y+1<m and s[y][x]<s[y+1][x])d[i][1]=1;
            if(x-1>=0 and s[y][x]<s[y][x-1])d[i][2]=1;
            if(x+1<n and s[y][x]<s[y][x+1])d[i][3]=1;
        }
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<m*n;i++){
            ans=max(ans,solve(i,6));
        }
        ans++;
        cout<<name<<": "<<ans<<endl;
    }
    system("pause");
    return 0;
}