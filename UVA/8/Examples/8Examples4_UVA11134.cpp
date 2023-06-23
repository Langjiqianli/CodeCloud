#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=5000+5;
int n;
int visx[maxn];
int visy[maxn];
struct zi{
    int xmin,xmax;
    int ymin,ymax;
    int id;
    zi():xmin(0),xmax(0),ymin(0),ymax(0),id(0){}
};
int cmpx(zi e1,zi e2){
    if(e1.xmax==e2.xmax)return e1.xmin>e2.xmin;
    return e1.xmax<e2.xmax;
}
int cmpy(zi e1,zi e2){
    if(e1.ymax==e2.ymax)return e1.ymin>e2.ymin;
    return e1.ymax<e2.ymax;
}
zi save[maxn];
zi jie[maxn];
int yesx=0,yesy=0;
void place_x(zi z[],int cur){
    if(cur==n){yesx=1;return;}
    for(int i=0;i<n;i++){
        if(visx[i])continue;
        if(z[i].xmin>cur+1)continue;
        else if(z[i].xmin<=cur+1 and z[i].xmax>=cur+1){
            visx[i]=1;
            jie[z[i].id].xmax=cur+1;
            place_x(z,cur+1);
        }
    }
}
void place_y(zi z[],int cur){
    if(cur==n){yesy=1;return;}
    for(int i=0;i<n;i++){
        if(visy[i])continue;
        if(z[i].ymin>cur+1)continue;
        else if(z[i].ymin<=cur+1 and z[i].ymax>=cur+1){
            visy[i]=1;
            jie[z[i].id].ymax=cur+1;
            place_y(z,cur+1);
        }
    }
}
bool cz(zi s[],int cur){
    if(cur==n)return true;
    sort(s,s+n,cmpx);
    memset(visx,0,sizeof(visx));
    place_x(save,0);
    sort(s,s+n,cmpy);
    memset(visy,0,sizeof(visy));
    place_y(save,0);
    if(yesx and yesy)return true;
    else return false;
}
int main(){
    while(true){
        int idj=0;
        scanf("%d",&n);
        if(n==0)break;
        for(int i=0;i<n;i++){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&c,&b,&d);
            zi zz;
            zz.xmin=a;
            zz.xmax=b;
            zz.ymin=c;
            zz.ymax=d;
            zz.id=idj++;
            save[i]=zz;
        }
        if(cz(save,0))for(int i=0;i<n;i++)printf("%d %d\n",jie[i].xmax,jie[i].ymax);
        else printf("IMPOSSIBLE \n");
        yesx=0;
        yesy=0;
    }
    system("pause");
    return 0;
}