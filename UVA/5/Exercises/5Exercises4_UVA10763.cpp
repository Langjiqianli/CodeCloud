#include<algorithm>
#include<iostream>
#include<set>
#include<map>
using namespace std;
map<int,map<int,int>> s;
set<int> dz;
int main(){
    int n;
    while(scanf("%d",&n)==1 and n){
        for(int i=0;i<n;i++){
            int c,m;
            scanf("%d %d",&c,&m);
            if(!s[c].count(m))s[c][m]=0;
            s[c][m]++;
            dz.insert(c);
            dz.insert(m);
        }
        int ji=n;
        dz.size();
        for(set<int>::iterator it1=dz.begin();it1!=dz.end();++it1){
            for(set<int>::iterator it2=dz.begin();it2!=dz.end();++it2){
                int c1=*it1,m1=*it2;
                int c2=*it2,m2=*it1;
                if(s[c1].count(m1) and s[c2].count(m2)){
                    if(s[c1][m1]>0 and s[c2][m2]>0){
                        int a=min(s[c1][m1],s[c2][m2]);
                        ji-=2*a;
                        s[c1][m1]-=a;
                        s[c2][m2]-=a;
                    }
                }
            }
        }
        if(ji==0)printf("YES\n");
        else printf("NO\n");
    }
    system("pause");
    return 0;
}