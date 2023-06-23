#include<iostream>
using namespace std;
char s[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("2 %d %d\n",n,n);
        for(int i=0;i<n;i++){
            for(int x=0;x<n;x++)printf("%c",s[i]);
            printf("\n");
        }
        printf("\n");
        for(int i=0;i<n;i++){
            for(int x=0;x<n;x++)printf("%c",s[x]);
            printf("\n");
        }
    }
    system("pause");
    return 0;
}