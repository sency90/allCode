#include <cstdio>
using namespace std;
#define MAX_NODE 100

struct Node{
    int data;
    Node *prev;
    Node *next;
};

struct NodeHeap{
    bool use;
    Node node;
};

NodeHeap heap[MAX_NODE];

void initHeap() {
    for(int i=0; i<MAX_NODE; i++) heap[i].use=false;
}

void initNode(Node *node) {
    node->data = 0;
    node->prev = node;
    node->next = node;
}

Node* getNode() {
    for(int i=0; i<MAX_NODE; i++) {
        if(!heap[i].use) {
            heap[i].use = true;
            initNode(&heap[i].node);
            return &heap[i].node;
        }
    }
    return NULL;
}

void destroyNode(Node* node) {
    NodeHeap* nodeHeap = (NodeHeap*)((bool*)node-1);
    nodeHeap->use = false;
}

Node* appendNode(Node* list, int data) {
    Node* node = getListNode();
    node->data = data;
    if(list == NULL) return node;
    else {
        Node* last = list->prev;
        last->next = node;
        list->prev = node;
        node->next = list;
        node->prev = last;
        return list;
    }
}

Node* removeNode(Node* list, Node* node) {
    if(list == list->next) {
        destroyNode(node);
        return NULL;
    } else {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
        destroyNode(node);
        return (list == node) ? next : list;
    }
}


int main() {

    return 0;
}
