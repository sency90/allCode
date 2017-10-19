#include <stdio.h>
struct List{
    int sx,sy,ex,ey,c;
    List *left,*right;
    List():left(NULL),right(NULL){}
    List(int sx,int sy,int ex,int ey,int c):sx(sx),sy(sy),ex(ex),ey(ey),c(c),left(NULL),right(NULL){}
};

int mx=0,mn=40000*40000;
inline bool inc(List *p,int x,int y) {
    return x<=p->ex && y<=p->ey;
}
inline void insert(List *p,int x,int y) {
    if(p->left == NULL) {
        if(!p->c) {
            p->left = new List(p->sx,p->sy,p->ex,y,p->c^1);
            p->right = new List(p->sx,y,p->ex,p->ey,p->c^1);
        } else {
            p->left = new List(p->sx,p->sy,x,p->ey,p->c^1);
            p->right = new List(x,p->sy,p->ex,p->ey,p->c^1);
        }
    } else {
        if(inc(p->left,x,y)) insert(p->left,x,y);
        else insert(p->right,x,y);
    }
}
inline int max(int x,int y) { return x>y?x:y; }
inline int min(int x,int y) { return x<y?x:y; }

inline int space(List *p) { return (p->ex-p->sx)*(p->ey-p->sy); }
void find(List *p) {
    if(p->left==NULL) {
        int s=space(p);
        mx = max(mx,s);
        mn = min(mn,s);
    } else {
        find(p->left);
        find(p->right);
    }
}

List *list;
int main() {
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    list = new List(0,0,n,m,0);
    for(int i=0; i<q; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        insert(list,x,y);
    }
    find(list);
    printf("%d %d",mx,mn);
    return 0;
}
