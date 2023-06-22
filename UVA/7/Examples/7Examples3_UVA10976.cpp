#include<iostream>
#include<vector>
using namespace std;
vector<int> Y;
int main(){
    int K;
    while(scanf("%d",&K)!=EOF){
        int ji=0;
        for(int i=K+1;i<=2*K;i++){
            double k=K,y=i;
            double zz=k*y/(y-k);
            if((int)zz==zz){
                ji++;
                Y.push_back(i);
            }
        }
        printf("%d\n",ji);
        for(int i=0;i<Y.size();i++){
            int a=Y[i];
            printf("1/%d = 1/%d + 1/%d\n",K,K*a/(a-K),a);
        }
        Y.clear();
    }
    system("pause");
    return 0;
}