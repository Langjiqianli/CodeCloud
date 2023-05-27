#include<iostream>
#include<string.h>
using namespace std;
class start{
    public:
    int sc=0,sr=0;
    int l=0,u=0;
    start(){}
};
int main(){
    int ci=1;
    for(;;){
        int c=0,r=0;
        scanf("%d",&c);
        if(c==0)break;
        scanf("%d",&r);
        int chi=0;
        chi=getchar();
        char s[c][r+1];
        if(ci!=1)printf("\n");
        printf("puzzle #%d:\n",ci++);
        start st [c*r+1];
        int id=1;
        for(int y=0;y<c;y++){
            for(int x=0;x<r+1;x++){
                s[y][x]=getchar();
                if(s[y][x]!='*' and x!=r){
                    int chongpan=0;
                    if(x-1<0 or s[y][x-1]=='*'){
                        st[id].sc=y;
                        st[id].sr=x;
                        st[id].l=1;
                        chongpan=1;
                    }
                    if(y-1<0 or s[y-1][x]=='*'){
                        st[id].sc=y;
                        st[id].sr=x;
                        st[id].u=1;
                        chongpan=1;
                    }
                    if(chongpan)id++;
                }
            }
        }
        printf("Across\n");
        int n=id;
        for(int duid=1;duid<id;duid++){
            char sp[r];
            int ji=0;
            if(st[duid].l){
                for(int i=0;;i++){
                    if(s[st[duid].sc][st[duid].sr+i]=='*' or st[duid].sr+i>=r)break;
                    sp[i]=s[st[duid].sc][st[duid].sr+i];
                    ji++;
                }
                printf("%3d.",duid);
                for(int i=0;i<ji;i++){
                    printf("%c",sp[i]);
                }
                printf("\n");
            }else{
                continue;
            }
        }
        printf("Down\n");
        for(int duid=1;duid<id;duid++){
            char sp[r];
            int ji=0;
            if(st[duid].u){
                for(int i=0;;i++){
                    if(s[st[duid].sc+i][st[duid].sr]=='*' or st[duid].sc+i>=c)break;
                    sp[i]=s[st[duid].sc+i][st[duid].sr];
                    ji++;
                }
                printf("%3d.",duid);
                for(int i=0;i<ji;i++){
                    printf("%c",sp[i]);
                }
                printf("\n");
            }else{
                continue;
            }
        }
    }
    system("pause");
    return 0;
}