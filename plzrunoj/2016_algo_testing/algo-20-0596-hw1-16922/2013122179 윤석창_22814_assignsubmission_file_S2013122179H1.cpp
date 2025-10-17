#include <stdio.h>
#include <vector>
using namespace std;

void f(vector<int> &pre, vector<int> &post){
    int n = pre.size(), i;
    if(n<=1){
        if(n==1) printf("%d ", pre[0]);
        return;
    }
    int root = pre[0];
    vector<int> pre1, pre2, post1, post2;
    for(i=0;i<n;i++){
        pre1.push_back(pre[i+1]);
        post1.push_back(post[i]);
        if(pre[1] == post[i]) break;
    }
    for(i=i+1;i<n-1;i++){
        pre2.push_back(pre[i+1]);
        post2.push_back(post[i]);
    }
    f(pre1, post1);
    printf("%d ", root);
    f(pre2, post2);
}
int main(){
    int n;
    scanf("%d", &n);
    vector<int> pre(n), post(n);
    for(int i=0;i<n;i++) scanf("%d", &pre[i]);
    for(int i=0;i<n;i++) scanf("%d", &post[i]);
    f(pre, post);
    return 0;
}
