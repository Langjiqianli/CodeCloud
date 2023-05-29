#include<iostream>
#define len 100
#define timelen 1000
using namespace std;
class sd{
    public:
    int a;
    int b;
    int now;
    sd(int a=0,int b=0,int c=0):a(a),b(b),now(c){}
};
int main(){
    int n;
    int lun=1;
    while(scanf("%d",&n) and n){
        printf("Case %d: ",lun++);
        sd s[n];
        int t[n][len];
        int timem=-1;
        for(int i=0;i<n;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            int wei=0;
            s[i].a=a;
            s[i].b=b;
            s[i].now=c-1;//shuzu
            for(int ai=0;ai<a;ai++)t[i][wei++]=1;
            for(int bi=0;bi<b;bi++)t[i][wei++]=2;
        }
        for(int time=1;time<timelen;time++){
            int wp=0,sp=0;
            for(int i=0;i<n;i++){
                if(t[i][s[i].now]==2){
                    s[i].now=(s[i].now+1)%(s[i].a+s[i].b);
                    sp++;
                }else if(t[i][s[i].now]==1){
                    s[i].now=(s[i].now+1)%(s[i].a+s[i].b);
                    wp++;
                }
            }
            for(int i=0;i<n;i++){
                if(t[i][s[i].now]==2 and t[i][s[i].now-1]==1){
                    if(sp<=wp)s[i].now=0;
                }
            }
            if(wp==n){timem=time;break;}
        }
        printf("%d\n",timem);
    }
    system("pause");
    return 0;
}