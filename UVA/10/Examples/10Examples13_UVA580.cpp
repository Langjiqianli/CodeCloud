#include<iostream>
#include<cmath>
using namespace std;
const int maxn=30+1;
int f[maxn],g[maxn];
void cz(){
    for(int n=3;n<maxn;n++){
        f[n]=pow(2,n-3);
        for(int i=2;i<n-1;i++){
            f[n]+=g[i-2]*pow(2,n-i-2);
        }
        g[n]=pow(2,n)-f[n];
    }
}
int main(){
    f[0]=f[1]=f[2]=0;
    g[0]=1;
    g[1]=2;
    g[2]=4;
    cz();
    int n;
    while(scanf("%d",&n) and n){
        printf("%d\n",f[n]);
    }
    system("pause");
    return 0;
}