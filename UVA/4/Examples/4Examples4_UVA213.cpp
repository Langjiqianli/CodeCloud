#include<iostream>
#include<string.h>
#include<cmath>
#define len 500
using namespace std;
char getcharplus(){
    char a;
    a=getchar();
    if(a=='\n'){
        a=getchar();
    }
    return a;
}
int er(const char*a,int l){
    int z=0;
    int lf=l;
    for(int i=0;i<l;i++){
        z+=(a[--lf]-'0')*pow(2,i);
    }
    return z;
}
int pri(const char*a,int l){
    int s=er(a,l);
    switch(l){
        case 1:
        return 0;
        break;
        case 2:
        return s+1;
        break;
        case 3:
        return s+4;
        break;
        case 4:
        return s+11;
        break;
        case 5:
        return s+26;
        break;
        case 6:
        return s+57;
        break;
        case 7:
        return s+120;
        break;
    }
    return 0;
}
int main(){
    char sc;
    char s[len];
    while(scanf("%c",&sc)!=EOF){
        s[0]=sc;
        for(int i=1;;i++){
            s[i]=getchar();
            if(s[i]=='\n')break;
        }
        for(;;){
            int pan1=0;
            char z[3];
            for(int i=0;i<3;i++)z[i]=getcharplus();
            int zz=er(z,3);
            if(zz==0)break;
            char zu[zz];
            for(;;){
                for(int x=0;x<zz;x++)zu[x]=getcharplus();
                for(pan1=0;pan1<zz;pan1++)if(zu[pan1]!='1')break;
                if(pan1==zz)break;
                int ci=pri(zu,zz);
                printf("%c",s[pri(zu,zz)]);
            }
        }
        printf("\n");
        int chi=getchar();
    }
    system("pause");
    return 0;
}