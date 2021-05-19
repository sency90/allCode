#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
using namespace std;
const string ETC_DIR = "ETC_DIR";
const string DIR_SUFFIX = "_DIR";
bool isPathExist(const string & path) {
    struct stat info;

    if(stat(path.c_str(), &info) != 0) return false;
    else if(info.st_mode & S_IFDIR) return true;
    else return false;
}
int main() {
    DIR *dir;
    struct dirent *dp;
    string extName;

    if((dir = opendir("./")) != NULL) {
        while((dp = readdir(dir)) != NULL) {
            string fname(dp->d_name);

            int idx = -1;
            for(int i=fname.size()-1; i>=0; i--) {
                if(fname[i] == '.') { idx = i+1; break; }
            }

            //set name for extName
            if(idx<0) extName = ETC_DIR;
            else {
                extName = fname.substr(idx); //extName = fname[i...end)
                for(int i=0; i<(int)extName.size(); i++) if(islower(extName[i])) extName[i] = extName[i]-'a'+'A'; //lower -> upper
                extName += DIR_SUFFIX; // + "_DIR"
            }

            if(!isPathExist(extName)) mkdir(extName.c_str(), 0755);
            rename(fname.c_str(), extName.c_str()); //mv file fnaem -> extName(path)
        }
        closedir(dir);
    }
    string path = "./";
    return 0;
}
