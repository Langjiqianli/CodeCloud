#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
const int maxn=100+5;
map<char,string> dz;
string word[maxn];
string wordjie[maxn];
string zanc1[maxn];
string zanc2[maxn];
int mincy[maxn];
string cz(string s){
    string ans="";
    for(int i=0;i<s.size();i++){
        ans+=dz[s[i]];
    }
    return ans;
}
int pd(string a,string b){
    int l=min(a.size(),b.size());
    int ans=a.size()-b.size();
    for(int i=0;i<l;i++){
        if(a[i]!=b[i]){ans=0;break;}
    }
    return abs(ans);
}
int main(){
    char zz;
    while(cin>>zz and zz!='*'){
        string zzw;
        cin>>zzw;
        dz[zz]=zzw;
    }
    int ji=0;
    string jz;
    while(cin>>jz and jz!="*"){
        word[ji]=jz;
        wordjie[ji++]=cz(jz);
    }
    string h=jz;
    string mm;
    while(cin>>mm and mm!="*"){
        memset(zanc1,0,sizeof(zanc1));
        memset(zanc2,0,sizeof(zanc2));
        memset(mincy,-1,sizeof(mincy));
        bool wan=false;
        int jimm=0;
        for(int i=0;i<ji;i++){
            if(mm==wordjie[i]){
                zanc1[jimm++]=word[i];
                wan=true;
            }
        }
        if(wan){
            cout<<zanc1[0];
            if(jimm>1)cout<<"!";
            cout<<endl;
        }else{
            int jinm=0;
            for(int i=0;i<ji;i++){
                if(pd(mm,wordjie[i])!=0){
                    zanc2[jinm]=word[i];
                    mincy[jinm++]=pd(mm,wordjie[i]);
                }
            }
            int minc=100000;
            for(int i=0;i<jinm;i++){
                if(minc>mincy[i])minc=mincy[i];
            }
            int zzid;
            for(int i=0;i<jinm;i++)if(minc==mincy[i]){zzid=i;break;}
            cout<<zanc2[zzid]<<"?"<<endl;
        }
    }
    system("pause");
    return 0;
}