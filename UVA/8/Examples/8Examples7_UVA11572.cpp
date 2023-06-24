#include<iostream>
#include<map>
using namespace std;
const int maxn=1000000+5;
map<int,int> c;
int n;
int s[maxn];
void yc(int&l,int end){
    while(s[l]!=end and l<n-1){
        c.erase(s[l]);
        l++;
    }
    l++;
}
int main(){
    int lun;
    scanf("%d",&lun);
    while(lun--){
        int ji=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&s[i]);
        int l=0,r;
        for(r=0;r<n;r++){
            if(!c.count(s[r])){c[s[r]]=1;if(ji<r-l+1)ji=r-l+1;}
            else yc(l,s[r]);
        }
        printf("%d\n",ji);
        c.clear();
    }
    system("pause");
    return 0;
}