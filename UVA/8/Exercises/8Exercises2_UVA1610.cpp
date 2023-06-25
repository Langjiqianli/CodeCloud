#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1000+5;
string s[maxn];
int main(){
    int n;
    while(cin>>n and n){
        for(int i=0;i<n;i++)cin>>s[i];
        sort(s,s+n);
        int m=n/2;
        string f=s[m-1];
        string r=s[m];
        string ans;
        int cur=0;
        while(true){
            ans+='A';
            while(ans[cur]<'Z' and ans<f)ans[cur]++;
            if(ans>=r)ans[cur]--;
            if(ans>=f and ans<r)break;
            cur++;
        }
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}