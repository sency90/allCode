#include <vector>
#include <algorithm>
using namespace std;
int main() {
	// 1부터 5까지 vector v에 넣습니다.<br />
	vector<int> v;
	for(int i = 1; i <= 5; i++) v.push_back(i);
	//find를 이용해서 reverse_iterator를 3의 위치에 둡니다<br />
	// 1,2,3,4,5
	vector<int>::reverse_iterator ri = find(v.rbegin(), v.rend(), 3);
	//reverse_iterator::base를 이용해 현재 위치를 기준으로<br />
	// iterator를 생성합니다.<br />
	// 즉, iterator를 3에다 두려고 합니다.<br />
	vector<int>::iterator it( ri.base());
	//3을 지우려고 합니다.<br />
	v.erase(it);
	//무슨일이 일어날까요?	</p>
	return 0;
}
