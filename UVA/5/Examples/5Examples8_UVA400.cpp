#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=105;
string file [maxn];
void print(const string&a,int len){
    cout<<a;
    for(int i=0;i<len-a.length();i++)cout<<' ';
}
int main(){
    freopen("output.txt", "w", stdout);
    int n;
    while(cin>>n){
        int M=0;
        for(int i=0;i<n;i++){
            cin>>file[i];
            M=max(M,(int)file[i].length());
        }
        int lie=(60-M)/(M+2)+1,row=(n-1)/lie+1;
        printf("------------------------------------------------------------");
        cout<<endl;
        sort(file,file+n);
        for(int r=0;r<row;r++){
            for(int l=0;l<lie;l++){
                int idx=l*row+r;
                if(idx<n)print(file[idx],l==lie-1?M:M+2);
            }
            cout<<endl;
        }
    }
    //system("pause");
    return 0;
}