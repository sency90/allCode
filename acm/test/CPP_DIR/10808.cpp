#include <stdio.h>
int a[26], i;
int main() {
    char c;
    while((c=getchar())!='\n'&&c!=EOF) a[c-'a']++;
    for(;i<26;i++) printf("%d ",a[i]);
}
