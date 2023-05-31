#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<map>
using namespace std;
typedef set<int> Set;
map<Set,int> id;
vector<Set> seet;
int ID(Set x){
    if(id.count(x))return id[x];
    seet.push_back(x);
    return id[x]=seet.size()-1;
}
int main(){
    stack<int> st;
    int t;
    cin>>t;
    for(int ti=0;ti<t;ti++){
        int n;
        cin>>n;
        for(int inx=0;inx<n;inx++){
            string cz;
            cin>>cz;
            if(cz[0]=='P')st.push(ID(Set()));
            else if(cz[0]=='D')st.push(st.top());
            else{
                Set s1=seet[st.top()];
                st.pop();
                Set s2=seet[st.top()];
                st.pop();
                Set x;
                if(cz[0]=='U') set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(x,x.begin()));
                if(cz[0]=='I') set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(x,x.begin()));
                if(cz[0]=='A') {x=s2,x.insert(ID(s1));}
                st.push(ID(x));
            }
            cout<<seet[st.top()].size()<<endl;
        }
        cout<<"***"<<endl;
    }
    system("pause");
    return 0;
}