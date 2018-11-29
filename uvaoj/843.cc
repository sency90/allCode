#include <stdio.h>
#define WORDLEN 17
struct Info{
    int len, idx;
    Info(){}
    Info(int len, int idx):len(len),idx(idx){}
};
int strlen(const char* s) {
    int len=0; for(; s[len]; len++);
    return len;
}
bool isLower(char x) {
    return 'a'<=x && x<='z';
}
bool issame(const char *a, const char *b) {
    int i,j;
    for(i=0, j=0; a[i] && b[j]; i++, j++) {
        if(a[i]!=b[j]) return false;
    }
    return a[i]==b[j];
}
char str[1001][WORDLEN+1], line[81], word[WORDLEN], cmpstr[81][WORDLEN+1];
Info g[1001], cmpg[1001];
int idx[1001], cmpidx[1001], cnt[WORDLEN];
int start[WORDLEN+1], dic[26], revdic[26], selfdic[26];
bool chk[81];
int aMatch[81], bMatch[1001], tmp[1001];
bool isSelfValid(int x, int y) {
    int len = cmpg[x].len;
    for(int i=0; i<len; i++) selfdic[int(cmpstr[cmpg[x].idx][i]-'a')] = -1;
    for(int i=0; i<len; i++) {
        int s = cmpstr[cmpg[x].idx][i]-'a', e = str[g[y].idx][i]-'a';
        if(selfdic[s]==-1 || selfdic[s]==e) selfdic[s]=e;
        else return false;
    }
    return true;
}
bool isValid(int x, int y) {
    if(cmpg[x].len != g[y].len) return false;
    int len = cmpg[x].len;
    for(int i=0; i<len; i++) {
        int s = cmpstr[cmpg[x].idx][i]-'a', e = str[g[y].idx][i]-'a';
        if((dic[s]==-1&&revdic[e]==-1) || (dic[s]==e && revdic[e]==s)) {
            dic[s] = e;
            revdic[e] = s;
        } else return false;
    }
    return true;
}
bool bipartite(int x) {
    if(chk[x]) return false;
    chk[x] = true;
    int len = cmpg[x].len;
    if(len==0) return false;
    for(int i=start[len-1]; i<start[len]; i++) {
        int y = g[i].idx;
        if(!isSelfValid(x,y)) continue;

        if((bMatch[y]==-1 && isValid(x,y)) || bipartite(bMatch[y])) {
            aMatch[x] = y;
            bMatch[y] = x;
            return true;
        }
    }
    return false;

}
int main() {
    freopen("input.txt", "r", stdin);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", str[i]);
        int len = strlen(str[i]);
        g[i] = Info(len,i);
    }
    for(int i=0; i<n; i++) cnt[g[i].len]++;
    for(int i=1; i<WORDLEN; i++) cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--) idx[--cnt[g[i].len]] = i;

    for(int i=0; i<WORDLEN; i++) start[i]=0;
    for(int i=0; i<n; i++) start[g[idx[i]].len]++;
    for(int i=1; i<=g[idx[n-1]].len; i++) start[i]+=start[i-1];
    start[g[idx[n-1]].len]=n;
    //prevLen = g[idx[n-1]].len;
    //for(int i=prevLen; i>=0; i--) {
        //if(start[i]==-1) {
         //   start[i]=start[i+1];
        //}
    //}

    while(true) {
        if(gets(line) == NULL) break;
        if(strlen(line)==0) continue;
        for(int i=0; i<26; i++) revdic[i]=dic[i]=-1;
        int cmpN=0, j=0;
        for(int i=0; line[i]; i++) {
            if(!isLower(line[i])) {
                cmpstr[cmpN][j] = 0;
                j=0;
                int len = strlen(cmpstr[cmpN]);
                cmpg[cmpN] = Info(len,cmpN);
                cmpN++;
            }
            else cmpstr[cmpN][j++] = line[i];
        }
        cmpstr[cmpN][j]=0; j=0;
        int len = strlen(cmpstr[cmpN]);
        cmpg[cmpN] = Info(len,cmpN);
        cmpN++;

        for(int i=0; i<cmpN; i++) tmp[i]=0;
        for(int i=0; i<cmpN; i++) {
            for(int j=i+1; j<cmpN; j++) {
                if(issame(cmpstr[i],cmpstr[j])) tmp[j]=-1;
            }
        }
        int tmpcnt=0;
        for(int i=0; i<cmpN; i++) if(tmp[i]>=0) cmpidx[tmpcnt++]=i;

        for(int i=0; i<cmpN; i++) aMatch[i] = -1;
        for(int i=0; i<n; i++) bMatch[i] = -1;
        bool good = true;
        for(int i=0; i<tmpcnt; i++) {
            int len = cmpg[cmpidx[i]].len;
            for(int j=0; j<cmpN; j++) chk[j] = false;
            if(!bipartite(cmpidx[i])) {
                good = false;
                break;
            }
        }

        if(good) {
            for(int i=0; line[i]; i++) {
                if(isLower(line[i])) printf("%c", char(dic[line[i]-'a']+'a'));
                else printf("%c", line[i]);
            }
        } else {
            for(int i=0; line[i]; i++) {
                if(isLower(line[i])) printf("*");
                else printf("%c", line[i]);
            }
        }
        puts("");
    }
    return 0;
}
