#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>>s;
int main(){
    int n;
    while(cin>>n and n){
        int ans=0;
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            s.push(a);
        }
        if(n==1)ans=s.top();
        else while(s.size()>1){
            int zz=0;
            zz+=s.top();
            s.pop();
            zz+=s.top();
            s.pop();
            ans+=zz;
            s.push(zz);
        }
        printf("%d\n",ans);
        while(!s.empty())s.pop();
    }
    system("pause");
    return 0;
}