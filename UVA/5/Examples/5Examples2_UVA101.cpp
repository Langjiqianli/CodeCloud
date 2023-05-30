#include<iostream>
#include<vector>
using namespace std;
const int maxn=30;
int n;
vector<int> pi[maxn];
void find(int a,int&p,int&h){
    for(p=0;p<n;p++){
        for(h=0;h<pi[p].size();h++){
            if(pi[p][h]==a)return;
        }
    }
}
void clearon(int p,int h){
    for(int i=h+1;i<pi[p].size();i++){
        int b=pi[p][i];
        pi[b].push_back(b);
    }
    pi[p].resize(h+1);
}
void runon(int p,int h,int p2){
    for(int i=h;i<pi[p].size();i++)pi[p2].push_back(pi[p][i]);
    pi[p].resize(h);
}
int main(){
    int a,b;
    string s1,s2;
    cin>>n;
    for(int i=0;i<n;i++)pi[i].push_back(i);
    while(cin>>s1>>a>>s2>>b){
        int pa,pb,ha,hb;
        find(a,pa,ha);
        find(b,pb,hb);
        if(pa==pb) continue;
        if(s2=="onto") clearon(pb,hb);
        if(s1=="move") clearon(pa,ha);
        runon(pa,ha,pb);
    }
    for(int i=0;i<n;i++){
        printf("%d:",i);
        for(int h=0;h<pi[i].size();h++)printf(" %d",pi[i][h]);
        printf("\n");
    }
    system("pause");
    return 0;
}