#include<iostream>
#include<cstring>
using namespace std;
const int maxd=10000+5;
struct cz{
    char c[5];
    int r1,c1,r2,c2;
    int a,x[20];
};
cz cmd[maxd];
int r,c,n;
int sim(int*r0,int*c0){
    for(int i=0;i<n;i++){
        if(cmd[i].c[0]=='E'){
            if(cmd[i].r1==*r0 and cmd[i].c1==*c0){*r0=cmd[i].r2;*c0=cmd[i].c2;}
            else if(cmd[i].r2==*r0 and cmd[i].c2==*c0){*r0=cmd[i].r1;*c0=cmd[i].c1;}
        }else{
            int dr=0,dc=0;
            for(int j=0;j<cmd[i].a;j++){
                int x=cmd[i].x[j];
                if(cmd[i].c[0]=='I'){
                    if(cmd[i].c[1]=='R' and x<=*r0)dr++;
                    if(cmd[i].c[1]=='C' and x<=*c0)dc++;
                }else{
                    if(cmd[i].c[1]=='R' and x==*r0)return 0;
                    if(cmd[i].c[1]=='C' and x== *c0)return 0;
                    if(cmd[i].c[1]=='R' and x<*r0)dr--;
                    if(cmd[i].c[1]=='C' and x<*c0)dc--;
                }
            }
            *r0+=dr;
            *c0+=dc;
        }
    }
    return 1;
}
int main(){
    int r0,c0,q,kass=0;
    while(scanf("%d%d%d",&r,&c,&n)==3 and r){
        for(int i=0;i<n;i++){
            scanf("%s",cmd[i].c);
            if(cmd[i].c[0]=='E')scanf("%d%d%d%d",&cmd[i].r1,&cmd[i].c1,&cmd[i].r2,&cmd[i].c2);
            else{
                scanf("%d", &cmd[i].a);
                for(int j=0;j<cmd[i].a;j++)scanf("%d",&cmd[i].x[j]);
            }
        }
        if(kass>0)printf("\n");
        printf("Spreadsheet #%d\n",++kass);
        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&r0,&c0);
            printf("Cell data in (%d,%d) ",r0,c0);
            if(!sim(&r0,&c0))printf("GONE\n");
            else printf("moved to (%d,%d)\n",r0,c0);
        }
    }
    system("pause");
    return 0;
}