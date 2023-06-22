#include<iostream>
using namespace std;
bool pd(int n,int m){
    int zhi;
    int s[10];
    s[0]=n/10000;
    n-=s[0]*10000;
    s[1]=n/1000;
    n-=s[1]*1000;
    s[2]=n/100;
    n-=s[2]*100;
    s[3]=n/10;
    n-=s[3]*10;
    s[4]=n;
    s[5]=m/10000;
    m-=s[5]*10000;
    s[6]=m/1000;
    m-=s[6]*1000;
    s[7]=m/100;
    m-=s[7]*100;
    s[8]=m/10;
    m-=s[8]*10;
    s[9]=m;
    for(int i=0;i<10;i++){
        for(int ii=i+1;ii<10;ii++){
            if(s[i]==s[ii])return false;
        }
    }
    return true;
}
int main(){
    for(int ji=0;;ji++){
        int n;
        scanf("%d",&n);
        if(n==0)break;
        if(ji!=0)printf("\n");
        int no=1;
        for(int i=1000;;i++){
            if(i*n>100000)break;
            if(pd(i,i*n)){
                printf("%05d / %05d = %d\n",i*n,i,n);
                no=0;
            }
        }
        if(no)printf("There are no solutions for %d.\n",n);
    }
    system("pause");
    return 0;
}