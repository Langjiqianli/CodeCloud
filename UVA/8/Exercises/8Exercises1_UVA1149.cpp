#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=100000+5;
int s[maxn];
int main(){
    int T;
    scanf("%d",&T);
    for(int ti=0;ti<T;ti++){
        if(ti)printf("\n");
        int n,l;
        scanf("%d%d",&n,&l);
        for(int i=0;i<n;i++)scanf("%d",&s[i]);
        sort(s,s+n);
        int ans=0;
        int da=n-1;
        for(int i=0;i<n;i++){
            while(i<da){
                if(s[i]+s[da]<=l){
                    ans--;
                    da--;
                    break;
                }else da--;
            }
            ans++;
        }
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}