#include <cstdio>
#include <cstdlib>
class node {
public:
    int key;
    int value;
    node* next;
    node* back;
    node(int key, int value, node* next, node* back)
    : key(key) , value(value), next(next), back(back) {}
};
node* trash=new node(-1, -1, NULL, NULL);
class chain {
public:
    node* head = new node(99999, -1, NULL, NULL);
    chain() {
        head->next = head->back = head = new node(99999, -1, NULL, NULL);
    }
    void insert(int in) {
        // 0은 따로 노드 생성할 필요 없음.
        if(in==0) return;
        // 노드가 하나도 없을 때 수행.
        int count=0; // 새로 생성될 노드보다 큰 key 값을 노드가 얼마나 있었는지 count.
        for(node* it=head->next; it->key != 99999; it=it->next) {
            // 현재 노드보다 큰 key 값을 갖으면 그 노드의 앞에 노드 생성.
            if( in >= it->key) {
                if(in == it->key)
                    it->value++;
                else
                    it = it->back = it->back->next = new node(in, ++count, it, it->back);
                
                // 생성된 노드보다 key 값이 작은 노드들의 value를 +1 시켜주고 종료.
                it = it->next;
                while(it != head) {
                    it->value++;
                    // 이미 조건을 만족하는 가장 큰 수를 찾았기 때문에 보다 작은 수들은 기억할 필요 없다.
                    if( it->value >= it->key && it->next->key != 99999 ) {
                        // 지울 부분을 찾아서.
                        node* start = it->next;
                        node* end = head->back;
                        // 쓰레기통에 버린다.
                        trash->next = start;
                        start->back = trash;
                        end->next = NULL;
                        // 버려진 부분을 제외하고 다시 링크.
                        it->next = head;
                        head->back = it;
                        return;
                    }
                    it=it->next;
                }
                return;
            }
            count++;
            // 입력받은 수 보다 크면서 조건을 만족하는 수가 있다면 노드를 추가할 필요 없다.
            if( it->value >= it->key) return;
        }
        // 입력받은 값 보다 크면서 조건을 만족하는 숫자가 하나도 없을 때 실행.
        node* last = head->back;
        head->back = last->next = new node(in, ++count, head, last);
    }
    int getMaxKey() {
        for(node* it=head->next; it->key!=99999; it=it->next) {
            if(it->value >= it->key)
                return it->key;
        }
        return 0;
    }
};

int main() {
    chain c;
    int n;
    scanf("%d", &n);
    
    int in;
    while(n--) {
        scanf("%d", &in);
        c.insert(in);
    }
    printf("%d\n", c.getMaxKey());
    
    // 쓰레기통 비움.
    node* temp;
    for(node* t = trash->next; t!=NULL; t=temp) {
        temp = t->next;
        delete[] t;
    }
    return 0;
}
