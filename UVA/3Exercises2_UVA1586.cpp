#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
int main(){
    int ci=0;
    scanf("%d",&ci);
    char s[100];
    for(int cx=0;cx<ci;cx++){
        scanf("%s",s);
        int len=strlen(s);
        int c=0,h=0,o=0,n=0;
        for(int i=0;i<len;i++){
            switch(s[i]){
                case 'C':
                if(s[i+1]<65 and i+1<len){
                    char z[100];
                    int ji=0;
                    for(;s[i+1]<65 and i+1<len;){
                        z[ji++]=s[++i];
                    }
                    ji--;
                    int wei=0;
                    for(;ji>=0;ji--){
                        c+=((int)z[wei++]-48)*pow(10,ji);
                    }
                }else{
                    c++;
                }
                break;
                case 'H':
                if(s[i+1]<65 and i+1<len){
                    char z[100];
                    int ji=0;
                    for(;s[i+1]<65 and i+1<len;){
                        z[ji++]=s[++i];
                    }
                    ji--;
                    int wei=0;
                    for(;ji>=0;ji--){
                        h+=((int)z[wei++]-48)*pow(10,ji);
                    }
                }else{
                    h++;
                }
                break;
                case 'O':if(s[i+1]<65 and i+1<len){
                    char z[100];
                    int ji=0;
                    for(;s[i+1]<65 and i+1<len;){
                        z[ji++]=s[++i];
                    }
                    ji--;
                    int wei=0;
                    for(;ji>=0;ji--){
                        o+=((int)z[wei++]-48)*pow(10,ji);
                    }
                }else{
                    o++;
                }
                break;
                case 'N':
                if(s[i+1]<65 and i+1<len){
                    char z[100];
                    int ji=0;
                    for(;s[i+1]<65 and i+1<len;){
                        z[ji++]=s[++i];
                    }
                    ji--;
                    int wei=0;
                    for(;ji>=0;ji--){
                        n+=((int)z[wei++]-48)*pow(10,ji);
                    }
                }else{
                    n++;
                }
                break;
            }
        }
        printf("%.3f\n",c*12.01+h*1.008+o*16.0+n*14.01);
    }
    system("pause");
    return 0;
}