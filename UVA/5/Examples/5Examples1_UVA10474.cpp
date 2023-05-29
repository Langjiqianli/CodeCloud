#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,q;
    int lun=1;
    while(scanf("%d %d",&n,&q) and n){
        printf("CASE# %d:\n",lun++);
        int s[n];
        for(int i=0;i<n;i++){
            int r;
            scanf("%d",&r);
            s[i]=r;
        }
        int z[q];
        for(int i=0;i<q;i++){
            int r;
            scanf("%d",&r);
            z[i]=r;
        }
        sort(s,s+n);
        for(int zi=0;zi<q;zi++){
            int wei=-1;
            for(int si=0;si<n;si++){
                if(z[zi]==s[si]){
                    wei=si+1;
                    break;
                }
            }
            if(wei==-1) printf("%d not found\n",z[zi]);
            else printf("%d found at %d\n",z[zi],wei);
        }
    }
    system("pause");
    return 0;
}