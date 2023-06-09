#include<iostream>
#include<cstring>
using namespace std;
const int maxn=100+5;
char pic[maxn][maxn];
int m,n,idx[maxn][maxn];
void dfs(int r,int c,int id){
    if(r<0 or r>=m or c<0 or c>=n)return;
    if(idx[r][c]>0 or pic[r][c]!='@')return;
    idx[r][c]=id;
    for(int dr=-1;dr<=1;dr++){
        for(int dc=-1;dc<=1;dc++){
            if(dr!=0 or dc!=0)dfs(r+dr,c+dc,id);
        }
    }
}
int main(){
    while(scanf("%d%d",&m,&n)==2 and m and n){
        for(int i=0;i<m;i++)scanf("%s",pic[i]);
        memset(idx,0,sizeof(idx));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(idx[i][j]==0 and pic[i][j]=='@')dfs(i,j,++cnt);
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}