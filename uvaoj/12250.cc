#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string,string> dic;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    dic["HELLO"]="ENGLISH";
    dic["HOLA"]="SPANISH";
    dic["HALLO"]="GERMAN";
    dic["BONJOUR"]="FRENCH";
    dic["CIAO"]="ITALIAN";
    dic["ZDRAVSTVUJTE"]="RUSSIAN";
    string s;
    for(int z=1;;z++) {
        cin >> s;
        if(s=="#") return 0;
        if(dic.count(s)) cout << "Case "<< z << ": "<< dic[s] << "\n";
        else cout <<"Case "<<z<<": UNKNOWN\n";
    }
    return 0;
}
