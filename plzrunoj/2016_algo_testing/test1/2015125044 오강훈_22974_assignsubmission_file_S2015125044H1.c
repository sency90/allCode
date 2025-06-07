#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class lr{
public:
    lr* l=NULL;
    lr* r=NULL;
    int value;
    
};

void getinorder(lr* root){
    
    if(root != NULL){
        getinorder(root->l);
        printf("%d ", root->value);
        getinorder(root->r);
    }
}

void ia(lr * tree,vector<int>pre,vector<int>post){
    int pren= pre.size();
    int postn = post.size();
    
    tree->value = pre.front();
    vector<int>lpre,lpost; // 왼쪽 서브트리의 전위 후위
    vector<int>rpre,rpost; //  오른쪽 ''
    
    tree->l= new lr();
    tree->r= new lr();
    if(pren==1){
        tree->l=NULL;
        tree->r=NULL;
        
    }
    
    else if(pren==2) {
        tree->l->value = pre[1];//2개일 땐 그냥 왼쪽으로
        tree->r = NULL;
        return;
    }
    
    else if(pren==3 && pre[1] == post[0]){ // 높이가 2인 완전2진트리
        tree->l->value = pre[1];
        tree->r->value = pre[2];
        return;
    }
    
    else if(pre[1] == post[postn-2]){ // 서브트리가 하나인경우 왼쪽으로 보낸다
        pre.erase(pre.begin());
        lpre = pre;
        post.erase(post.end()-1);
        lpost = post;
        
        ia(tree->l,lpre,lpost);
    }
    
    else{
        int i=1;
        int k=0;
        while(pre[i]!=post[postn-2]) {
            lpre.push_back(pre[i++]);
        }
        while(i< pren){
            rpre.push_back(pre[i++]);
        }
        
        while(post[k] != pre[1]) {
            lpost.push_back(post[k++]);
        }
        lpost.push_back(post[k++]);
        
        while(k<postn-1) {
            rpost.push_back(post[k++]);
        }
        
        ia(tree->l,lpre,lpost); // 서브트리를 나눠서 각 l,r을 루트로 하여 재귀
        ia(tree->r,rpre,rpost);
        
    }
    
}
int main(){
    int num,i;
    lr *tree = new lr();
    
    scanf("%d",&num);
    vector<int> pre; // 숫자 배열로 해보았으나 외부함수에서 배열의 크기를 알 수 없어서 벡터를 사용
    vector<int> post;
    
    int a;
    for(i=0;i<num;i++){
        scanf("%d",&a);
        pre.push_back(a);
    }
    
    for(i=0;i<num;i++){
        scanf("%d",&a);
        post.push_back(a);
        
    }
    int root= pre.front();
    tree->value = root;
    ia(tree,pre,post);
    getinorder(tree);
    
}

