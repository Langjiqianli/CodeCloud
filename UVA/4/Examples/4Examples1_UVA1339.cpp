#include<iostream>
#include<algorithm>
#include<string.h>
#define len 105
using namespace std;
int main(){
    char a[len],b[len];
    while(scanf("%s",a)!=EOF){
        scanf("%s",b);
        int l=strlen(a);
        int ai[l],bi[l];
        int az[26],bz[26];
        memset(az,0,sizeof(az));
        memset(bz,0,sizeof(bz));
        for(int i=0;i<l;i++){
            az[a[i]-'A']+=1;
            bz[b[i]-'A']+=1;
        }
        sort(az,az+26);
        sort(bz,bz+26);
        int pan=0;
        for(int i=0;i<26;i++){
            if(az[i]!=bz[i]){
                pan=1;
                break;
            }
        }if(pan){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    system("pause");
    return 0;
}