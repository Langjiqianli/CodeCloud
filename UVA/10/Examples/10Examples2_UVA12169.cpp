#include<iostream>
using namespace std;
const int maxn=200+5;
const int m=10001;
int t,x[maxn];
void solve(){
    for(int a=0;a<m;a++){
        for(int b=0;b<m;b++){
            bool ok=true;
            for(int i=2;i<=t*2;i+=2){
                x[i]=(a*x[i-1]+b)%m;
                if(i+1<=t*2 and x[i+1]!=(a*x[i]+b)%m){ok=false;break;}
            }
            if(ok)return;
        }
    }
}
int main(){
    while(cin>>t){
        for(int i=1;i<=t*2-1;i+=2)cin>>x[i];
        solve();
        for(int i=2;i<=t*2;i+=2)cout<<x[i]<<endl;
    }
    system("pause");
    return 0;
}