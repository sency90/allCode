#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;

deque<int> preList, postList, li_left, li_right,result;
struct node{
	int *left;
	int *right;
	int *parent;
	int val;
};

void printInorder(int preStart, int preEnd, int postStart, int postEnd){
	int seperator, leftPreStart, leftPreEnd, rightPreStart, rightPreEnd,numCount;
	int leftPostStart, leftPostEnd, rightPostStart, rightPostEnd;
	int tempRoot = preList[preStart];
	seperator = postList[postEnd-1];
	leftPreStart = preStart + 1;
	rightPreEnd = preEnd;
	rightPostEnd = postEnd - 1;
	leftPostStart = postStart;
	numCount = 0;
	for(int i=leftPreStart;i<preEnd+1;i++){
		numCount++;
		if(preList[i] == seperator){
			if(i == leftPreStart){
				if(preStart+1 != preEnd)
					printInorder(preStart+1, preEnd, postStart, postEnd-1);
				else
					result.push_back(preList[preStart+1]);

				result.push_back(tempRoot); //두가지 경우중 왼쪽으로 붙는경우로 생각
				return;
			}
			rightPreStart = i;
			leftPreEnd = rightPreStart-1;
			break;
		}
	}

	leftPostEnd = numCount - 2 + leftPostStart;
	rightPostStart = leftPostEnd+1;

	if(leftPreStart == leftPreEnd)
		result.push_back(preList[leftPreStart]);
	else
		printInorder(leftPreStart,leftPreEnd, leftPostStart, leftPostEnd);

	result.push_back(tempRoot);

	if(rightPreStart == rightPreEnd)
		result.push_back(preList[rightPreStart]);
	else
		printInorder(rightPreStart,rightPreEnd, rightPostStart, rightPostEnd);

	return;
}




int main(){
	int testSize,inputTemp;

	scanf("%d",&testSize);

	for(int i=0; i<testSize; i++){
		scanf("%d",&inputTemp);
		preList.push_back(inputTemp);
	}
	for(int i=0; i<testSize; i++){
		scanf("%d",&inputTemp);
		postList.push_back(inputTemp);
	}
	
	if(testSize == 1){
		printf("%d",inputTemp);
		return 0;
	}

	printInorder(0,testSize-1,0,testSize-1);
	
	while(result.size()){
		printf("%d ",result.front());
		result.pop_front();
	}

	return 0;
}