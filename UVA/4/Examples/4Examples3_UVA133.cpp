#include<iostream>
using namespace std;
int go(int a[],int k,int fang,int n,int wei){
    while(k>0){
        while(a[wei]==0)wei=(wei+fang+n)%n;
        k--;
        if(k!=0)wei=(wei+fang+n)%n;
    }
    return wei;
}
int main(){
    int n,k,m;
    while(scanf("%d %d %d",&n,&k,&m)and n){
        int o[n];
        for(int i=0;i<n;i++)o[i]=i+1;
        int ren=n;
        int p1=0,p2=n-1;
        while(ren>0){
            p1=go(o,k,1,n,p1);
            p2=go(o,m,-1,n,p2);
            printf("%3d",o[p1]);
            ren--;
            if(p1!=p2){
                ren--;
                printf("%3d",o[p2]);
            }
            if(ren)printf(",");
            o[p1]=0;
            o[p2]=0;
        }
        printf("\n");
    }
    system("pause");
    return 0;
}