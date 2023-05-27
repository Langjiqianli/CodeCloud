#include<iostream>
#include<string.h>
using namespace std;
int px(const char* p,int a,int b){
    int n = strlen(p);
    for(int i=0;i<n;i++){
        if(p[(a+i)%n]!=p[(b+i)%n]){
            return p[(a+i)%n]<p[(b+i)%n];
        }
    }
    return 0;
}
int main(){
    int ci=0;
    scanf("%d",&ci);
    for(int i=0;i<ci;i++){
        int x=0;
        char s [50];
        scanf("%s",s);
        int len=strlen(s);
        for(int o=0;o<len;o++){
            if(px(s,o,x))x=o;
        }
        for(int c=0;c<len;c++){
            printf("%c",s[(c+x)%len]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}