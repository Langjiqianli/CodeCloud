#include<iostream>
#define shu 10000
using namespace std;
int xun(const char* s,int a){
    for(int i=a;i<shu;i++){
        int T=0;
        int stop=0;
        if(s[a]==s[i] and a!=i){
            T=i-a;
            for(int q=0;q<T;q++){
                if(a+q+T*3>shu)return 0;
                if(s[a+q]!=s[a+q+T] or s[a+q]!=s[a+q+T*2] or s[a+q]!=s[a+q+T*3]){
                    T=0;
                    break;
                }
                if(q==T-1)stop=1;
            }
        }
        if(stop)return T;
    }
    return 0;
}
char s[shu];
int main(){
    int a=0,b=0;
    int lun=0;
    while((scanf("%d %d",&a,&b))!=EOF){
        double ac=a,bc=b;
        int acc=a,bcc=b;
        int T=0;
        int jin=0;
        int neigui=0;
        for(int i=0;i<shu;i++){
            int z=0;
            a*=10;
            z=a/b;
            if(a%b==0){
                neigui=1;
                break;
            }
            a-=z*b;
            if(z>9)z-=z/10*10;
            s[i]=z+48;
        }
        if(neigui==0){
            for(int j=0;j<shu;j++){
                T=xun(s,j);
                if(T!=0){
                    jin=j;
                    break;
                }
            }
        }else{
            T=1;
        }
        if(neigui){
            printf("%d/%d = %g",acc,bcc,ac/bc);
            if(acc%bcc==0)printf(".");
            printf("(0)\n");
        }else{
            printf("%d/%d = %d.",acc,bcc,acc/bcc);
                for(int d=0;d<jin;d++){
                    printf("%c",s[d]);
            }
            printf("(");
            if(jin+T>50){
                for(int o=jin;o<50;o++){
                    printf("%c",s[o]);
                }
                printf("...)\n");
            }else{
                for(int o=jin;o<T+jin;o++){
                    printf("%c",s[o]);
                }
                printf(")\n");
            }
        }
        printf("   %d = number of digits in repeating cycle\n\n",T);
        system("pause");
    }
    return 0;
}