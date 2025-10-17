#include <cstdlib>
#include <cstdio>
#include <vector>

class node {
    public:
    int value;
    node* left;
    node* right;
    node() : value(-1), left(NULL), right(NULL) {}
};
class tree {
    public:
    node* root;
    tree() { root = new node(); }
    void getInorder() { getInorder(root); }
    void getInorder(node* root) {
        if(root != NULL) {
            getInorder(root->left);
            printf("%d ", root->value);
            getInorder(root->right);
        }
    }
    void setSubTree(std::vector<int>& pre, std::vector<int>& post) {
        setSubTree(root, pre, post);
    }
    void setSubTree(node* subRoot, std::vector<int>& pre, std::vector<int>& post) {
        // 트리로 구성할 수 없는 값.
        if(pre[0] != post.back()) { printf("%d", -1); exit(-1); }
        
        // 값 저장.
        subRoot->value = pre[0];
        subRoot->left = new node();
        subRoot->right = new node();

        
        // subTree의 전위 / 후위 결과.
        std::vector<int> leftPre;
        std::vector<int> leftPost;
        std::vector<int> rightPre;
        std::vector<int> rightPost;
        
        // 배열의 길이가 1인 경우 더 진행할 필요가 없음.
        if(pre.size() == 1) {
            delete subRoot->left;
            subRoot->left = NULL;
            delete subRoot->right;
            subRoot->right = NULL;
            return;
        }
        
        // 배열의 길이가 2인 경우 왼쪽 자식에 할당.
        else if(pre.size() == 2) {
            subRoot->left->value = pre[1];
            delete subRoot->right;
            subRoot->right = NULL;
            return;
        }
        
        // 배열의 길이가 3이고 부모-자식 관계일 경우.
        else if(pre.size() == 3 && pre[1] == post[0]) {
            subRoot->left->value = pre[1];
            subRoot->right->value = pre[2];
            return;
        }
        
        // subTree가 하나만 존재할 때 왼쪽 서브트리로.
        else if(pre[1] == post[post.size()-2]) {
            delete subRoot->right;
            subRoot->right = NULL;
            
            pre.erase(pre.begin());
            leftPre = pre;
            
            post.erase(post.end()-1);
            leftPost = post;
            
            setSubTree(subRoot->left, leftPre, leftPost);
        }
        else {
            // leftPre 구성.
            int i = 1;
            while(pre[i] != post[post.size()-2]) {
                leftPre.push_back(pre[i++]);
            }
            
            // rightPre 구성.
            while(i < pre.size()) {
                rightPre.push_back(pre[i++]);
            }
            
            // leftPost 구성.
            i=0;
            while(post[i] != pre[1]) {
                leftPost.push_back(post[i++]);
            }
            leftPost.push_back(post[i++]);
            
            // rightPost 구성.
            while(i < post.size()-1) {
                rightPost.push_back(post[i++]);
            }
            
            setSubTree(subRoot->left, leftPre, leftPost);
            setSubTree(subRoot->right, rightPre, rightPost);
        }
    }
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> pre;
    std::vector<int> post;
    tree t;
    
    int temp;
    for(int i=0; i<n; i++) {
        scanf("%d", &temp);
        pre.push_back(temp);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &temp);
        post.push_back(temp);
    }
    
    t.setSubTree(pre, post);
    t.getInorder();
    
    return 0;
}

