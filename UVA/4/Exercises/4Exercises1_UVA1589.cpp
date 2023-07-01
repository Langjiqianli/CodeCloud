#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct zi{
    int x;
    int y;
    int lei;
    zi(int x=0,int y=0,int l=0):x(x),y(y),lei(l){}
};
vector<zi> s;
bool find(int x,int y){
    for(int i=0;i<s.size();i++){
        if(s[i].x==x and s[i].y==y)return true;
    }
    return false;
}
int zhao(int a,int b,int f,int fu){
    int xiao=min(a,b);
    int da=max(a,b);
    int ji=0;
    if(f==0){
        for(int i=xiao+1;i<da;i++){
            if(find(i,fu))ji++;
        }
    }
    if(f==1){
        for(int i=xiao+1;i<da;i++){
            if(find(fu,i))ji++;
        }
    }
    return ji;
}
bool pd(int x,int y){
    for(int i=0;i<s.size();i++){
        zi&r=s[i];
        if(r.lei==0)if(r.y==y){
            if(!zhao(r.x,x,0,y))return false;
        }
        if(r.lei==1){
            if(r.y==y and r.x==x)continue;
            if(r.y==y){
                if(!zhao(r.x,x,0,y))return false;
            }
            if(r.x==x){
                if(!zhao(r.y,y,1,x))return false;
            }
        }
        if(r.lei==2){
            if(r.y==y)continue;
            if(r.x==x)continue;
            if(abs(r.x-x)==1){
                bool ok=false;
                if(r.y>y){if(!find(r.x,r.y-1))ok=true;}
                else{if(!find(r.x,r.y+1))ok=true;}
                if(ok){
                    if(r.y+2==y or r.y-2==y)return false;
                }
            }
            if(abs(r.x-x)==2){
                if(r.x>x){
                    if(!find(r.x-1,r.y)){
                        if(r.y+1==y or r.y-1==y)return false;
                    }
                }else{
                    if(!find(r.x+1,r.y)){
                        if(r.y+1==y or r.y-1==y)return false;
                    }
                }
            }
        }
        if(r.lei==3){
            if(r.y==y){
                int ji=zhao(r.x,x,0,y);
                if(ji==1)return false;
            }
            if(r.x==x){
                int ji=zhao(r.y,y,1,x);
                if(ji==1)return false;
            }
        }
    }
    return true;
}
int main(){
    int n;
    while(cin>>n and n){
        int a,b;
        cin>>a>>b;
        zi jiang(a,b,0);
        int jix,jiy;
        for(int i=0;i<n;i++){
            getchar();
            char l;
            int c,d;
            cin>>l>>c>>d;
            zi red(c,d);
            if(l=='G'){red.lei=0;jix=c;jiy=d;}
            else if(l=='R')red.lei=1;
            else if(l=='H')red.lei=2;
            else if(l=='C')red.lei=3;
            s.push_back(red);
        }
        bool yes=false;
        if(jiang.y==jiy)if(!zhao(jix,jiang.x,0,jiy))yes=true;
        if(jiang.x>1)if(pd(jiang.x-1,jiang.y))yes=true;
        if(jiang.x<3)if(pd(jiang.x+1,jiang.y))yes=true;
        if(jiang.y>4)if(pd(jiang.x,jiang.y-1))yes=true;
        if(jiang.y<6)if(pd(jiang.x,jiang.y+1))yes=true;
        if(yes)printf("NO\n");
        else printf("YES\n");
        s.clear();
    }
    system("pause");
    return 0;
}