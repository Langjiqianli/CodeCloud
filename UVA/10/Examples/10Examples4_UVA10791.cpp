#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll n;
ll cz(ll n){
    int shu=0;
    ll ans=0;
    for(int i=2;i<=sqrt(n+0.5);i++){
        if(n%i==0){
            shu++;
            ll ji=1;
            while(n%i==0){
                n/=i;
                ji*=i;
            }
            ans+=ji;
        }
    }
    if(n>1){ans+=n;shu++;}
    if(shu==1)ans+=1;
    return ans;
}
int main(){
    int kase=1;
    while(scanf("%lld",&n) and n){
        printf("Case %d: ",kase++);
        if(n==1){printf("2\n");continue;}
        printf("%lld\n",cz(n));
    }
    system("pause");
    return 0;
}