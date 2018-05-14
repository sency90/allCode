#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
typedef long long ll;
class Solution {
public:
	//Fenwick
	Solution() { memset(fen, 0, sizeof(fen)); }
	~Solution() {}

	int n;
	int fen[100001];
	void update(int at) {
		for(;at<=n;at+=at&-at) fen[at]++;
	}
	int query(int at) {
		int ret=0;
		for(;at;at-=at&-at) ret+=fen[at];
		return ret;
	}

	map<ll, int> revOrder;
	set<ll> s;
	int reversePairs(vector<int>& nums) {
		revOrder.clear();
		s.clear();
		for(int i=0; i<nums.size(); i++) {
			s.insert(ll(nums[i]));
			s.insert(ll(nums[i])*2);
		}
		int idx=1;
		for(ll x : s) revOrder[x]=idx++;

		n=s.size();
		int ans=0;
		for(int i=0; i<nums.size(); i++) {
			ans += query(n)-query(revOrder[ll(nums[i])*2]);
			update(revOrder[ll(nums[i])]);
		}
		return ans;
	}
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().reversePairs(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
