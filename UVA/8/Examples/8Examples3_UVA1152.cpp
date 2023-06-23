#include<unordered_map>
#include<iostream>
using namespace std;
const int maxn=4000+5;
int a[maxn],b[maxn],c[maxn],d[maxn];
int abz[maxn*maxn];
unordered_map<int,int> ab;
unordered_map<int,int> cd;
void input(int z,unordered_map<int,int>&s){
    if(!s.count(z))s[z]=0;
    s[z]++;
    return;
}
int main(){
    int lun;
    int kong=0;
    scanf("%d",&lun);
    while(lun--){
        if(kong++!=0)printf("\n");
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int ac,bc,cc,dc;
            scanf("%d%d%d%d",&ac,&bc,&cc,&dc);
            a[i]=ac;
            b[i]=bc;
            c[i]=cc;
            d[i]=dc;
        }
        int ji=0;
        int answer=0;
        for(int i=0;i<n;i++)for(int ii=0;ii<n;ii++)input(a[i]+b[ii],ab);
        for(int i=0;i<n;i++)for(int ii=0;ii<n;ii++)if(ab.count(-c[i]-d[ii]))answer+=ab[-c[i]-d[ii]];
        printf("%d\n",answer);
        ab.clear();
        cd.clear();
    }
    system("pause");
    return 0;
}