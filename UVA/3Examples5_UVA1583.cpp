#include<iostream>
using namespace std;
int main(){
    int ci=0;
    scanf("%d",&ci);
    for(int i=0;i<ci;i++){
        int a=0,x=0;
        int b=0;
        scanf("%d",&a);
        x=a;
        for(int h=0;h<46;h++){
            int i=0,ii=0,iii=0,iiii=0,iiiii=0;
            i=x/10000;
            ii=(x-i*10000)/1000;
            iii=(x-i*10000-ii*1000)/100;
            iiii=(x-i*10000-ii*1000-iii*100)/10;
            iiiii=x-i*10000-ii*1000-iii*100-iiii*10;
            if(i+ii+iii+iiii+iiiii+x==a){
                b=x;
            }
            x--;
        }
        printf("%d\n",b);
    }
    system("pause");
    return 0;
}