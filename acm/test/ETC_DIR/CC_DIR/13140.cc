#include <stdio.h>
int main() {
    int N; scanf("%d", &N);
    int H,E,L,O,W,R,D;
    for(H=1;H<10;H++) {
        for(E=0;E<10;E++) {
            if(H==E) continue;
            for(L=0;L<10;L++) {
                if(H==L || E==L) continue;
                for(O=0;O<10;O++) {
                    if(H==O || L==O || E==O) continue;
                    for(W=1;W<10;W++) {
                        if(H==W || L==W || E==W || O==W) continue;
                        for(R=0;R<10;R++) {
                            if(H==R || L==R || E==R || O==R || W==R) continue;
                            for(D=0;D<10;D++) {
                                if(H==D || L==D || E==D || O==D || W==D || R==D) continue;
                                if(L*120+1001*O+(H+W)*10000+E*1000+R*100+D == N) {
                                    int a=H*10000+E*1000+L*100+L*10+O;
                                    int b=W*10000+O*1000+R*100+L*10+D;
                                    printf("%7d\n+ %d\n-------\n%7d\n",a,b,N);
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    puts("No Answer");
    return 0;
}
