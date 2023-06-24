#include<iostream>
#include<set>
using namespace std;
const int maxn=200000+5;
struct zu{
    int h;
    int g;
    bool operator < (const zu& rhs) const {return h < rhs.h;}
    zu(int h,int g):h(h),g(g){}
};
set<zu> s;
int h[maxn];
int g[maxn];
int f[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&h[i]);
        g[0]=1;
        for(int i=1;i<n;i++){
            if(h[i]>h[i-1])g[i]=g[i-1]+1;
            else g[i]=1;
        }
        f[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(h[i+1]>h[i])f[i]=f[i+1]+1;
            else f[i]=1;
        }
        int ans=1;
        s.insert(zu(h[0],g[0]));
        for(int i=1;i<n;i++){
            zu c(h[i],g[i]);
            set<zu>::iterator it=s.lower_bound(c);
            bool keep=true;
            if(it!=s.begin()){
                zu last=*(--it);
                if(ans<last.g+f[i])ans=last.g+f[i];
                if(c.g<=last.g)keep=false;
            }
            if(keep){
                s.erase(c);
                s.insert(c);
                it=s.find(c);
                it++;
                while(it!=s.end() and c.g>=it->g and c.h<it->h)s.erase(it++);
            }
        }
        printf("%d\n",ans);
        s.clear();
    }
    system("pause");
    return 0;
}