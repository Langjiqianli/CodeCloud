#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=30+5;
int dp[maxn][maxn];
int n;
struct lft{
    int l[3];
    void srt(){
        sort(l,l+3);
        return;
    }
    lft(){
        l[0]=0;
        l[1]=0;
        l[2]=0;
    }
};
lft s[maxn];
int solve(int i,int j){
    if(dp[i][j]!=-1)return dp[i][j];
    lft&o=s[i];
    int maxh=0;
    for(int x=1;x<=n;x++){
        lft&u=s[x];
        int pd=0;
        int ji=0;
        int yes=0;
        int q=0;
        for(int y=0;y<3;y++){
            if(y==j)y++;
            for(;q+ji<3;){
                if(o.l[y]<u.l[ji+q]){yes++;pd+=ji+q;ji++;break;}
                else q++;
            }
            if(yes==2){
                if(pd==1 and yes==2){
                    maxh=max(maxh,solve(x,0)+s[x].l[0]);
                    maxh=max(maxh,solve(x,1)+s[x].l[1]);
                    maxh=max(maxh,solve(x,2)+s[x].l[2]);
                }
                else if(pd==2 and yes==2){
                    maxh=max(maxh,solve(x,0)+s[x].l[0]);
                    maxh=max(maxh,solve(x,1)+s[x].l[1]);
                }
                else if(pd==3 and yes==2){
                    maxh=max(maxh,solve(x,0)+s[x].l[0]);
                }
            }
        }
    }
    maxh++;
    return dp[i][j]=dp[i][j]+maxh;
}
int main(){
    int lun=1;
    while(cin>>n and n){
        cout<<"Case "<<lun++<<": maximum height = ";
        for(int i=1;i<=n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            s[i].l[0]=a;
            s[i].l[1]=b;
            s[i].l[2]=c;
            s[i].srt();
        }
        memset(dp,-1,sizeof(dp));
        s[0].l[0]=0;
        s[0].l[1]=0;
        s[0].l[2]=0;
        int ans=solve(0,3);
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}