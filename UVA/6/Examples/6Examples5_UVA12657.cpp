#include<iostream>
using namespace std;
const int maxn=100000+5;
int rt[maxn];
int lf[maxn];
void link(int l,int r){
    rt[l]=r;
    lf[r]=l;
    return;
}
int main(){
    int n,m,kase=0;
    while(scanf("%d%d",&n,&m)==2){
        for(int i=1;i<=n;i++){
            lf[i]=i-1;
            rt[i]=(i+1)%(n+1);
        }
        rt[0]=1;
        lf[0]=n;
        int op,x,y,inv=0;
        while(m--){
            scanf("%d",&op);
            if(op==4)inv=!inv;
            else{
                scanf("%d%d",&x,&y);
                if(op==3 and rt[y]==x)swap(x,y);
                if(op!=3 and inv)op=3-op;
                if(op==1 and x==lf[y])continue;
                if(op==2 and x==rt[y])continue;
                int lx=lf[x],rx=rt[x],ly=lf[y],ry=rt[y];
                if(op==1){
                    link(lx,rx);
                    link(ly,x);
                    link(x,y);
                }else if(op==2){
                    link(lx,rx);
                    link(y,x);
                    link(x,ry);
                }else if(op==3){
                    if(rt[x]==y){
                        link(lx,y);
                        link(y,x);
                        link(x,ry);
                    }else{
                        link(lx,y);
                        link(y,rx);
                        link(ly,x);
                        link(x,ry);
                    }
                }
            }
        }
        int b=0;
        long long ans=0;
        for(int i=1;i<=n;i++){
            b=rt[b];
            if(i%2==1)ans+=b;
        }
        if(inv and n%2==0)ans=(long long)n*(n+1)/2-ans;
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
}