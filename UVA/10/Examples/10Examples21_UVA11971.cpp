#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
        ll n,k;
        scanf("%lld%lld",&n,&k);
        ll l=pow(2,k)-k-1;
        ll r=pow(2,k);
        ll z=gcd(l,r);
        l/=z;
        r/=z;
        if(l==0)printf("Case #%d: %lld/%lld\n",ti,l,r);
        else printf("Case #%d: %lld/%lld\n",ti,l,r);
    }
    system("pause");
    return 0;
}