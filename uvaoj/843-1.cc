#include <stdio.h>
#define LINE_LEN 80
#define WORD_CNT 1000
#define WORD_LEN 16
#define HWORD_CNT 40
#define HWORD_LEN 16
char line[LINE_LEN+1];
char word[WORD_CNT+1][WORD_LEN+1];
char hword[HWORD_CNT][WORD_LEN+1];
int prev[WORD_CNT+1], group[WORD_LEN+1];
char dic[26], rdic[26];
int dicCnt[26], rdicCnt[26];
int strlen(const char *s) {
    int ret; for(ret=0;s[ret];ret++);
    return ret;
}
void init() {
    for(int i=0; i<=WORD_LEN; i++) group[i] = -1;
    for(int i=0; i<=WORD_CNT; i++) prev[i] = -1;
}
void middleInit() {
    for(int i=0; i<26; i++) dic[i]=rdic[i]=dicCnt[i]=rdicCnt[i]=0;
}
int tmpDic[26], tmpRDic[26];
bool isValid(const char *u, const char *v) {
    int len = strlen(u);
    if(len!=strlen(v)) return false;

    for(int i=0; i<26; i++) tmpDic[i]=tmpRDic[i]=-1;
    for(int i=0; i<len; i++) {
        int x=u[i]-'a', y=v[i]-'a';
        if(tmpDic[x]<0) tmpDic[x] = y;
        else if(tmpDic[x]!=y) return false;
        if(tmpRDic[y]<0) tmpRDic[y]=x;
        else if(tmpRDic[y]!=x) return false;
    }
    return true;
}
bool isDicValid(const char *u, const char *v, char *dic, char *rdic) {
    int len = strlen(u);
    for(int i=0; i<len; i++) {
        int x= u[i]-'a', y=v[i]-'a';
        if((((dic[x]==v[i]&&dicCnt[x]>0) || dicCnt[x]==0) && ((rdic[y]==u[i]&&rdicCnt[y]>0) || rdicCnt[y]==0)) == false) return false;
    }
    return true;
}

void regiDic(const char *u, const char *v, char *dic, char *rdic) {
    int len = strlen(u);
    for(int i=0; i<len; i++) {
        int x=u[i]-'a', y=v[i]-'a';
        dic[x] = v[i]; dicCnt[x]++;
        rdic[y] = u[i]; rdicCnt[y]++;
    }
}
void unregiDic(const char *u, const char *v, char *dic, char *rdic) {
    int len  = strlen(u);
    for(int i=0; i<len; i++) {
        int x=u[i]-'a', y=v[i]-'a';
        dicCnt[x]--;
        rdicCnt[y]--;
    }
}
bool go(int x, char *dic, char *rdic) {
    if(x<0) return true;
    int len = strlen(hword[x]);
    for(int i=group[len]; i!=-1; i=prev[i]) {
        if(!isValid(hword[x],word[i])) continue;
        if(!isDicValid(hword[x],word[i],dic,rdic)) continue;
        regiDic(hword[x],word[i],dic,rdic);
        if(go(x-1,dic,rdic)) return true;
        unregiDic(hword[x],word[i],dic,rdic);
    }
    return false;
}
int main() {
    init();
    freopen("input.txt","r",stdin);
    int n; scanf("%d%*[\r\n]", &n);
    for(int i=0; i<n; i++) {
        scanf("%[^ \r\n]%*[ \r\n]", word[i]);
        printf(":%s\n", word[i]);
        int len = strlen(word[i]);
        prev[i] = group[len];
        group[len] = i;
    }

    while(scanf("%[^\r\n]%*[\r\n]", line)!=EOF) {
        //printf("%s\n", line);
        int len = strlen(line), cnt=0;
        if(len==0) continue;

        middleInit();
        len = 0;
        for(cnt=0; sscanf(line+len, "%s", hword[cnt])!=EOF; cnt++) {
            //printf("[TEST]: %s\n", hword[cnt]);
            len += strlen(hword[cnt])+1;
        }
        if(go(cnt-1, dic, rdic)) {
            int len = strlen(line);
            for(int i=0; i<len; i++) printf("%c", line[i]==' '?' ':dic[line[i]-'a']);
            puts("");
        }
        else {
            int len = strlen(line);
            for(int i=0; i<len; i++) printf("%c", line[i]==' '?' ':'*');
            puts("");
        }
    }
    return 0;
}
