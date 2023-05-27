#include<iostream>
#include<string.h>
#define len 100000
using namespace std;
int main(){
    char s[len];
    char t[len];
    while(scanf("%s",s)!=EOF){
        scanf("%s",t);
        int sl=strlen(s);
        int tl=strlen(t);
        int wei=0;
        int win=0;
        for(int i=0;i<tl;i++){
            if(s[wei]==t[i]){
                wei++;
                if(wei==sl){
                    win=1;
                    break;
                }
            }
        }
        if(win){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    system("pause");
    return 0;
}