#include <stdio.h>

struct node {
    int value;
    node *leftNode;
    node *rightNode;
};

class tree {
    public:
        tree();
    private:
        node *root;
        void addNode(int value, node* &p);
};

void tree::addNode(int value, node* &p) {
    if(p == NULL) {
        p = new node;
        p->value = value;
        p->leftNode = NULL;
        p->rightNode = NULL;
    } else {
        if(value < p->value) {
            addNode(value, p->leftNode);
        } else {
            addNode(value, p->rightNode);
        }
    }
}
