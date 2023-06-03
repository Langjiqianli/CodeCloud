#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> list;
map<int,int> pro;
void yd(){
    int z=list.front();
    list.erase(list.begin());
    list.push_back(z);
}
int pan(int p){
    int pd=0;
    for(int i=9;i>p;i--){
        if(pro.count(i)){
            if(pro[i]>0){
                pd++;
                break;
            }
        }
    }
    return pd;
}
int main(){
    int lun;
    scanf("%d",&lun);
    for(int luni=0;luni<lun;luni++){
        int n,m;
        int time=1;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            int pr;
            scanf("%d",&pr);
            list.push_back(pr);
            if(!pro.count(pr))pro[pr]=0;
            pro[pr]++;
        }
        for(;;){
            int l=list.size();
            if(m==0){
                if(pan(list.front()))yd();
                else break;
                m=(m+l-1)%l;
            }
            else if(m!=0){
                if(pan(list.front()))yd();
                else {pro[list.front()]--;list.erase(list.begin());time++;}
                m=(m+l-1)%l;
            }
        }
        printf("%d\n",time);
        list.clear();
        pro.clear();
    }
    system("pause");
    return 0;
}