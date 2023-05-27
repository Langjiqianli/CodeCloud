#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[6][2];
    while(scanf("%d %d",&a[0][0],&a[0][1])!=EOF){
        int fails=0;
        int fails1=0;
        int fail[6]={0,0,0,0,0,0};
        for(int i=1;i<6;i++){
            scanf("%d %d",&a[i][0],&a[i][1]);
        }

        for(int i=0;i<6;i++){
            if(a[i][0]>a[i][1]){
                int z=0;
                z=a[i][0];
                a[i][0]=a[i][1];
                a[i][1]=z;
            }
        }
        for(int i=0;i<6;i++){
            for(int y=0;y<6;y++){
                if(i!=y and (a[i][0]!=a[y][0] or a[i][1]!=a[y][1]))fail[i]+=1;
            }
        }
        for(int i=0;i<6;i++){
            if(fail[i]==5)fails=1;
        }
        for(int i=0;i<6;i++){
            for(int y=0;y<2;y++){
                int len=0;
                int shu=0;
                len=a[i][y];
                for(int x=0;x<6;x++){
                    for(int o=0;o<2;o++){
                        if(len==a[x][o] and x!=i){
                            shu++;
                            o++;
                        }
                        if(len==a[x][o] and x!=i)shu++;
                    }
                }
                if(shu<3)fails1=1;
            }
            if(fails1)break;
        }
        if(fails or fails1){
            printf("IMPOSSIBLE\n");
        }else{
            printf("POSSIBLE\n");
        }
    }
    system("pause");
    return 0;
}