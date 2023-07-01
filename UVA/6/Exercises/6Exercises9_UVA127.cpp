#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<stack<string>> s;
stack<string> zz;
void del(){
    for(int i=0;i<s.size();i++){
        auto it=s.begin()+i;
        if((*it).empty()){
            s.erase(it);
        }
    }
}
bool pd(int l,int r){
    if(s[l].top()[0]==s[r].top()[0])return true;
    if(s[l].top()[1]==s[r].top()[1])return true;
    return false;
}
bool cz(int w){
    if(w-3>=0){
        if(pd(w-3,w)){
            string z=s[w].top();
            s[w].pop();
            s[w-3].push(z);
            del();
            return true;
        }
    }
    if(w-1>=0){
        if(pd(w-1,w)){
            string z=s[w].top();
            s[w].pop();
            s[w-1].push(z);
            del();
            return true;
        }
    }
    return false;
}
int main(){
    while(true){
        bool br=false;
        for(int i=0;i<52;i++){
            string a;
            cin>>a;
            if(a=="#"){br=true;break;}
            zz.push(a);
            s.push_back(zz);
            zz.pop();
        }
        if(br)break;
        for(int i=0;i<s.size();i++){
            int ji=cz(i);
            if(ji)i=0;
        }
        if(s.size()==1){
            cout<<"1 pile remaining: 52"<<endl;
        }else{
            cout<<s.size()<<" piles remaining:";
            for(int i=0;i<s.size();i++){
                cout<<" "<<s[i].size();
            }
            cout<<endl;
        }
        s.clear();
    }
    system("pause");
    return 0;
}