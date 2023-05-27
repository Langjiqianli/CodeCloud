#include<iostream>
#include<string.h>
#define max 20
using namespace std;
int main(){
    freopen("output.txt", "w", stdout);
    int ci=0;
    for(;;){
        int stop=0;
        int feifa=0;
        int chihuiche=0;
        char s[5][6];
        char cz[max];
        int x=0,y=0;
        for(int q=0;q<5;q++){
            for(int w=0;w<6;w++){
                s[q][w]=getchar();
                if(s[0][0]=='Z'){
                    stop=1;
                    break;
                }
                if(s[q][w]==' '){
                    x=w;
                    y=q;
                }
            }
            if(stop)break;
        }
        if(stop)break;
        if(ci!=0)printf("\n");
        printf("Puzzle #%d:\n",++ci);
        for(int i=0;i<max;i++){
            cz[i]=getchar();
            if(cz[i]=='0')break;
        }
        int n=strlen(cz);
        for(int i=0;i<n;i++){
            int ting=0;
            switch(cz[i]){
                case 'A':
                if(y-1>=0){
                    int zhong=0;
                    zhong=s[y-1][x];
                    s[y-1][x]=' '; 
                    s[y][x]=zhong;
                    y-=1;
                }else{
                    feifa=1;
                }
                break;
                case 'B':
                if(y+1<=4){
                    int zhong=0;
                    zhong=s[y+1][x];
                    s[y+1][x]=' ';
                    s[y][x]=zhong;
                    y+=1;
                }else{
                    feifa=1;
                }
                break;
                case 'L':
                if(x-1>=0){
                    int zhong=0;
                    zhong=s[y][x-1];
                    s[y][x-1]=' ';
                    s[y][x]=zhong;
                    x-=1;
                }else{
                    feifa=1;
                }
                break;
                case 'R':
                if(x+1<=4){
                    int zhong=0;
                    zhong=s[y][x+1];
                    s[y][x+1]=' ';
                    s[y][x]=zhong;
                    x+=1;
                }else{
                    feifa=1;
                }
                break;
                case '0':
                ting=1;
                break;
            }
            if(feifa){
                printf("This puzzle has no final configuration.\n");
                break;
            }
            if(ting)break;
        }
        if(feifa==0){
            for(int e=0;e<5;e++){
                for(int r=0;r<5;r++){
                    printf("%c",s[e][r]);
                    if(r<4)printf(" ");
                }
                printf("\n");
            }
        }
        chihuiche=getchar();
    }
    system("pause");
    return 0;
}