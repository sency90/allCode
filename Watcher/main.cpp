#include <cstdio>
#include <regex>
#include <memory>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stdexcept>
using namespace std;

class Parent;
typedef void (Parent::*WorkFuncType)(const string &);

class Parent{
	public:
		vector<regex> regexList;
		vector<WorkFuncType> workList;
		Parent(){}

		void registerTargetFile(const string & patternName, WorkFuncType work) {
			try {
				regexList.emplace_back(patternName, regex::grep | regex::optimize);
				workList.emplace_back(work);
			}
			catch(exception e) {
				throw e;
			} }
};

class Child : public Parent{
	public:
		Child():Parent(){
			string s = ".*\\.cpp";
			try {
				registerTargetFile("[^_]"+s, static_cast<WorkFuncType>(&Child::work_0));
				//registerTargetFile(".*\\.zip", static_cast<WorkFuncType>(&Child::work_0));
			}
			catch(exception e) {
				throw e;
			}
		}

		void work_0(const string & evtName) {
			printf("evtName: %s\n", evtName.c_str());
		}

};

int main(int argc, char **argv) {
	if(argc!=2) {
		printf("Error Occured!!\n");
		throw std::runtime_error("Error Occured!!\n");
	}

	try {
		Parent p = Child();
		for(int i=0; i<p.regexList.size(); i++) {
			regex &re = p.regexList[i];
			if(regex_match(argv[1], re)) {
				printf("%s is matched with the registered regex_pattern.\n", argv[1]);
			}
			else {
				printf("%s is -NOT- matched with the registered regex_pattern.\n", argv[1]);
			}
		}
	}
	catch(exception & ex) {
		printf("Exception: %s\n", ex.what());
	}
	return 0;
}
