#include<iostream>
#include<map>
#include<set>
using namespace std;
const int maxn=120005;
string s [maxn];
map<string,int> dz;
set<string> zz;
int main(){
    string in;
    int ji=0;
    while(cin>>in){
        s[ji++]=in;
        dz[in]=1;
    }
    for(int i=0;i<ji;i++){
        int l=s[i].length();
        for(int ii=0;ii<l;ii++){
            string s1=s[i].substr(0,ii);
            string s2=s[i].substr(ii);
            if(dz.count(s1) and dz.count(s2))zz.insert(s[i]);
        }
    }
    for(set<string>::iterator it=zz.begin();it!=zz.end();++it)cout<<*it<<endl;
    system("pause");
    return 0;
}