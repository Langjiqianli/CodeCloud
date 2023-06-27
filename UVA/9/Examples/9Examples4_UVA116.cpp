#include<algorithm>
#include<iostream>
using namespace std;
const int INF=100000;
const int maxn=100+5;
int s[maxn][maxn];
int d[maxn][maxn];
int nxt[maxn][maxn];
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        for(int y=0;y<m;y++)for(int x=0;x<n;x++)scanf("%d",&s[y][x]);
        int ans=INF,first=0;
        for(int j=n-1;j>=0;j--){
            for(int i=0;i<m;i++){
                if(j==n-1)d[i][j]=s[i][j];
                else{
                    int rows[3]={i,i-1,i+1};
                    if(i==0)rows[1]=m-1;
                    if(i==m-1)rows[2]=0;
                    sort(rows,rows+3);
                    d[i][j]=INF;
                    for(int k=0;k<3;k++){
                        int v=d[rows[k]][j+1]+s[i][j];
                        if(v<d[i][j]){d[i][j]=v;nxt[i][j]=rows[k];}
                    }
                }
                if(j==0 and d[i][j]<ans){ans=d[i][j];first=i;}
            }
        }
        printf("%d",first+1);
        for(int i=nxt[first][0],j=1;j<n;i=nxt[i][j],j++)printf(" %d",i+1);
        printf("\n%d\n",ans);
    }
    system("pause");
    return 0;
}