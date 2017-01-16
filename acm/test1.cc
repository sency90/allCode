long long f(long long x) {
    if(x==0) return 0LL;
    int i=0;
    for(;(1LL<<i)<x; i++);
    return 1LL<<i;
}
