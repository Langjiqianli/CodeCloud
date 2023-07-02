#include<iostream>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        double a0=0,a1=0;
        double a00=0,a01=0;
        char last=s[s.size()-1];
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                a0++;
                if(last=='0')a00++;
            }
            if(s[i]=='1'){
                a1++;
                if(last=='0')a01++;
            }
            last=s[i];
        }
        double sh;
        if(a00==0)sh=0;
        else sh=a00/(a00+a01);
        double ro;
        if(a0==0)ro=0;
        else ro=a0/(a0+a1);
        if(sh==ro)cout<<"EQUAL"<<endl;
        else if(sh>ro)cout<<"SHOOT"<<endl;
        else if(sh<ro)cout<<"ROTATE"<<endl;
        s.clear();
    }
    system("pause");
    return 0;
}