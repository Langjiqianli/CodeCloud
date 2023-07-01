#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
vector<int> s;
vector<int> zz;
set<vector<int>> cun;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            s.push_back(a);
        }
        while(true){
            int sum=0;
            for(int i=0;i<s.size();i++){
                if(i+1<s.size())zz.push_back(abs(s[i]-s[i+1]));
                else zz.push_back(abs(s[0]-s[i]));
            }
            s.clear();
            for(int i=0;i<zz.size();i++)s.push_back(zz[i]);
            if(cun.count(zz))break;
            cun.insert(zz);
            zz.clear();
        }
        bool zero=true;
        for(int i=0;i<zz.size();i++){
            if(zz[i]!=0){zero=false;break;}
        }
        if(zero)printf("ZERO\n");
        else printf("LOOP\n");
        s.clear();
        zz.clear();
        cun.clear();
    }
    system("pause");
    return 0;
}