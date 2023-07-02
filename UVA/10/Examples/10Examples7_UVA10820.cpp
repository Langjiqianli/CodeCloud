#include<iostream>
#include<cmath>
using namespace std;
const int maxn=50000+5;
int euler_phi(int n){
    int m=(int)sqrt(n+0.5);
    int ans=n;
    for(int i=2;i<=m;i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ans=ans/n*(n-1);
    return ans;
}
int cun[maxn];
int f[maxn];
void cz(){
    for(int i=1;i<maxn;i++){
        cun[i]=euler_phi(i);
    }
    for(int i=2;i<maxn;i++){
        if(i==2)f[i]=cun[2];
        else f[i]=f[i-1]+cun[i];
    }
}
int main(){
    cz();
    int n;
    while(scanf("%d",&n) and n){
        if(n==1)printf("1\n");
        else printf("%d\n",f[n]*2+1);
    }
    system("pause");
    return 0;
}