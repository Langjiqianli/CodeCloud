#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<string> s;
map<int,vector<string>> z;
int kuan[2000+5];
int main(){
    string read;
    int n=0;
    while(getline(cin,read)){
        int jik=0;
        string zz;
        for(int i=0;i<read.size();i++){
            if(!zz.empty() and read[i]==' '){
                s.push_back(zz);
                int l=zz.size();
                kuan[jik]=max(kuan[jik],l);
                zz.clear();
                jik++;
            }
            if(read[i]==' ')continue;
            else zz+=read[i];
        }
        if(!zz.empty()){
            s.push_back(zz);
            int l=zz.size();
            kuan[jik]=max(kuan[jik],l);
        }
        z[n++]=s;
        s.clear();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<z[i].size();j++){
            if(j){
                for(int k=0;k<kuan[j-1]-z[i][j-1].size()+1;k++)cout<<" ";
            }
            cout<<z[i][j];
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}