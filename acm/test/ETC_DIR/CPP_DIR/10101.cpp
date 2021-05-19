#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int ang[3], sum=0;
    for(int i=0; i<3; i++) {
        scanf("%d", &ang[i]);
        sum += ang[i];
    }
    sort(ang, ang+3);
    if(sum!=180) printf("Error");
    else if(ang[0] == ang[1] || ang[1] == ang[2]) {
        if(ang[0] == ang[2]) printf("Equilateral");
        else printf("Isosceles");
    } else printf("Scalene");
    return 0;
}
