#include <stdio.h>
typedef int KeyType;
struct Node {
    KeyType key;
    int priority, size;
    Node *left, *right;
    Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
    void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
    void setRight(Node* newRight) { right = newRight; calcSize(); }

    void clacSize() {
        size=1;
        if(left) size += left->size;
        if(right) size += right->size;
    }
};
int main() {
    return 0;
}
