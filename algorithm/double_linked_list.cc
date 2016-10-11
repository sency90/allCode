#include <cstdio>
using namespace std;
struct Node {
    Node *next, *prev;
    int x;
    Node():next(0),prev(0),x(0){}
    Node(int x):next(0),prev(0),x(x){}
};
struct DList{
    Node *head, *tail, *cur;
    int sz, _idx;
    DList():sz(0),_idx(0) {
        head=new Node(); tail=new Node();
        head->next=tail; tail->next=tail;
        head->prev=head; tail->prev=head;
        cur=head;
    }
    int idx() { return _idx; }
    int size() { return sz; }
    int val() { return cur->x; }
    void ins(int x) {
        Node *node = new Node(x);
        cur->next->prev=node;
        node->next=cur->next;
        cur->next=node;
        node->prev=cur;
        cur=node;
        _idx++;
        sz++;
    }
    bool rm() {
        if(sz==0) return false;
        cur->next->prev=cur->prev;
        cur->prev->next=cur->next;
        Node *tmp=cur;
        cur=cur->prev;
        delete tmp;
        _idx--;
        sz--;
        return true;
    }
    Node* cc(int cnt) {
        if(sz==0) return head;
        else if(cnt>=sz) cnt%=sz;

        for(int i=0; i<cnt; i++) {
            if(cur->next!=tail) {
                cur=cur->next;
                _idx++;
            } else {
                cur=head->next;
                _idx=1;
            }
        }
        return cur;
    }
    Node* ccw(int cnt) {
        if(sz==0) return head;
        else if(cnt>=sz) cnt%=sz;

        for(int i=0; i<cnt; i++) {
            if(cur->prev!=head) {
                cur=cur->prev;
                _idx--;
            } else {
                cur=tail->prev;
                _idx=sz;
            }
        }
        return cur;
    }
    Node* mvForward(int cnt) {
        if(sz==0) return head;
        for(int i=0; i<cnt && cur->next!=tail; i++) {
            cur=cur->next;
            _idx++;
        }
        return cur;
    }
    Node* mvBackward(int cnt) {
        if(sz==0) return head;
        for(int i=0; i<cnt && _idx!=0; i++) {
            cur=cur->prev;
            _idx--;
        }
        return cur;
    }
    void print() {
        if(head->next == tail) return;
        for(Node *p=head; p->next!=tail; p=p->next) {
            printf("%d ", p->next->x);
        }
        puts("");
    }
    bool printCur() {
        if(cur==head) return false;
        printf("%d\n", cur->x);
        return true;
    }
};
int main() {
    DList dl;
    dl.ins(1); dl.ins(2); dl.ins(5); dl.ins(3); dl.print();
    dl.rm(); dl.printCur(); // 1, 2, 5
    dl.ccw(1); dl.printCur(); //2

    puts("test");

    dl.ccw(4); dl.printCur(); //1
    dl.cc(0); dl.printCur(); //1
    dl.ccw(0); dl.printCur(); //1
    dl.cc(100); dl.printCur(); //2
    printf("%d\n", dl.ccw(1)->x); //1
    printf("%d\n", dl.idx()); //1
    printf("%d\n", dl.size()); //3
    return 0;
}
