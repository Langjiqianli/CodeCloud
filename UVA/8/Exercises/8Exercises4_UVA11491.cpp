#include<iostream>
#include<vector>
using namespace std;
const int maxn=100000+5;
int s[maxn];
vector<int> ans;
int main(){
    int n,d;
    while(cin>>n>>d and n){
        getchar();
        for(int i=0;i<n;i++){
            char a=getchar();
            s[i]=a-'0';
        }
        int an=n-d;
        for(int i=0;i<n and an>0;i++){
            if(n-i==an){while(i<n)ans.push_back(s[i++]);break;}
            int sy=n-d;
            int wei=i,max=s[i];
            for(int x=i;x<=n-an;x++){
                if(s[x]>max){wei=x;max=s[x];}
            }
            ans.push_back(max);
            i=wei;
            an--;
        }
        for(int i=0;i<ans.size();i++)cout<<ans[i];
        cout<<endl;
        ans.clear();
    }
    system("pasue");
    return 0;
}