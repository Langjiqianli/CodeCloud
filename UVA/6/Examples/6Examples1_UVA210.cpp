#include<iostream>
#include<cstring>
#include<vector>
#include<deque>
#include<map>
using namespace std;
int bl[26];
deque<int> zx;
deque<int> jin;
const int maxn=100;
vector<string> cz[maxn];
void zc(){
    int x=zx.front();
    zx.pop_front();
    zx.push_back(x);
    return;
}
void zjin(){
    int x=zx.front();
    zx.pop_front();
    jin.push_back(x);
    return;
}
void jiejin(){
    int x=jin.front();
    zx.push_front(x);
    jin.pop_front();
    return;
}
int pdcz(int id,int czid){
    string a=cz[id][czid];
    int l=a.size();
    if(a[0]=='p' and a[1]=='r' and a[2]=='i')return 2;
    if(a[0]=='l' and a[1]=='o' and a[2]=='c')return 3;
    if(a[0]=='u' and a[1]=='n' and a[2]=='l')return 4;
    if(a[0]=='e' and a[1]=='n' and a[2]=='d')return 5;
    return 1;
}
int main(){
    int lun;
    scanf("%d",&lun);
    for(int luni=0;luni<lun;luni++){
        if(luni!=0)printf("\n");
        int n,t1,t2,t3,t4,t5,q;
        scanf("%d %d %d %d %d %d %d",&n,&t1,&t2,&t3,&t4,&t5,&q);
        int czid[n+1];
        for(int i=0;i<n+1;i++)czid[i]=0;
        for(int i=1;i<=n;i++)zx.push_back(i);
        for(int i=1;i<=n;i++){
            for(int xu=0;;xu++){
                char r;
                char z[150];
                memset(z,0,150);
                for(int x=0;;x++){
                    r=getchar();
                    if(r=='\n')break;
                    z[x]=r;
                }
                string zz=z;
                if(zz.size())cz[i].push_back(zz);
                if(zz=="end")break;
            }
        }
        int lock=0;
        for(;;){
            int sj=q;
            int jinpan=0;
            int jiejinp=0;
            for(;;){
                int cxh=zx.front();
                int cid=czid[cxh];
                if(sj>0){czid[cxh]++;}
                else break;
                string ss=cz[cxh][cid];
                int ssl=ss.size();
                switch(pdcz(cxh,cid)){
                    case 1:
                    sj-=t1;
                    if(ss[ssl-2]==' '){
                        bl[ss.front()-'a']=ss.back()-'0';
                    }
                    else if(ss[ssl-3]==' '){
                        bl[ss.front()-'a']=ss.back()-'0'+(ss[ssl-2]-'0')*10;
                    }
                    break;
                    case 2:
                    sj-=t2;
                    printf("%d: %d\n",cxh,bl[ss.back()-'a']);
                    break;
                    case 3:
                    sj-=t3;
                    if(lock==0){lock=cxh;}
                    else{zjin();czid[cxh]--;jinpan=1;}
                    break;
                    case 4:
                    sj-=t4;
                    if(lock==cxh){if(jin.size())jiejinp++;lock=0;}
                    break;
                    case 5:
                    sj-=t5;
                    zx.pop_front();
                    jinpan=1;
                    break;
                }
                if(jinpan)break;
            }
            if(!jinpan)zc();
            if(jiejinp)for(int i=0;i<jiejinp;i++)if(jin.size())jiejin();
            if(zx.size()==0)break;
        }
        for(int i=1;i<=n;i++)cz[i].clear();
        for(int i=0;i<26;i++)bl[i]=0;
    }
    system("pause");
    return 0;
}