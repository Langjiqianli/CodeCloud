#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int d,I;
    int PD;
    scanf("%d",&PD);
    for(int pd=0;pd<PD;pd++){
        scanf("%d%d",&d,&I);
        int k=1;
        for(int i=0;i<d-1;i++){
            if(I%2){k=k*2;I=(I+1)/2;}
            else{k=k*2+1;I/=2;}
        }
        printf("%d\n",k);
    }
    system("pause");
    return 0;
}