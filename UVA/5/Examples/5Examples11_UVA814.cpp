#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
void ParseAddress(const string&s,string&user,string&mta){
    int k=s.find('@');
    user=s.substr(0,k);
    mta=s.substr(k+1);
}
int main(){
    int k;
    string s,t,user1,user2,mta1,mta2;
    set<string>addr;
    while(cin>>s and s!="*"){
        cin>>s>>k;
        while(k--){
            cin>>t;
            addr.insert(t+"@"+s);
        }
    }
    while(cin>>s and s!="*"){
        ParseAddress(s,user1,mta1);
        vector<string>mta;
        map<string,vector<string>>dest;
        set<string>vis;
        while(cin>>t and t!="*"){
            ParseAddress(t,user2,mta2);
            if(vis.count(t))continue;
            vis.insert(t);
            if(!dest.count(mta2)){
                mta.push_back(mta2);
                dest[mta2]=vector<string>();
            }
            dest[mta2].push_back(t);
        }
        getline(cin,t);
        string data;
        while(getline(cin,t) and t[0]!='*')data+="     "+t+"\n";
        for(int i=0;i<mta.size();i++){
            string mta2=mta[i];
            vector<string>users=dest[mta2];
            cout<<"Connection between "<<mta1<<" and "<<mta2<<endl;
            cout<<"     HELO "<<mta1<<"\n";
            cout<<"     250\n";
            cout<<"     MAIL FROM:<"<<s<<">\n";
            cout<<"     250\n";
            bool ok=false;
            for(int i=0;i<users.size();i++){
                cout<<"     RCPT TO:<"<<users[i]<<">\n";
                if(addr.count(users[i])){
                    ok=true;
                    cout<<"     250\n";
                }else cout<<"     550\n";
            }
            if(ok){
                cout<<"     DATA\n";
                cout<<"     354\n";
                cout<<data;
                cout<<"     .\n";
                cout<<"     250\n";
            }
            cout<<"     QUIT\n";
            cout<<"     221\n";
        }
    }
    system("pause");
    return 0;
}