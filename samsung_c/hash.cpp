#include <cstdio>
using namespace std;
struct Data{
    int x,y,z;
    Data(){}
    Data(int x, int y, int z):x(x), y(y), z(z) {}
    bool operator==(const Data & rhs) {
        return x==rhs.x && y==rhs.y && z==rhs.z;
    }
    bool operator!=(const Data & rhs) {
        return x!=rhs.x && y!=rhs.y && z!=rhs.z;
    }
};
template <typename T>
struct Node{
    T x;
    Node *next;
    Node():next(nullptr){}
    Node(T x, Node *next):x(x), next(next) {}
};
struct HashTable {
    const static int SIZE = 10000;
    Node<Data> *table[SIZE];

    HashTable() {
        for(int i=0; i<SIZE; i++) {
            table[i] = nullptr;
        }
    }
    int hash(const Data & data) {
        return (data.x+data.y+data.z)%SIZE;
    }
    void insert(const Data & data) {
        int idx = hash(data);
        table[idx] = new Node<Data>(data, table[idx]);
    }
    bool search(const Data & data) {
        int idx = hash(data);
        for(Node<Data> *it=table[idx]; it!=nullptr && it->x!=data; it=it->next);
        return it!=nullptr;
    }
    void remove(const Data &data) {
        int idx = hash(data);
        Node<Data> *prv = nullptr;
        for(Node<Data> *it=table[idx]; it!=nullptr && it->x!=data; ) {
            prv = it;
            it = it->next;
        }

        if (it == nullptr) return; //NOT FOUND
        else {
            if (prv == nullptr) {
                prv = it;
                it = it->next;
                delete prv;
            }
            else {
                prv->next = it->next;
                delete it;
                it = prv->next;
            }
        }
    }
};
int main()
{
    HashTable hTable;
    Data d1(1, 2, 3), d2(3, 6, 9), d3(2, 5, 8), d4(10, 10, 6);
    hTable.insert(d1);
    hTable.insert(d2);
    hTable.insert(d3);
    hTable.insert(d4);
    if (hTable.search(d1))
    {
        puts("d1 found");
    }
    else
    {
        puts("d1 not found");
    }

    hTable.remove(d1);
    if (hTable.search(d1))
    {
        puts("d1 found");
    }
    else
    {
        puts("d1 not found");
    }

    return 0;
}