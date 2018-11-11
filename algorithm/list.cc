#include <cstdio>
#include <cstdlib>
using namespace std;
template <class T>
struct Node{
    T data;
    Node *prev; Node *next; Node():data(T(0)),prev(this),next(this){}
};

template <class T>
struct List{
    Node<T> *head;
    List() {
        head = new Node<T>();
    }
    ~List() {
        if(head!=NULL) delList(head);
    }

    //target -> node -> next
    Node<T>* insert(Node<T> *target, Node<T> *node = NULL) {
        Node<T> *next = target->next;
        if(node == NULL) node = new Node<T>();

        target->next = node;
        node->prev = target;
        node->next = next;
        next->prev = node;

        return node;
    }

    Node<T>* insert(Node<T> *target, const T& data) {
        Node<T> *node = new Node<T>();
        node->data = data;

        Node<T> *next = target->next;
        target->next = node;
        node->prev = target;
        node->next = next;
        next->prev = node;

        return node;
    }

    List<T>& paste(List<T>& rhs) {
        if(rhs.head == rhs.head->next) return *this;
        Node<T>* lhsFirst = head;
        Node<T>* lhsLast = head->prev;
        Node<T>* rhsFirst = rhs.head->next;
        Node<T>* rhsLast = rhs.head->prev;

        lhsFirst->prev = rhsLast;
        rhsLast->next = lhsFirst;
        lhsLast->next = rhsFirst;
        rhsFirst->prev = lhsLast;

        delete rhs.head;
        rhs.head = NULL;
        return *this;
    }

    void delNode(Node<T> *target) {
        Node<T> *next = target->next;
        Node<T> *prev = target->prev;
        next->prev = prev;
        prev->next = next;
        delete target;
    }

    void delList(Node<T> *target) {
        if(target->next != head) delList(target->next);
        delNode(target);
    }
};
List<int> list, list2;
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        list.insert(list.head->prev, x);
    }

    for(Node<int> *it = list.head->next; it!=list.head; it=it->next) {
        list2.insert(list2.head->prev, it->data);
        printf("%d ", it->data);
    }
    puts("");

    list.paste(list2);
    for(Node<int> *it = list.head->next; it!=list.head; it=it->next) {
        printf("%d ", it->data);
    }
    puts("");
    return 0;
}
