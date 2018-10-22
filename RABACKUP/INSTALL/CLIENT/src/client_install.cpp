#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "../../../PGM/CLIENT/src/common_functions.h"
using namespace std;
string homeDir;
string clientSrcDir;
int main() {
    printf("Please enter the below information\n");
    printf("RABACKUP_HOME: ");
    cin >> homeDir;
    if(access(homeDir.c_str(), F_OK) != 0) {
        printf("ERR: Invalid RABACKUP_HOME Directory Path");
        exit(1);
    }
    CommonFunctions::trimBothTrailingSpaces(homeDir);
    CommonFunctions::putTrailingSlash(homeDir);
    string initFilePath = homeDir + "PGM/CLIENT/src/init.rab";
    ofstream ofs(initFilePath);
    ofs << "HOME=" << homeDir << "\n";
    ofs.close();

    printf("MSG: RABACKUP_HOME: %s > %s\n", homeDir.c_str(), initFilePath.c_str());
    return 0;
}
