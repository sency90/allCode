#include <stdio.h>
int Strlen(char *a) { int i=0; while(a[i++]); return i-1; }
int cmp(char *a,char *b) {
    int al=Strlen(a),bl=Strlen(b);
    if(al == bl) {
        for(int i=0; i<al; i++) {
            if(a[i]<b[i]) return -1;
            else if(a[i]>b[i]) return 1;
        }
        return 0;
    } else if(al<bl) return -1;
    else return 1;
}
char ret[301];
void add(char *a,char *b) {
    int al=Strlen(a),bl=Strlen(b);
    int carry=0,i,j;
    for(i=al-1,j=bl-1; i>=0 && j>=0; i--,j--) {
        int d = (a[i]-'0')+(b[j]-'0')+carry;
        if(d>=10) {
            carry=1;
            ret[i]=(d-10)+'0';
        } else {
            carry=0;
            ret[i]=d+'0';
        }
    }
    for(;i>=0;i--) {
        int d = (a[i]-'0')+carry;
        if(d>=10) {
            carry=1;
            ret[i]=(d-10)+'0';
        } else {
            carry=0;
            ret[i]=d+'0';
        }
    }
    if(carry) {
        for(int i=al-1; i>=0; i--) ret[i+1]=ret[i];
        ret[0]='1';
        ret[al+1]=0;
    } else ret[al]=0;
    printf("%s\n",ret);
}

int x[301],y[301];
void m(char *a,char *b) {
    int al=Strlen(a),bl=Strlen(b);
    for(int i=0; i<al; i++) x[i]=a[i]-'0';
    for(int i=0,j=al-bl; i<bl; i++,j++) y[j]=b[i]-'0';
    for(int i=0; i<al-bl; i++) y[i]=0;
    for(int i=1; i<al; i++) x[i]+=10,x[i-1]--;
    for(int i=0; i<al; i++) x[i]-=y[i];
    for(int i=al-1; i>=0; i--) {
        if(x[i]>=10) {
            x[i-1]++;
            x[i]-=10;
        }
    }
    int len=0;
    int ii=0;
    for(; ii<al; ii++) if(x[ii]!=0) break;
    for(; ii<al; ii++) y[len++]=x[ii];
    if(len==0) puts("0");
    else {
        for(int ii=0; ii<len; ii++) printf("%0d",y[ii]);
        puts("");
    }
}
char p[301],q[301];
int main() {
    while(true) {
        scanf("%s %s",p,q);
        int plen=Strlen(p),qlen=Strlen(q);
        if(plen==1 && qlen==1 && p[0]=='0' && q[0]=='0') return 0;
        else {
            if(cmp(p,q)<0) {
                add(q,p);
                m(q,p);
            } else {
                add(p,q);
                m(p,q);
            }
        }
    }

    return 0;
}
