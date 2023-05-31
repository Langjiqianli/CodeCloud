#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
map<string,int> ji;
vector<string> word;
string re(const string& s){
    string a=s;
    for(int i=0;i<a.length();i++)a[i]=tolower(a[i]);
    sort(a.begin(),a.end());
    return a;
}
int main(){
    string s;
    while(cin>>s){
        if(s[0]=='#')break;
        word.push_back(s);
        string r=re(s);
        if(!ji.count(r))ji[r]=0;
        ji[r]++;
    }
    vector<string> z;
    for(int i=0;i<word.size();i++)if(ji[re(word[i])]==1)z.push_back(word[i]);
    sort(z.begin(),z.end());
    for(int i=0;i<z.size();i++){
        cout<<z[i]<<endl;
    }
    system("pause");
    return 0;
}