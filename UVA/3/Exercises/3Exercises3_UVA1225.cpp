#include<iostream>
using namespace std;
int main(){
    int ci=0;
    scanf("%d",&ci);
    for(int cishu=0;cishu<ci;cishu++){
        int s0=0,s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0,s8=0,s9=0;
        int shu=0;
        scanf("%d",&shu);
        for(int i=1;i<=shu;i++){
            int w=0,q=0,b=0,s=0,g=0;
            w=i/10000;
            q=(i-w*10000)/1000;
            b=(i-w*10000-q*1000)/100;
            s=(i-w*10000-q*1000-b*100)/10;
            g=i-w*10000-q*1000-b*100-s*10;
            if(w){
                switch(w){
                    case 0:
                    s0++;
                    break;
                    case 1:
                    s1++;
                    break;
                    case 2:
                    s2++;
                    break;
                    case 3:
                    s3++;
                    break;
                    case 4:
                    s4++;
                    break;
                    case 5:
                    s5++;
                    break;
                    case 6:
                    s6++;
                    break;
                    case 7:
                    s7++;
                    break;
                    case 8:
                    s8++;
                    break;
                    case 9:
                    s9++;
                    break;
                }
            }
            if(q or w){
                switch(q){
                    case 0:
                    s0++;
                    break;
                    case 1:
                    s1++;
                    break;
                    case 2:
                    s2++;
                    break;
                    case 3:
                    s3++;
                    break;
                    case 4:
                    s4++;
                    break;
                    case 5:
                    s5++;
                    break;
                    case 6:
                    s6++;
                    break;
                    case 7:
                    s7++;
                    break;
                    case 8:
                    s8++;
                    break;
                    case 9:
                    s9++;
                    break;
                }
            }
            if(b or(q or w)){
                switch(b){
                    case 0:
                    s0++;
                    break;
                    case 1:
                    s1++;
                    break;
                    case 2:
                    s2++;
                    break;
                    case 3:
                    s3++;
                    break;
                    case 4:
                    s4++;
                    break;
                    case 5:
                    s5++;
                    break;
                    case 6:
                    s6++;
                    break;
                    case 7:
                    s7++;
                    break;
                    case 8:
                    s8++;
                    break;
                    case 9:
                    s9++;
                    break;
                }
            }
            if(s or(b or(q or w))){
                switch(s){
                    case 0:
                    s0++;
                    break;
                    case 1:
                    s1++;
                    break;
                    case 2:
                    s2++;
                    break;
                    case 3:
                    s3++;
                    break;
                    case 4:
                    s4++;
                    break;
                    case 5:
                    s5++;
                    break;
                    case 6:
                    s6++;
                    break;
                    case 7:
                    s7++;
                    break;
                    case 8:
                    s8++;
                    break;
                    case 9:
                    s9++;
                    break;
                }
            }
            switch(g){
                case 0:
                s0++;
                break;
                case 1:
                s1++;
                break;
                case 2:
                s2++;
                break;
                case 3:
                s3++;
                break;
                case 4:
                s4++;
                break;
                case 5:
                s5++;
                break;
                case 6:
                s6++;
                break;
                case 7:
                s7++;
                break;
                case 8:
                s8++;
                break;
                case 9:
                s9++;
                break;
            }
        }
        printf("%d %d %d %d %d %d %d %d %d %d\n",s0,s1,s2,s3,s4,s5,s6,s7,s8,s9);
    }
    system("pause");
    return 0;
}