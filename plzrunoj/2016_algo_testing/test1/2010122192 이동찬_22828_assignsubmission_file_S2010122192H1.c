#include <iostream>
#include <stack>
#define MAX 1001

using namespace std;

stack <int> s;

int preorder[MAX];
int postorder[MAX];
bool visited[MAX];

//  return (num index of postorder)
int return_index(int num){
    int index=0;
    while(true){
        if(postorder[index] == num) break;
        index++;
    }
    return index;
}

void travel(int pre_begin, int pre_end, int post_begin, int post_end, char LR) {

    if (pre_begin > pre_end || post_begin > post_end) return;

    int root = preorder[pre_begin];
    s.push(root);

    int new_post = return_index(root);
    int new_range = new_post-post_begin;       

    travel(pre_begin+1, pre_begin+new_range, post_begin, new_post-1, 'L');

    if(!visited[root]){ printf("%d ", s.top()); s.pop();}
    if(LR=='L'){ printf("%d ", s.top()); visited[s.top()]=true; s.pop(); }

    travel(pre_begin+new_range+1, pre_end, new_post+1, post_end, 'R');    

}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d",&preorder[i]);
    for (int i=0; i<n; i++) scanf("%d",&postorder[i]);
    
    travel(0, n-1, 0, n-1, 'F');
    cout<<endl;
    return 0;
}