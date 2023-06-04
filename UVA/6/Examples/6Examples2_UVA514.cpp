#include<iostream>
#include<stack>
using namespace std;
const int maxn =1000+10;
int dl[maxn];
int main(){
    int n;
    while(scanf("%d",&n)==1){
        if(n==0)break;
        for(;;){
            stack<int> c;
            int a=1,b=1;
            int ting=0;
            for(int i=1;i<=n;i++){scanf("%d",&dl[i]);if(dl[i]==0){ting++;break;}}
            if(ting)break;
            int ok=1;
            while(b<=n){
                if(a==dl[b]){a++;b++;}
                else if(!c.empty() and c.top()==dl[b]){c.pop();b++;}
                else if(a<=n)c.push(a++);
                else {ok=0;break;}
            }
            printf("%s\n",ok?"Yes":"No");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}