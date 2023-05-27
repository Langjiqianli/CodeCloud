#include<iostream>
using namespace std;
int main(){
    int a=0;
    int p=1;
    while((a=getchar())!=EOF){
        if(a=='"'){
            if(p%2){
                printf("``");
                p++;
            }else{
                printf("''");
                p++;
            }
        }else{
            printf("%c",a);
        }
    }
    system("pause");
    return 0;
}