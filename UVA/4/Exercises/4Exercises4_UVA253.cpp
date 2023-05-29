#include<iostream>
using namespace std;
void zhuan(char a[]){
    int a1=a[0],a2=a[1],a5=a[4],a6=a[5];
    a[1]=a1;
    a[5]=a2;
    a[4]=a6;
    a[0]=a5;
    return;
}
void zhuanl(char a[]){
    int a1=a[0],a3=a[2],a6=a[5],a4=a[3];
    a[2]=a1;
    a[5]=a3;
    a[3]=a6;
    a[0]=a4;
    return;
}
void zhuans(char a[]){
    int a2=a[1],a3=a[2],a4=a[3],a5=a[4];
    a[4]=a3;
    a[2]=a2;
    a[3]=a5;
    a[1]=a4;
    return;
}
int main(){
    char s;
    while(scanf("%c",&s)!=EOF){
        char s1[6],s2[6];
        s1[0]=s;
        for(int i=1;i<6;i++)s1[i]=getchar();
        for(int i=0;i<6;i++)s2[i]=getchar();
        getchar();
        int p=0;
        if(p!=6)for(int i=0;i<4;i++){
            zhuans(s2);
            if(p!=6)for(int ii=0;ii<4;ii++){
                zhuanl(s2);
                if(p!=6)for(p=0;p<6;p++)if(s1[p]!=s2[p])break;
                if(p==6)break;
            }
        }
        zhuan(s2);
        if(p!=6)for(int i=0;i<4;i++){
            zhuans(s2);
            if(p!=6)for(int ii=0;ii<4;ii++){
                zhuanl(s2);
                if(p!=6)for(p=0;p<6;p++)if(s1[p]!=s2[p])break;
                if(p==6)break;
            }
        }
        zhuan(s2);
        if(p!=6)for(int i=0;i<4;i++){
            zhuans(s2);
            if(p!=6)for(int ii=0;ii<4;ii++){
                zhuanl(s2);
                if(p!=6)for(p=0;p<6;p++)if(s1[p]!=s2[p])break;
                if(p==6)break;
            }
        }
        zhuan(s2);
        if(p!=6)for(int i=0;i<4;i++){
            zhuans(s2);
            if(p!=6)for(int ii=0;ii<4;ii++){
                zhuanl(s2);
                if(p!=6)for(p=0;p<6;p++)if(s1[p]!=s2[p])break;
                if(p==6)break;
            }
        }
        if(p==6){
            printf("TRUE\n");
        }else{
            printf("FALSE\n");
        }
    }
    system("pause");
    return 0;
}