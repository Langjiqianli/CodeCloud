#include<iostream>
#include<string.h>
using namespace std;
#define len 85
int main(){
    int ci=0;
    scanf("%d",&ci);
    for(int c=0;c<ci;c++){
        char s [len];
        scanf("%s",s);
        int n=strlen(s);
        int fend=0;
        int fen=0;
        for(int i=0;i<n;i++){
            if(s[i]=='O')fen+=++fend;
            if(s[i]=='X')fend=0;
        }
        printf("%d\n",fen);
    }
    system("pause");
    return 0;
}