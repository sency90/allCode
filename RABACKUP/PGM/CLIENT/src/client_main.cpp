#include <cstdio>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdarg>
#include <unistd.h>
#include <algorithm>
#include <vector>
#include <map>

#include "rab_install.h"
#include "rab_link.h"
#include "rab_push.h"
#include "rab_showinfo.h"
#include "rab_event.h"
#include "common_functions.h"
using namespace std;
using namespace CommonFunctions;
map<string, string> pathDic;
void init();

int main() {
    init();
    return 0;
}

void init() {
    pathDic["HOME"]="";
    pathDic["LOG"]="";
    pathDic["PGM"]= "";
    pathDic["EVENT"]="";
    pathDic["DISK"]="";
    pathDic["INSTALL"]="";

    ifstream ifs("./init.rab");
    stringstream ss, ss2;
    string line, dirName, dirPath;
    while(getline(ifs, line)) {
        ss.clear(); ss.str(line);
        while(getline(ss, line, '\r')) {
            trimBothTrailingSpaces(line);
            if(line.size()==0) continue;
            ss2.clear(); ss2.str(line);
            getline(ss2, dirName, '=');
            getline(ss2, dirPath);
            trimBothTrailingSpaces(dirName);
            trimBothTrailingSpaces(dirPath);
            putTrailingSlash(dirPath);
            if(pathDic.count(dirName) > 0) {
                pathDic[dirName] = dirPath;
            }
        }
    }

    if(pathDic.at("HOME").empty()) err("ERR: Line %d @ %s\n", __LINE__, __FILE__);
    for(map<string, string>::iterator it = pathDic.begin(), it!=pathDic.end(); it++) {
        if(it->second.empty()) it->second = pathDic["HOME"] + it->first;

        debug("pathDic[%s]: %s\n", it->first, it->second);
    }
}





















