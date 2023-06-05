#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int maxn=128+5;
char s[maxn];
stack<int> z;
int main(){
    freopen("output.txt", "w", stdout);
    int lun;
    scanf("%d",&lun);
    getchar();
    while(lun--){
        int yes=1;
        memset(s,0,sizeof(s));
        for(int i=0;;i++){
            char r=getchar();
            if(r=='\n')break;
            s[i]=r;
        }
        int l=strlen(s);
        for(int i=0;i<l;i++){
            if(s[i]=='(')z.push(1);
            if(s[i]=='[')z.push(2);
            if(s[i]==')'){
                if(z.empty()){yes=0;break;}
                if(z.top()==1){z.pop();}
                else if(z.top()==2){yes=0;break;}
            }
            if(s[i]==']'){
                if(z.empty()){yes=0;break;}
                if(z.top()==1){yes=0;break;}
                else if(z.top()==2){z.pop();}
            }
        }
        if(yes and z.empty())printf("Yes\n");
        else printf("No\n");
        while(!z.empty())z.pop();
    }
    //system("pause");
    return 0;
}