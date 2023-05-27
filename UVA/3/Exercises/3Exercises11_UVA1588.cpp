#include<iostream>
#include<string.h>
#define len 205
using namespace std;
int lang(const char* a,const char* b,int al,int bl){
    int L=al+bl;
    int ronga[al+bl];
    for(int i=0;i<al+bl;i++)ronga[i]=0;
    for(int i=0;i<al;i++)ronga[i]=a[i]-'0';
    for(int aw=0;aw<al;aw++){
        int awpan=bl;
        int awf=aw;
        for(int bw=0;bw<=aw;bw++){
            if(ronga[awf]+b[bw]-'0'>3)break;
            awpan--;
            awf--;
            if(awf<0 and aw+1<bl){
                if(L>al+bl-aw-1 and aw+1<bl)L=al+bl-aw-1;
                if(aw+1>=bl)L=al;
            }
            if(awpan<1 and aw+1>=bl){
                if(L>al+bl-aw-1 and aw+1<bl)L=al+bl-aw-1;
                if(aw+1>=bl)L=al;
            }
        }
    }
    return L;
}
int main(){
    char a[len];
    char b[len];
    char bfan[len];
    char afan[len];
    while(scanf("%s",a)!=EOF){
        scanf("%s",b);
        int al=strlen(a),bl=strlen(b);
        int L=al+bl;
        int ronga[al+bl];
        for(int i=0;i<al+bl;i++)ronga[i]=0;
        for(int i=0;i<al;i++)ronga[i]+=a[i]-'0';
        int afanwei=al-1;
        for(int i=0;i<al;i++){
            afan[afanwei--]=a[i];
        }
        int bfanwei=bl-1;
        for(int i=0;i<bl;i++){
            bfan[bfanwei--]=b[i];
        }
        if(al>bl){
            if(L>lang(afan,b,al,bl))L=lang(afan,b,al,bl);
            if(L>lang(a,bfan,al,bl))L=lang(a,bfan,al,bl);
        }else{
            if(L>lang(b,afan,bl,al))L=lang(b,afan,bl,al);
            if(L>lang(bfan,a,bl,al))L=lang(bfan,a,bl,al);
        }
        if(L<al or L<bl){
            if(al>bl)L=al;
            else L=bl;
        }
        printf("%d\n",L);
    }
    system("pause");
    return 0;
}