#include<iostream>
using namespace std;
bool solve(int& w){
    int w1,d1,w2,d2;
    bool b1=true,b2=true;
    cin>>w1>>d1>>w2>>d2;
    if(!w1)b1=solve(w1);
    if(!w2)b2=solve(w2);
    w=w1+w2;
    return b1 and b2 and (w1*d1==w2*d2);
}
int main(){
    int t,w;
    cin>>t;
    while(t--){
        if(solve(w))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        if(t)cout<<endl;
    }
    return 0;
}