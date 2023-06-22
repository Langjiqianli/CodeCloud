#include<iostream>
using namespace std;
int main(){
    int n;
    int lun=1;
    while(scanf("%d",&n)!=EOF){
        int s[n];
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            s[i]=a;
        }
        long long z=0;
        for(int st=0;st<n;st++){
            for(int e=n-1;e>=st;e--){
                long long b;
                for(int i=st;i<=e;i++){
                    if(i==st)b=s[i];
                    else b*=s[i];
                    if(b>z)z=b;
                }
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",lun++,z);
    }
    system("pause");
    return 0;
}