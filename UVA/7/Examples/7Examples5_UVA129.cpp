#include<iostream>
#include<cstring>
using namespace std;
bool pd(char s[]){
    int len=strlen(s);
    char p=s[len-1];
    int step=0;
    for(int i=len-2;i>=0;i--){
        step++;
        if(s[i]==p){
            int q;
            for(q=0;q<step;q++)if(s[len-1-q]!=s[i-q])break;
            if(q==step)return false;
            else continue;
        }
    }
    return true;
}
int zid=0;
int cz(char s[],const int n,const int l){
    int zong=0;
    int len=strlen(s);
    if(zid==n and zong==0){
        for(int i=0;i<len;i++){
            printf("%c",s[i]);
            if((i+1)%64==0)printf("\n");
            else if((i+1)%4==0 and i and i!=len-1)printf(" ");
        }
        printf("\n%d\n",len);
        return 1;
    }else{
        for(int i=0;i<l;i++){
            char z[85];
            for(int x=0;x<len;x++)z[x]=s[x];
            for(int x=len;x<85;x++)z[x]=0;
            z[len]='A'+i;
            if(pd(z)){
                zid++;
                zong=cz(z,n,l);
                if(zong)break;
            }
        }
    }
    return zong;
}
int main(){
    int n,l;
    for(;;){
        scanf("%d%d",&n,&l);
        if(n==0 and l==0)break;
        char s[80+5];
        for(int i=0;i<85;i++)s[i]=0;
        zid=0;
        cz(s,n,l);
    }
    system("pause");
    return 0;
}