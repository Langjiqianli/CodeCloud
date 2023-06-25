#include<iostream>
using namespace std;
const int maxn=100000+5;
int p[maxn];
int q[maxn];
int n;
int pd(int s){
    int oil=0;
    int ans=-1;
    for(int i=0;i<n;i++){
        int d=(s+i)%n;
        oil+=p[d];
        if(oil<q[d]){
            ans=d;
            break;
        }
        oil-=q[d];
    }
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
        printf("Case %d: ",ti);
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&p[i]);
        for(int i=0;i<n;i++)scanf("%d",&q[i]);
        int ans=-1;
        for(int st=0;st<n;st++){
            if(pd(st)==-1){ans=st;break;}
            else{int z=pd(st);if(st<=z)st=z;else break;}
        }
        if(ans==-1)printf("Not possible\n");
        else printf("Possible from station %d\n",ans+1);
    }
    system("pause");
    return 0;
}