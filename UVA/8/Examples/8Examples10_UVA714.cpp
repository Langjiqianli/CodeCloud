#include<iostream>
#include<cstring>
using namespace std;
const int maxn=500+5;
long long s[maxn];
long long cd[maxn*2];
long long n,k;
long long bmax;
bool pd(long long p,long long j,long long z){
    long long cur=0;
    j--;
    for(int i=0;i<n;i++){
        cur+=s[i];
        z-=s[i];
        if(cur+s[i+1]>p and i<n-1 and j){
            cur=0;
            j--;
            if(j==0)break;
        }
    }
    if(z>p)return false;
    else return true;
}
long long search(long long z){
    long long l=bmax,r=z;
    while(l<=r){
        int m=(l+r)/2;
        if(pd(m,k,z))r=m-1;
        else l=m+1;
    }
    return l;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        long long z=0;
        for(int i=0;i<n;i++){
            long long a;
            scanf("%lld",&a);
            if(!i)bmax=a;
            if(bmax<a)bmax=a;
            z+=a;
            s[i]=a;
        }
        long long p=search(z);
        k--;
        long long cur=0;
        memset(cd,0,sizeof(cd));
        for(int i=n-1;i>=0;i--){
            if(k==i and k){
                k--;
                cd[i+i-1]=1;
                continue;
            }
            cur+=s[i];
            if(cur+s[i-1]>p and i-1>=0 and k){
                cur=0;
                k--;
                cd[i+i-1]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(i)printf(" ");
            printf("%lld",s[i]);
            if(cd[i+i+1])printf(" /");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}