#include<iostream>
using namespace std;
const int maxn=100+5;
int s[maxn];
int t[maxn];
int main(){
    int T;
    scanf("%d",&T);
    getchar();
    for(int ti=1;ti<=T;ti++){
        printf("Case %d: ",ti);
        int s0=0,s1=0,sw=0;
        int n=0;
        while(true){
            char a=getchar();
            if(a=='0'){s0++;s[n++]=0;}
            else if(a=='1'){s1++;s[n++]=1;}
            else if(a=='?'){sw++;s[n++]=-1;}
            else if(a=='\n')break;
        }
        int t0=0,t1=0;
        n=0;
        while(true){
            char a=getchar();
            if(a=='0'){t0++;t[n++]=0;}
            else if(a=='1'){t1++;t[n++]=1;}
            else if(a=='\n')break;
        }
        int ans=0;
        if(s0+sw<t0)printf("%d\n",-1);
        else{
            int ji1=t1-s1;
            if(ji1>0)for(int i=0;i<n and ji1>0;i++){
                if(s[i]==-1 and t[i]==1){
                    ji1--;
                    ans++;
                    s[i]=1;
                }
            }
            if(ji1>0)for(int i=0;i<n and ji1>0;i++){
                if(s[i]==-1){s[i]=1;ans++;ji1--;}
            }
            for(int i=0;i<n;i++){
                if(s[i]==-1){s[i]=0;ans++;}
            }
            for(int i=0;i<n;i++)if(s[i]==0 and t[i]==1)ans++;
            printf("%d\n",ans);
        }
    }
    system("pause");
    return 0;
}