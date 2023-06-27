#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int INF=10000;
const int maxt=500+5;
const int maxst=100+5;
int hast[maxt*10][maxst][2];
int usti[maxst];
int dp[maxt][maxst];
int main(){
    int lun=1;
    while(true){
        int n;
        scanf("%d",&n);
        if(n==0)break;
        int t;
        scanf("%d",&t);
        for(int i=1;i<n;i++)scanf("%d",&usti[i]);
        memset(hast,0,sizeof(hast));
        int m1;
        scanf("%d",&m1);
        for(int i=1;i<=m1;i++){
            int st;
            scanf("%d",&st);
            hast[st][1][0]=1;
            int last=st;
            for(int w=1;w<n;w++){
                hast[last+usti[w]][w+1][0]=1;
                last+=usti[w];
            }
        }
        int m2;
        scanf("%d",&m2);
        for(int i=1;i<=m2;i++){
            int st;
            scanf("%d",&st);
            hast[st][n][1]=1;
            int last=st;
            for(int w=n;w>2;w--){
                hast[last+usti[w-1]][w-1][1]=1;
                last+=usti[w-1];
            }
        }
        for(int i=0;i<=n-1;i++)dp[t][i]=INF;
        dp[t][n]=0;
        for(int i=t-1;i>=0;i--){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i+1][j]+1;
                if(hast[i][j][0] and i+usti[j]<=t and j<n){
                    dp[i][j]=min(dp[i][j],dp[i+usti[j]][j+1]);
                }
                if(hast[i][j][1] and i+usti[j-1]<=t and j>1){
                    dp[i][j]=min(dp[i][j],dp[i+usti[j-1]][j-1]);
                }
            }
        }
        printf("Case Number %d: ",lun++);
        if(dp[0][1]>=INF)printf("impossible\n");
        else printf("%d\n",dp[0][1]);
    }
    system("pause");
    return 0;
}