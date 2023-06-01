#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
const int ju[3]={2,3,5};
int main(){
    priority_queue<LL,vector<LL>,greater<LL> >pd;
    set<LL> s;
    pd.push(1);
    s.insert(1);
    for(int i=1;;i++){
        LL x=pd.top();
        pd.pop();
        if(i==1500){
            cout<<"The 1500'th ugly number is "<<x<<"."<<endl;
            break;
        }
        for(int j=0;j<3;j++){
            LL x2=x*ju[j];
            if(!s.count(x2)){
                s.insert(x2);
                pd.push(x2);
            }
        }
    }
    system("pause");
    return 0;
}