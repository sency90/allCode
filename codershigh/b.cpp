#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
map<int,pair<int,int> > xx;
char mp[25][100]={"1967 DavidBowie","1969 SpaceOddity","1970 TheManWhoSoldTheWorld","1971 HunkyDory","1972 TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars","1973 AladdinSane","1973 PinUps","1974 DiamondDogs","1975 YoungAmericans","1976 StationToStation","1977 Low","1977 Heroes","1979 Lodger","1980 ScaryMonstersAndSuperCreeps","1983 LetsDance","1984 Tonight","1987 NeverLetMeDown","1993 BlackTieWhiteNoise","1995 1.Outside","1997 Earthling","1999 Hours","2002 Heathen","2003 Reality","2013 TheNextDay","2016 BlackStar"};
int v[25]={1967,1969,1970,1971,1972,1973,1973,1974,1975,1976,1977,1977,1979,1980,1983,1984,1987,1993,1995,1997,1999,2002,2003,2013,2016};
void init() {
    for(int i=0; i<25; i++) {
        if(xx.count(v[i])==0) xx[v[i]]=make_pair(i,1);
        else xx[v[i]].second++;
    }
}
int main() {
    int n, s, e;
    init();
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        string str[25];
        int cnt=0;
        scanf("%d%d",&s,&e);
        if(s<1967) s = 1967;
        if(e>2016) e = 2016;
        for(int i=s; i<=e; i++) {
            if(xx.count(i)==0) continue;
            else {
                for(int j=0; j<xx[i].second; j++) {
                    str[cnt++]=mp[xx[i].first+j];
                }
            }
        }
        printf("%d\n", cnt);
        for(int i=0; i<cnt; i++) {
            cout<<str[i]<<'\n';
        }
    }
    return 0;
}
