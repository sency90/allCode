#include <stdio.h>
#include <map>
using namespace std;
map<int, string> mp;
char s[26][100];
void init() {
    mp[1967]="DavidBowie";
    mp[1969]="SpaceOddity";
    mp[1970]="TheManWhoSoldTheWorld";
    mp[1971]="HunkyDory";
    mp[1972]="TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars";
    mp[1973]="AladdinSane";
    mp[1973]="PinUps";
    mp[1974]="DiamondDogs";
    mp[1975]="YoungAmericans";
    mp[1976]="StationToStation";
    mp[1977]="Low";
    mp[1977]="Heroes";
    mp[1979]="Lodger";
    mp[1980]="ScaryMonstersAndSuperCreeps";
    mp[1983]="LetsDance";
    mp[1984]="Tonight";
    mp[1987]="NeverLetMeDown";
    mp[1993]="BlackTieWhiteNoise";
    mp[1995]="1.Outside";
    mp[1997]="Earthling";
    mp[1999]="Hours";
    mp[2002]="Heathen";
    mp[2003]="Reality";
    mp[2013]="TheNextDay";
    mp[2016]="BlackStar";
}
int main() {
    int n, s, e;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        int cnt=0;
        scanf("%d%d",&s,&e);
        if(s<1967) s = 1967;
        if(e>2016) e = 2016;
        for(int i=s; i<=e; i++) {
            if(mp.count(i)==0) continue;
            else {
                fprintf(s[cnt++], "%d %s", i, mp[i]);
                cnt++;
            }
        }
        printf("%d", cnt);
        for(int i=0; i<cnt; i++) {
            printf("%s\n", s[i]);
        }
    }
    return 0;
}
