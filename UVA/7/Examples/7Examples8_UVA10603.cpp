#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node{
    int v[3],dist;
    bool operator < (const node&rhs)const{
        return dist>rhs.dist;
    }
};
const int maxn=200+5;
int vis[maxn][maxn],cap[3],ans[maxn];
void updateans(const node&u){
    for(int i=0;i<3;i++){
        int d=u.v[i];
        if(ans[d]<0 or u.dist<ans[d])ans[d]=u.dist;
    }
}
void solve(int a,int b,int c,int d){
    cap[0]=a;
    cap[1]=b;
    cap[2]=c;
    memset(vis,0,sizeof(vis));
    memset(ans,-1,sizeof(ans));
    priority_queue<node> q;
    node start;
    start.dist=0;
    start.v[0]=0;
    start.v[1]=0;
    start.v[2]=c;
    q.push(start);
    vis[0][0]=1;
    while(!q.empty()){
        node u=q.top();
        q.pop();
        updateans(u);
        if(ans[d]>=0)break;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)if(i!=j){
                if(u.v[i]==0 or u.v[j]==cap[j])continue;
                int amount=min(cap[j],u.v[i]+u.v[j])-u.v[j];
                node u2;
                memcpy(&u2,&u,sizeof(u));
                u2.dist=u.dist+amount;
                u2.v[i]-=amount;
                u2.v[j]+=amount;
                if(!vis[u2.v[0]][u2.v[1]]){
                    vis[u2.v[0]][u2.v[1]]=1;
                    q.push(u2);
                }
            }
        }
    }
    while(d>=0){
        if(ans[d]>=0){
            printf("%d %d\n",ans[d],d);
            return;
        }
        d--;
    }
}
int main(){
    int T,a,b,c,d;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        solve(a,b,c,d);
    }
    system("pause");
    return 0;
}