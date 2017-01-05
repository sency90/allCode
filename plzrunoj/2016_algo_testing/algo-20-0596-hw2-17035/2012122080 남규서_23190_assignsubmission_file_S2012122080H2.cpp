#include <stdio.h>
#include <algorithm>
#include <vector>
// vector, heap을 사용하기 위해 algorithm, vector 헤더 포함

int arrInt[10000];
// 최대 들어갈 수 있는 입력은 1000까지

int main(){
	int numberCount = 0;
	scanf("%d",&numberCount);

	for(int i = 0; i<numberCount; i++)
		scanf("%d", &arrInt[i]);

	int maxNumber = 0;

	std::vector<int> vi(&arrInt[0], &arrInt[numberCount]);
	// 입력받은 int형 배열을 heap만들때 사용하기 위해 벡터로 변환한다

	std::make_heap(vi.begin(), vi.end());
	std::sort_heap(vi.begin(), vi.end());
	//벡터를 이용해 힙을 만들고 heap_sort로 정렬한다

	for(int i = 0; i<numberCount; i++){
		if( vi[i] >= numberCount - i){
			// 배열크기에서 자신의 index를 빼면 자기보다 같거나 큰 원소의 수를 알 수 있다
			// 이를 자기자신과 비교하여 조건에 맞는다면
			maxNumber = numberCount - i;
			// 조건에 맞는 x를 maxNumber에 저장
			break;
			// 오름차순으로 정렬되어있기 때문에 뒤에 원소는 비교하지 않아도 된다

		}
	}
	
	printf("%d\n", maxNumber);
	//조건에 맞는 x중 최대값 출력

	return 0;
}