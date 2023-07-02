#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int maxn=1000;
vector<set<char>> d;
vector<set<char>> s;
string ans[maxn];
vector<int> zai;
set<char> zz;
int ji;
void cz(string z="",int w=0){
    if(w==zai.size())return;
    if(ji>800)return;
    for(auto it=s[zai[w]].begin();it!=s[zai[w]].end();++it){
        if(w+1==zai.size())ans[ji++]=z+*it;
        else cz(z+*it,w+1);
        if(ji>800)return;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int k;
        cin>>k;
        zz.clear();
        for(int i=0;i<5;i++)d.push_back(zz);
        for(int i=0;i<6;i++){
            string z;
            cin>>z;
            for(int j=0;j<5;j++){
                if(d[j].count(z[j]))continue;
                else d[j].insert(z[j]);
            }
        }
        for(int i=0;i<5;i++)s.push_back(zz);
        for(int i=0;i<6;i++){
            string z;
            cin>>z;
            for(int j=0;j<5;j++){
                if(d[j].count(z[j]))s[j].insert(z[j]);
            }
        }
        int sum=1;
        for(int i=0;i<5;i++)sum*=s[i].size();
        if(sum<k)cout<<"NO"<<endl;
        else{
            ji=1;
            for(int i=0;i<5;i++){
                if(!s[i].empty())zai.push_back(i);
            }
            cz();
            cout<<ans[k]<<endl;
        }
        d.clear();
        s.clear();
        zai.clear();
    }
    system("pause");
    return 0;
}