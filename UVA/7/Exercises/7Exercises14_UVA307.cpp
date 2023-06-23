#include<iostream>
#include<algorithm>
using namespace std;
int cmp(const int &a, const int &b){
    return a > b;
}
int n;
int yes=0;
void pd(int s[],int vis[],int k,int ji,int wei,int shu){
    if(yes)return;
    if(shu==n)yes=1;
    else{
        for(int i=wei;i<n;i++){
            if(vis[i])continue;
            else if(ji+s[i]<k){
                vis[i]=1;
                pd(s,vis,k,ji+s[i],i+1,shu+1);
                vis[i]=0;
                while(s[i]==s[i+1] and i+1<n)i++;
            }else if(ji+s[i]==k){
                vis[i]=1;
                pd(s,vis,k,0,0,shu+1);
                vis[i]=0;
                return;
            }
            if(ji==0)return;
        }
    }
}
int main(){
    while(true){
        scanf("%d",&n);
        if(n==0)break;
        int s[n];
        int z=0;
        int min,max;
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            if(i==0){min=a;max=a;}
            s[i]=a;
            z+=a;
            if(a<min)min=a;
            if(a>max)max=a;
        }
        int jieguo=z;
        sort(s,s+n,cmp);
        int vis[n];
        for(int i=0;i<n;i++)vis[i]=0;
        for(int i=n;i>=1;i--){
            if(z%i!=0)continue;
            else{
                if(z/i<max)continue;
                pd(s,vis,z/i,0,0,0);
                if(yes){
                    jieguo=z/i;
                    break;
                }
            }
        }
        printf("%d\n",jieguo);
        yes=0;
    }
    system("pause");
    return 0;
}