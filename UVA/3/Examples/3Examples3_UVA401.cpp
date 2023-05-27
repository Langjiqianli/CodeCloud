#include<iostream>
#include<string.h>
using namespace std;
char c[]="A   E  HIJ LM O   STUVWXYZ123 5  8 ";
char r[]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";//镜像
const char* pd[]={"is not a palindrome","is a regular palindrome","is a mirrored string","is a mirrored palindrome"};
int main(){
    char s[50];
    while(scanf("%s",s)==1){
        int jing=1;
        int hui=1;
        int len =strlen(s);
        for(int l=0;l<(len+1)/2;l++){
            if(s[l]!=s[len-l-1]){
                hui=0;
            }
            int pd=0;
            for(int i=0;i<36;i++){
                if(s[l]==c[i]){
                    if(s[len-l-1]!=r[i]){
                        jing=0;
                    }
                    pd++;
                }
            }
            if(pd==0){
                jing=0;
            }
        }
        if(jing+hui==0){
            printf("%s -- %s.\n\n",s,pd[0]);
        }else if(jing==1 and hui==0){
            printf("%s -- %s.\n\n",s,pd[2]);
        }else if(hui==1 and jing==0){
            printf("%s -- %s.\n\n",s,pd[1]);
        }else if(hui==1 and jing==1){
            printf("%s -- %s.\n\n",s,pd[3]);
        }
    }
    system("pause");
    return 0;
}