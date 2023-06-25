#include<iostream>
#include<cmath>
using namespace std;
int n;
long long czd(int mn,int end,long long s){
    if(end==0)return 0;
    if(end==1 and mn==2)return s/3*2;
    int m=mn-mn/2;
    if(end<mn){
        long long ji=s/3*2;
        long long zz;
        if(end>=m){zz=czd(mn-m,end-m,s/3);return ji+zz;}
        else{zz=czd(mn-m,end,s/3*2);return zz;}
    }else if(end==mn)return s;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
        printf("Case %d: ",ti);
        int st,end;
        scanf("%d%d%d",&n,&st,&end);
        long long ans=czd(pow(2,n),end,pow(3,n))-czd(pow(2,n),st-1,pow(3,n));
        printf("%lld\n",ans);
    }
    system("pause");
    return 0;
}