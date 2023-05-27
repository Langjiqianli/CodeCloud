#include<iostream>
using namespace std;
int main(){
    int lun=0;
    scanf("%d",&lun);
    for(int lunf=0;lunf<lun;lunf++){
        int m=0,n=0;
        scanf("%d %d",&m,&n);
        int chi2=0;
        chi2=getchar();
        char DNA [m][n];
        for(int i=0;i<m;i++){
            for(int a=0;a<n;a++){
                DNA[i][a]=getchar();
            }
            int chi1=0;
            chi1=getchar();
        }
        char qDNA[n];
        int zjuli=0;
        int juli[4];
        int julizhong=0;
        int id=0;
        for(int j=0;j<n;j++){
            qDNA[j]='A';
        }
        for(int x=0;x<n;x++){
            id=0;
            for(int p=0;p<4;p++){
                juli[p]=0;
            }
            for(int y=0;y<4;y++){
                julizhong=m*n;
                switch(y){
                    case 0:
                    qDNA[x]='A';
                    break;
                    case 1:
                    qDNA[x]='C';
                    break;
                    case 2:
                    qDNA[x]='G';
                    break;
                    case 3:
                    qDNA[x]='T';
                    break;
                }
                for(int q=0;q<m;q++){
                    if(qDNA[x]!=DNA[q][x])juli[y]++;
                }
            }
            for(int fid=0;fid<4;fid++){
                if(juli[fid]<julizhong){
                    id=fid;
                    julizhong=juli[fid];
                }else if(juli[fid]==julizhong){
                    if(fid<id)id=fid;
                }
            }
            zjuli+=juli[id];
            switch(id){
                case 0:
                qDNA[x]='A';
                break;
                case 1:
                qDNA[x]='C';
                break;
                case 2:
                qDNA[x]='G';
                break;
                case 3:
                qDNA[x]='T';
                break;
            }
        }
        for(int z=0;z<n;z++){
            printf("%c",qDNA[z]);
        }
        printf("\n%d\n",zjuli);
    }
    system("pause");
    return 0;
}