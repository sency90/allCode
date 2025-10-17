#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

bool IsSameCombination(char** L1, char** L2, int range) {	//두 배열의 조합이 같은지 판별하는 함수
	int checklist[1000] = { 0 };

	for (int i = 0; i < range; i++) {
		for (int j = 0; j < range; j++) {
			if ((strcmp(L1[i],L2[j]) == 0) && (checklist[j] != 1)) {
				checklist[j] = 1;
				break;
			}
		}
	}
	
	for (int i = 0; i < range; i++) {
		if (checklist[i] == 0) {
			return false;
		}
	}
	return true;
}

char** substring(char** str, int start, int end) { //배열의 부분을 때어 새로 만드는 함수
	char** sub = new char*[end - start];
	int count = 0;
	int i;

	for (i = start; i < end; i++) {
		sub[count] = new char[1000];

		strcpy(sub[count++], str[i]);

	}

	return sub;
}


char** searchMidle(char** first, char** last, int node) { //루트를 찾고 좌 트리와 우트리 부분을 찾아 좌 + 루트 + 우 순서로 결합하는 함수 
	int leftcount = 0;
	bool isLeft = false;

	char** result = new char*[node];
	char** Lefttemp;
	char** Righttemp;

	if (node == 1) { //노드가 하나이면 그대로 반환
		return first;
	}

	while (!(isLeft)) { //좌트리를 찾을때까지 탐색
		leftcount++;
		isLeft = IsSameCombination(substring(first, 1, leftcount + 1), substring(last, 0, leftcount), leftcount);

	}

	Lefttemp = searchMidle(substring(first, 1, 1 + leftcount), substring(last, 0, leftcount), leftcount);	//왼쪽 트리 완성
	Righttemp = searchMidle(substring(first, 1 + leftcount, node), substring(last, leftcount, node), node - leftcount - 1); //오른쪽 트리 완성


	for (int i = 0; i < leftcount; i++) { //왼쪽트리 합치기
		result[i] = new char[1000];
		strcpy(result[i], Lefttemp[i]);
	}

	result[leftcount] = new char[1000]; //가운데
	strcpy(result[leftcount], first[0]);

	for (int i = leftcount + 1; i < node; i++) { //오른쪽 트리 합치기
		result[i] = new char[1000];
		strcpy(result[i], Righttemp[i-leftcount-1]);
	}

	return result;
}


int main() {
	int node; //노드
	char firstSearch[2000]; //입력받기용 배열
	char lastSearch[2000];
	
	char** firstTrimNode = new char*[1000]; //공백 제거 배열(숫자가 10을 넘어갈 때 길이가 두개인것도 입력 받기 위해서 2차원 배열을 사용)
	char** lastTrimNode = new char*[1000];

	char** resultMidle; //결과

	cout << "Node 개수 : ";
	scanf("%i", &node);
	printf("전위 순회 : ");
	scanf("\n");
	fgets(firstSearch, sizeof(firstSearch), stdin);
	cout << "후위 순회 : ";
	fgets(lastSearch, sizeof(firstSearch), stdin);

	int count = 0;
	char *ptr;
	ptr = strtok(firstSearch, "\t \n");
	while (ptr != NULL) { //공백제거
		firstTrimNode[count] = new char[1000];
		strcpy(firstTrimNode[count], ptr);
		strcat(firstTrimNode[count], "\0");
		ptr = strtok(NULL, "\t \n");
		count++;
	}

	int count2 = 0;
	char *ptr2;
	ptr2 = strtok(lastSearch, "\t \n");
	while (ptr2 != NULL) { //공백제거
		lastTrimNode[count2] = new char[1000];
		strcpy(lastTrimNode[count2], ptr2);
		strcat(lastTrimNode[count2], "\0");
		ptr2 = strtok(NULL, "\t \n");
		count2++;
	}

	resultMidle = searchMidle(firstTrimNode, lastTrimNode, node); //중위 순회 탐색

	cout << "----<결과>----\n중위 순회 : ";
	for (int i = 0; i < node; i++) cout << resultMidle[i] << " ";
	cout << endl;
	return 0;
}