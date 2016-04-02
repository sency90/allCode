#include <stdio.h>
int main() {
   int t; scanf("%d ", &t);
   int subcnt, cnt;
   char c;
   bool prevO;
   while(t--) {
       prevO = false;
       cnt = 0;
       subcnt = 0;
       while((c=getchar())!='\n' && c!=EOF && c!='\r') {
           if(c!='O' && c!='X') continue;
           if(c=='O') {
               if(prevO) subcnt++;
               else subcnt=1;
               prevO = true;
           } else {
               subcnt = 0;
               prevO = false;
           }
           cnt += subcnt;
       }
       printf("%d\n", cnt);
   }
}
