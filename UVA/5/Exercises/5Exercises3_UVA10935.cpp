#include<iostream>
#include<vector>
using namespace std;
vector<int> s;
vector<int> zz;
int main(){
    int n;
    while(scanf("%d",&n)==1 and n){
        for(int i=n;i>0;i--)s.push_back(i);
        printf("Discarded cards:");
        for(;;){
            int l=s.size();
            int x=s.back();
            if(l==1)break;
            if(l>1)s.pop_back();
            printf(" %d",x);
            l=s.size();
            if(l==1)break;
            int zh=s.back();
            s.pop_back();
            l=s.size();
            zz.push_back(zh);
            for(int i=0;i<l;i++)zz.push_back(s[i]);
            s.clear();
            for(int i=0;i<=l;i++)s.push_back(zz[i]);
            zz.clear();
            printf(",");
        }
        printf("\n");
        printf("Remaining card: %d\n",s.front());
        s.clear();
    }
    system("pause");
    return 0;
}