#include<iostream>
#include<string.h>
#include<set>
using namespace std;
const int bookmax=105;
set<int> retuid;
set<string> zuozhe;
set<string> namez;
struct book{
    string name,au;
    int zai;
    book(string a,string b,int c=0):name(a),au(b),zai(c){}
    book(){}
};
char za [100],zn [100];
book s[bookmax];
book sz[bookmax];
int main(){
    int n=0;
    int ji=0;
    for(;;){
        string bookname,author;
        memset(zn,0,100);
        for(int i=0;;i++){
            char r;
            r=getchar();
            zn[i]=r;
            if(r=='"' and i>0)break;
            if(zn[0]=='E' and zn[1]=='N' and zn[2]=='D')break;
        }
        if(zn[0]=='E' and zn[1]=='N' and zn[2]=='D')break;
        bookname=zn;
        string by;
        cin>>by;
        getchar();
        memset(za,0,100);
        for(int i=0;;i++){
            char r;
            r=getchar();
            if(r=='\n')break;
            za[i]=r;
        }
        author=za;
        book a(bookname,author,1);
        s[ji++]=a;
        zuozhe.insert(author);
        n++;
    }
    int jizz=0;
    for(set<string>::iterator it=zuozhe.begin();it!=zuozhe.end();++it){
        for(int i=0;i<n;i++)if(s[i].au==*it) namez.insert(s[i].name);
        for(set<string>::iterator it1=namez.begin();it1!=namez.end();++it1){
            for(int i=0;i<n;i++)if(s[i].name==*it1)sz[jizz++]=s[i];
        }
        namez.clear();
    }
    for(int i=0;i<n;i++)s[i]=sz[i];
    for(;;){
        string cz,bookname;
        cin>>cz;
        if(cz[0]=='B'){
            getchar();
            memset(zn,0,100);
            for(int i=0;;i++){
                char r;
                r=getchar();
                zn[i]=r;
                if(r=='"' and i>0)break;
            }
            bookname=zn;
            for(int i=0;i<n;i++)if(s[i].name==bookname)s[i].zai=0;
        } 
        if(cz[0]=='R'){
            getchar();
            memset(zn,0,100);
            for(int i=0;;i++){
                char r;
                r=getchar();
                zn[i]=r;
                if(r=='"' and i>0)break;
            }
            bookname=zn;
            for(int i=0;i<n;i++)if(s[i].name==bookname){s[i].zai=1;retuid.insert(i);}
        }
        if(cz[0]=='S'){
            if(retuid.size()){
                for(set<int>::iterator it=retuid.begin();it!=retuid.end();++it){
                    int id=*it;
                    for(int yd=0;;yd++){
                        if(id-yd==0){cout<<"Put "<<s[id].name<<" first"<<endl;break;
                        }else{
                            if(s[id-yd-1].zai){cout<<"Put "<<s[id].name<<" after "<<s[id-yd-1].name<<endl;break;}
                            else continue;
                        }
                    }
                }
            }
            retuid.clear();
            cout<<"END"<<endl;
        }
        if(cz[0]=='E')break;
    }
    system("pause");
    return 0;
}