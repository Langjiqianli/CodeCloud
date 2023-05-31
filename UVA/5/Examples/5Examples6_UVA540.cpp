#include<iostream>
#include<queue>
#include<map>
using namespace std;
const int maxt=1005;
int main(){
    int t,lun=0;
    while(scanf("%d",&t)==1 and t){
        printf("Scenario #%d\n",++lun);
        map<int,int>team;
        for(int i=0;i<t;i++){
            int n,x;
            scanf("%d",&n);
            while(n--){
                scanf("%d",&x);
                team[x]=i;
            }
        }
        queue<int>q,qz[maxt];
        for(;;){
            int x;
            char cmd[10];
            scanf("%s",cmd);
            if(cmd[0]=='S')break;
            else if(cmd[0]=='E'){
                scanf("%d",&x);
                int t=team[x];
                if(qz[t].empty())q.push(t);
                qz[t].push(x);
            }
            else if(cmd[0]=='D'){
                int t=q.front();
                printf("%d\n",qz[t].front());
                qz[t].pop();
                if(qz[t].empty())q.pop();
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}