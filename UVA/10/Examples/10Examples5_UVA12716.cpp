#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=30000000+5;
ll ji[maxn];
ll ans[maxn];
void cz(){
    memset(ji,0,sizeof(ji));
    for(ll c=1;c<=maxn;c++){
        for(ll a=c*2;a<=maxn;a+=c){
            if(c==(a^(a-c)))ji[a]++;
        }
    }
    for(int i=1;i<=maxn;i++){
        ans[i]=ans[i-1]+ji[i];
    }
}
int main(){
    cz();
    int T;
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
        printf("Case %d: ",ti);
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",ans[n]);
    }
    system("pause");
    return 0;
}