#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
map<string,string> o;
map<string,string> n;
vector<string> ol;
vector<string> ne;
set<string> add;
set<string> jian;
set<string> gai;
int main(){
    int T;
    cin>>T;
    while(T--){
        getchar();
        while(true){
            string z;
            char a=getchar();
            if(a=='{')continue;
            if(a=='}')break;
            else z=a;
            while(true){
                a=getchar();
                if(a==':')break;
                z+=a;
            }
            string zhi;
            while(true){
                a=getchar();
                if(a==',' or a=='}')break;
                zhi+=a;
            }
            o[z]=zhi;
            ol.push_back(z);
            if(a==',')continue;
            else if(a=='}')break;
        }
        getchar();
        while(true){
            string z;
            char a=getchar();
            if(a=='{')continue;
            if(a=='}')break;
            else z=a;
            while(true){
                a=getchar();
                if(a==':')break;
                z+=a;
            }
            string zhi;
            while(true){
                a=getchar();
                if(a==',' or a=='}')break;
                zhi+=a;
            }
            n[z]=zhi;
            ne.push_back(z);
            if(a==',')continue;
            else if(a=='}')break;
        }
        for(int i=0;i<ne.size();i++)if(!o.count(ne[i]))add.insert(ne[i]);
        for(int i=0;i<ol.size();i++)if(!n.count(ol[i]))jian.insert(ol[i]);
        for(int i=0;i<ne.size();i++){
            if(o.count(ne[i])){
                if(o[ne[i]]!=n[ne[i]])gai.insert(ne[i]);
            }
        }
        if(!add.empty()){int ji=0;cout<<"+";for(set<string>::iterator it=add.begin();it!=add.end();++it){if(ji++)cout<<",";cout<<*it;}cout<<endl;}
        if(!jian.empty()){int ji=0;cout<<"-";for(set<string>::iterator it=jian.begin();it!=jian.end();++it){if(ji++)cout<<",";cout<<*it;}cout<<endl;}
        if(!gai.empty()){int ji=0;cout<<"*";for(set<string>::iterator it=gai.begin();it!=gai.end();++it){if(ji++)cout<<",";cout<<*it;}cout<<endl;}
        if(add.empty() and jian.empty() and gai.empty())cout<<"No changes"<<endl;
        cout<<endl;
        o.clear();
        n.clear();
        add.clear();
        jian.clear();
        gai.clear();
        ol.clear();
        ne.clear();
    }
    system("pause");
    return 0;
}