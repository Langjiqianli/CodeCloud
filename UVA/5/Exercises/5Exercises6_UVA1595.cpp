#include<algorithm>
#include<iostream>
#include<cmath>
#include<map>
using namespace std;
map<int,int> xm;//id,x
map<int,int> ym;//id,y
map<int,map<int,int>> dian;
int main(){
    int lun;
    scanf("%d",&lun);
    for(int luni=0;luni<lun;luni++){
        int n;
        scanf("%d",&n);
        int xmin,xmax;
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            if(i==0){
                xmin=x;
                xmax=x;
            }
            xm[i]=x;
            ym[i]=y;
            dian[x][y]=1;
            xmin=min(xmin,x);
            xmax=max(xmax,x);
        }
        double dcz=(xmin+xmax)/2.0;
        int ji=n;
        for(int i=0;i<n;i++){
            double dt=abs(dcz-xm[i]);
            if(xm[i]==dcz)ji--;
            else if(xm[i]>dcz){
                if(dian.count(xm[i]) and dian.count(dcz-dt)){
                    if(dian[dcz-dt].count(ym[i]))ji--;
                }
            }
            else if(xm[i]<dcz){
                if(dian.count(xm[i]) and dian.count(dcz+dt)){
                    if(dian[dcz+dt].count(ym[i]))ji--;
                }
            }
        }
        xm.clear();
        ym.clear();
        dian.clear();
        if(ji==0)printf("YES\n");
        else printf("NO\n");
    }
    system("pause");
    return 0;
}