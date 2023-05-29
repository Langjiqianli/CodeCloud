#include<iostream>
using namespace std;
int main(){
    int n=0;
    int lun=1;
    while(scanf("%d",&n)!=EOF){
        if(lun!=1)printf("\n**********************************\n\n");
        printf("Problem #%d\n\n",lun++);
        int m=0;
        int shu[10];
        for(int i=0;i<10;i++)shu[i]=0;
        scanf("%d",&m);
        int s[2*n-1][2*n-1];
        for(int y=0;y<2*n-1;y++){
            for(int x=0;x<2*n-1;x++)s[y][x]=0;
        }
        for(int y=1;y<=n;y++){
            for(int x=1;x<=n;x++)s[y*2-2][x*2-2]=1;
        }
        for(int e=0;e<m;e++){
            int i,j;
            char a;
            getchar();
            scanf("%c %d %d",&a,&i,&j);
            if(a=='H')s[i*2-2][j*2-1]=2;
            if(a=='V')s[j*2-1][i*2-2]=2;
        }
        for(int le=1;le<n;le++){
            int wx=1,wy=1,sh=0;
            int x,y;
            for(y=0;y<n-1;y++){
                for(x=0;x<n-1;x++){
                    int ji=0;
                    for(int j=0;j<le;j++){
                        if(wy+le*2-1+y*2>n*2-2 or wx+le*2-1+x*2>n*2-2)break;
                        if(s[wy+y*2+j*2][wx-1+x*2]==0 or s[wy+y*2+j*2][wx+le*2-1+x*2]==0)break;
                        if(s[wy-1+y*2][wx+x*2+j*2]==0 or s[wy+le*2-1+y*2][wx+x*2+j*2]==0)break;//x
                        ji++;
                    }
                    if(ji==le)shu[le]++;
                }
            }
        }
        int pan;
        for(pan=0;pan<10;pan++)if(shu[pan]!=0)break;
        if(pan==10){
            printf("No completed squares can be found.\n");
        }else{
            for(int i=1;i<10;i++){
                if(shu[i]!=0)printf("%d square (s) of size %d\n",shu[i],i);
            }
        }
    }
    system("pause");
    return 0;
}