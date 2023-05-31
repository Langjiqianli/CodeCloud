#include<iostream>
#include<set>
#include<sstream>
using namespace std;
set<string> word;
int main(){
    string s,a;
    while(cin>>s){
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i]))s[i]=tolower(s[i]);
            else s[i]=' ';
        }
        stringstream ss(s);
        while(ss>>a)word.insert(a);
    }
    for(set<string>::iterator it=word.begin();it!=word.end();it++)cout<<*it<<endl;
    system("pause");
    return 0;
}