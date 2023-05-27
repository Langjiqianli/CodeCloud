#include<iostream>
using namespace std;
#define len 1000
int a[len];
int b[len];
int main(){
    int ca=1;
    int n=0;
    while(scanf("%d",&n)==1 and n){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        printf("Game %d:\n",ca++);
        for(;;){
            int A=0,B=0;
            for(int i=0;i<n;i++){
                scanf("%d",&b[i]);
                if(a[i]==b[i]){
                    A++;
                }
            }
            if(b[0]==0)break;
            for(int d=1;d<10;d++){
                int c1=0,c2=0;
                for(int i=0;i<n;i++){
                    if(a[i]==d)c1++;
                    if(b[i]==d)c2++;
                }
                if(c2>c1){
                    B+=c1;
                }else{
                    B+=c2;
                }
            }
            printf("    (%d,%d)\n",A,B-A);
        }
    }
    system("pause");
    return 0;
}