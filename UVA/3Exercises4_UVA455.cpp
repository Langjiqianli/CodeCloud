#include<iostream>
#include<string.h>
#define max 85
using namespace std;
int main(){
    int ci=0;
    scanf("%d",&ci);
    for(int cishu=0;cishu<ci;cishu++){
        char s[max];
        scanf("%s",s);
        int n=strlen(s);
        int T=n;
        int a=s[0];
        for(int i=1;i<n;i++){
            if(a==s[i]){
                int pdd=0;
                for(int x=0;x<i;x++){
                    int pd=0;
                    if(n%i){
                        break;
                    }
                    int lun=n/i;
                    for(int y=1;y<lun;y++){
                        if(s[x]!=s[x+y*i]){
                            pd++;
                            break;
                        }
                    }
                    if(pd)continue;
                    pdd++;
                }
                if(pdd==i){
                    T=i;
                    break;
                }
            }
        }
        printf("%d\n",T);
        if(cishu!=ci-1)printf("\n");
    }
    system("pause");
    return 0;
}