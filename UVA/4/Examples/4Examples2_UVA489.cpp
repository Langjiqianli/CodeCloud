#include<iostream>
#include<string.h>
#define len 100
using namespace std;
int main(){
    int ID;
    while(scanf("%d",&ID)!=EOF and ID!=-1){
        printf("Round %d\n",ID);
        int hp=7;
        char s[len],cai[len];
        scanf("%s",s);
        scanf("%s",cai);
        int sl=strlen(s);
        int cl=strlen(cai);
        for(int i=0;i<cl;i++){
            for(int ii=i+1;ii<cl;ii++){
                if(cai[i]==cai[ii])cai[ii]=' ';
            }
        }
        int win=0;
        for(int i=0;i<cl;i++){
            int pan=1;
            for(int y=0;y<sl;y++){
                if(cai[i]==s[y]){
                    s[y]=' ';
                    pan=6;
                }
                if(cai[i]==' ')pan=0;
            }
            if(pan==1)hp--;
            int p;
            for(p=0;p<sl;p++){
                if(s[p]!=' ')break;
            }
            if(p==sl)win=1;
            if(hp<=0)break;
            if(win)break;
        }
        if(win)printf("You win.\n");
        else if(hp<=0)printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    system("pause");
    return 0;
}