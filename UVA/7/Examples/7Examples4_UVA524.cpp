#include<iostream>
#include<set>
using namespace std;
set<int> P;
bool pd(int a,int b){
    int c=a+b;
    if(P.count(c))return true;
    else return false;
}
void cz(int cur,const int n,int usd[],int s[]){
    if(cur==n and pd(s[0],s[n-1])){
        for(int i=0;i<n;i++){
            if(i!=0)printf(" ");
            printf("%d",s[i]);
        }
        printf("\n");
    }else{
        for(int i=2;i<=n;i++){
            if(!usd[i] and pd(s[cur-1],i)){
                s[cur]=i;
                usd[i]=1;
                cz(cur+1,n,usd,s);
                usd[i]=0;
            }
        }
    }
}
int main(){
    P.insert(2);
    P.insert(3);
    P.insert(5);
    P.insert(7);
    P.insert(11);
    P.insert(13);
    P.insert(17);
    P.insert(19);
    P.insert(23);
    P.insert(29);
    P.insert(31);
    int n,lun=1;
    while(scanf("%d",&n)!=EOF){
        if(lun!=1)printf("\n");
        printf("Case %d:\n",lun++);
        int usd[n+1];
        for(int i=1;i<=n;i++)usd[i]=0;
        usd[1]=1;
        int s[n];
        s[0]=1;
        cz(1,n,usd,s);
    }
    system("pause");
    return 0;
}