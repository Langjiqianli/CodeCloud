#include<iostream>
#include<cstring>
using namespace std;
const int maxn=100+5;
int n,m;
int c[maxn];
int topo[maxn],t;
int g[maxn][maxn];
bool dfs(int u){
    c[u]=-1;
    for(int v=0;v<n;v++)if(g[u][v]){
        if(c[v]<0)return false;
        else if(!c[v] and !dfs(v))return false;
    }
    c[u]=1;
    topo[--t]=u;
    return true;
}
bool toposort(){
    t=n;
    memset(c,0,sizeof(c));
    for(int u=0;u<n;u++)if(!c[u])if(!dfs(u))return false;
    return true;
}
int main(){
    while(scanf("%d%d",&n,&m) and n){
        memset(g,0,sizeof(g));
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            g[a-1][b-1]=1;
        }
        toposort();
        for(int i=0;i<n;i++){
            if(i)printf(" ");
            printf("%d",topo[i]+1);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}