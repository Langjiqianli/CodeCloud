#include<iostream>
#include<cstring>
#include<deque>
using namespace std;
const int maxn=30;
deque<char> sq,sz;
struct node{
    char val;
    node*left;
    node*right;
    node():val(0),left(NULL),right(NULL){}
};
node*newnode(){return new node();}
char getroot(deque<char>* s){
    char root=s->front();
    s->pop_front();
    return root;
}
node* build(deque<char> sqj,deque<char> szj){
    if(sqj.empty() or szj.empty())return NULL;
    node*root=newnode();
    char rt=getroot(&sqj);
    root->val=rt;
    deque<char> lf,ri;
    for(;;){
        char a=szj.front();
        szj.pop_front();
        if(a==rt)break;
        lf.push_back(a);
    }
    for(;;){
        if(szj.empty())break;
        char a=szj.front();
        ri.push_back(a);
        szj.pop_front();
    }
    deque<char> sql,sqr;
    for(int i=0;i<lf.size();i++)sql.push_back(getroot(&sqj));
    for(int i=0;i<ri.size();i++)sqr.push_back(getroot(&sqj));
    root->left=build(sql,lf);
    root->right=build(sqr,ri);
    return root;
}
void print(node*root){
    if(root->left!=NULL)print(root->left);
    if(root->right!=NULL)print(root->right);
    printf("%c",root->val);
    return;
}
int main(){
    char s1[maxn],s2[maxn];
    while(scanf("%s",s1)!=EOF){
        scanf("%s",s2);
        int l=strlen(s1);
        for(int i=0;i<l;i++)sq.push_back(s1[i]);
        for(int i=0;i<l;i++)sz.push_back(s2[i]);
        node*root=build(sq,sz);
        print(root);
        printf("\n");
        sq.clear();
        sz.clear();
    }
    system("pause");
    return 0;
}