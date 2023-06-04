#include<iostream>
#include<stack>
using namespace std;
struct ma{
    int a,b;
    ma(int a=0,int b=0):a(a),b(b){}
};
ma m [26];
stack<ma> s;
int main(){
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        int k=name[0]-'A';
        cin>>m[k].a>>m[k].b;
    }
    string expr;
    while(cin>>expr){
        int len=expr.length();
        bool error=false;
        int ans=0;
        for(int i=0;i<len;i++){
            if(isalpha(expr[i]))s.push(m[expr[i]-'A']);
            else if(expr[i]==')'){
                ma m2=s.top();
                s.pop();
                ma m1=s.top();
                s.pop();
                if(m1.b!=m2.a){error=true;break;}
                ans+=m1.a*m1.b*m2.b;
                s.push(ma(m1.a,m2.b));
            }
        }
        if(error)printf("error\n");
        else printf("%d\n",ans);
    }
    system("pause");
    return 0;
}