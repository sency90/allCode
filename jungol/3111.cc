int idx[100001], tmp[100001];
extern int orderCheck(int left,int right);
inline void merge(int s, int m,int e) {
    int i=s,j=m+1,k=s;
    while(i<=m && j<=e) {
        if(orderCheck(idx[i],idx[j])) tmp[k++]=idx[i++];
        else tmp[k++]=idx[j++];
    }
    while(i<=m) tmp[k++] = idx[i++];
    while(j<=e) tmp[k++] = idx[j++];

    for(int i=s; i<=e; i++) idx[i]=tmp[i];
}
inline void msort(int s,int e) {
    if(s==e) return;
    int m=(s+e)>>1;
    msort(s,m); msort(m+1,e);
    merge(s,m,e);
}

void array_restore(int arrCount,int dat[]){
    for(int i=0; i<=arrCount; i++) idx[i]=i;
    msort(0,arrCount-1);
    for(int i=0; i<arrCount; i++) dat[idx[i]]=i+1;
}
