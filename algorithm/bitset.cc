#include <bitset>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define INTERVAL 8
typedef unsigned long long ull;
struct BIT {
    stack<ull> st;
    const ull ONE_ROOM;
    const int LIM;
    BIT() : ONE_ROOM((1ULL<<INTERVAL)-1ULL), LIM(64/INTERVAL) {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }

    void swap(ull &s, int idx_a, int idx_b) {
        int dif = (idx_a-idx_b)*INTERVAL;
        if(dif == 0) return;
        ull real_idx_a = ONE_ROOM<<(INTERVAL*idx_a);
        ull real_idx_b = ONE_ROOM<<(INTERVAL*idx_b);
        ull val_a=s&real_idx_a, val_b=s&real_idx_b;

        s &= ~real_idx_a & ~idx_b;
        if(dif > 0) { val_a >>= dif; val_a <<= dif; }
        else { val_a <<= -dif; val_b >>= -dif; }
        s |= (val_a|val_b);
    }

    void circulateLeft(ull &s, int n) {
    }

    void decimal_print(ull s) {
        for(int i=0; i<LIM; i++) {
            st.push(s&ONE_ROOM);
            s>>=INTERVAL;
        }
        while(!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
    }
    void binary_print(ull state) const {
        bitset<64> s(state);
        for(int i=63; i>=0; i-=INTERVAL) {
            for(int j=0; j<INTERVAL; j++) {
                cout << s.test(i-j);
            }
            cout << " ";
        }
    }
    void changeToValidString(string &str) {
        for(int i=0; i<str.size(); i++) {
            if(str[i]!='0') str[i]='1';
        }
    }
    ull stringToULL(string &str) {
        changeToValidString(str);
        return bitset<64>(str).to_ullong();
    }
    bitset<64> stringToBit(string &str) {
        changeToValidString(str);
        return bitset<64>(str);
    }
};
BIT bit;
int main() {
    string s;
    cin >> s;
    bit.decimal_print(bit.stringToULL(s));
    bit.binary_print(bit.stringToULL(s));
    return 0;
}
