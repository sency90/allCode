#include <stdio.h>
#include <vector>
#define L 0
#define R 1
using namespace std;
vector<char> v[26];
int cnt[26];
void preorder(int idx) {
    printf("%c", idx+'A');
    if(v[idx][L]!='.') preorder(v[idx][L]-'A');
    if(v[idx][R]!='.') preorder(v[idx][R]-'A');
}
void inorder(int idx) {
    if(v[idx][L]!='.') inorder(v[idx][L]-'A');
    printf("%c", idx+'A');
    if(v[idx][R]!='.') inorder(v[idx][R]-'A');
}
void postorder(int idx) {
    if(v[idx][L]!='.') postorder(v[idx][L]-'A');
    if(v[idx][R]!='.') postorder(v[idx][R]-'A');
    printf("%c", idx+'A');
}
int main() {
    int n;
    char p, l, r;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf(" %c %c %c",&p,&l,&r);
        cnt[p-'A']++;
        if(l!='.') cnt[l-'A']++;
        if(r!='.') cnt[r-'A']++;
        v[p-'A'].push_back(l);
        v[p-'A'].push_back(r);
    }
    int i=0;
    for(; i<26; i++) {
        if(cnt[i]==1) break;
    }

    preorder(i); puts("");
    inorder(i); puts("");
    postorder(i);
    return 0;
}
