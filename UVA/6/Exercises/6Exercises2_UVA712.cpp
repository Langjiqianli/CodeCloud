#include<iostream>
#include<cmath>
using namespace std;
int er(const char*a,int l){
    int z=0;
    int lf=l;
    for(int i=0;i<l;i++){
        z+=(a[--lf]-'0')*pow(2,i);
    }
    return z;
}
int main(){
    int lun=1;
    for(;;){
        int d,n;
        scanf("%d",&d);
        if(d==0)break;
        printf("S-Tree #%d:\n",lun++);
        char chi[10];
        for(int i=0;i<d;i++)scanf("%s",chi);
        int shu=pow(2,d);
        char zhi[shu+5];
        scanf("%s",zhi);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            char cz[d+5];
            scanf("%s",cz);
            printf("%c",zhi[er(cz,d)]);
        }
        printf("\n\n");
    }
    system("pause");
    return 0;
}