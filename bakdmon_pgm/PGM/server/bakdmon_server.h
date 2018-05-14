#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <cstdlib>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>


struct Directory{
    const string homeDir, eventDir, logDir, pgmDir;
    Directory(){}
    Directory(const string& homeDir, const string& eventDir, const string& logDir, const string& pgmDir):homeDir(homeDir),eventDir(eventDir),logDir(logDir){}
};
Directory dirInfo("/Users/lian/allCode/bakdmon_pgm", "/Users/lian/allCode/bakdmon_pgm/EVENT", "/Users/lian/allCode/bakdmon_pgm/LOG", "/Users/lian/allCode/bakdmon_pgm/PGM");

void init();
int fprintlog(FILE *logfp, const char *format, ... );

void chkEvent();

