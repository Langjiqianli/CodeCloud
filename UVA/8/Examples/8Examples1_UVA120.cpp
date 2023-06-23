#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
deque<int>s;
deque<int>cache;
deque<int>ls;
void fan(deque<int>&a,int xu){
    int n=a.size()-xu+1;
    for(int i=0;i<n;i++){
        cache.push_front(a.front());
        a.pop_front();
    }
    for(int i=0;i<n;i++){
        a.push_front(cache.back());
        cache.pop_back();
    }
    return;
}
int main(){
    int st;
    int x[30+5];
    while(scanf("%d",&st)!=EOF){
        int n=0;
        s.push_back(st);
        x[n++]=st;
        bool du=true;
        if(getchar()=='\n')du=false;
        while(du){
            int a;
            scanf("%d",&a);
            s.push_back(a);
            x[n++]=a;
            if(getchar()=='\n')break;
        }
        for(int i=0;i<n;i++){
            if(i!=0)printf(" ");
            printf("%d",s[i]);
        }
        printf("\n");
        sort(x,x+n);
        int zo=n;
        for(int ci=0;ci<zo;ci++){
            int cmax=x[--n];
            if(s[n]==cmax)continue;
            if(s[0]!=cmax){
                int wei;
                for(int i=0;i<zo;i++)if(s[i]==cmax){wei=i;break;}
                fan(s,zo-wei);
                ls.push_back(zo-wei);
            }
            fan(s,ci+1);
            ls.push_back(ci+1);
        }
        for(int i=0;i<ls.size();i++){
            if(i!=0)printf(" ");
            printf("%d",ls[i]);
        }
        if(!ls.empty())printf(" ");
        printf("0\n");
        s.clear();
        ls.clear();
    }
    system("pasue");
    return 0;
}