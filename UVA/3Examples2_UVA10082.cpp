#include<iostream>
using namespace std;
char c[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main(){
    int a=0;
    while((a=getchar())!=EOF){
        int pd=0;
        for(int i=0;i<48;i++){
            if(c[i]==a){
                printf("%c",c[i-1]);
                pd++;
                break;
            }
        }
        if(pd==0){
            printf("%c",a);
        }
    }
    system("pause");
    return 0;
}