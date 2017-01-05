#include <stdio.h>

using namespace std;

//노드를 정의하는 클래스
class Node
{
private:
	int mData;
public:
	Node* left;
	Node* right;
	Node(int data);
	~Node(void);

	void setData(int data) {
		mData = data;
	}

	int getData() {
		return mData;
	}
};

//생성자 
Node::Node(int data)
{
	mData = data;
	left = NULL;
	right = NULL;
}

//파괴자 
Node::~Node(void)
{
}

//트리 클래스 
class Tree
{
private:
	int mNodeCount;
	Node* root;
	Node* makeTree(int* pre, int* post, int count);
	Node* makeTreeRecur(int pre[], int post[], int* preIndex, int l, int h, int size);
public:
	Tree(int count, int* pre, int* post);
	~Tree();
	Node* getRoot() {
		return root;
	}
	void printInOrder(Node* node);
};

//생성자 
Tree::Tree(int count, int* pre, int* post)
{
	mNodeCount = count;
	root = makeTree(pre, post, count);
}

//파괴자 
Tree::~Tree(void)
{
}

//만든 트리를 반환 
Node* Tree::makeTree(int* pre, int* post, int count) {
	int preIndex = 0;
	return makeTreeRecur(pre, post, &preIndex, 0, count - 1, count);
}


// 전위 후위 결과를 가지고 트리를 생성 //재귀함수 사용 
Node* Tree::makeTreeRecur(int pre[], int post[], int* preIndex,
	int l, int h, int size)
{
	if (*preIndex >= size || l > h)
		return NULL;
	Node* root = new Node(pre[*preIndex]);
	++*preIndex;

	if (l == h)
		return root;

	int i;
	for (i = l; i <= h; ++i)
		if (pre[*preIndex] == post[i])
			break;

	if (i <= h)
	{
		root->left = makeTreeRecur(pre, post, preIndex, l, i, size);
		root->right = makeTreeRecur(pre, post, preIndex, i + 1, h, size);
	}

	return root;
}

//출력함수
void Tree::printInOrder(Node* node) {
	//노드가 존재한다면 
	if (node) {
		printInOrder(node->left); //왼쪽 
		printf("%d ", node->getData());  //출력
		printInOrder(node->right); //오른쪽  
	}
}

int main(int argc, char** argv) {
	int nodeCnt; //노드의 개수 받는 변수 
	scanf("%d", &nodeCnt);  //입력받기 
	if (nodeCnt > 1000 || nodeCnt < 1) {
		printf ("범위가 잘못되었습니다. 프로그램을 종료합니다. " );
		return 0;
	}
	int* pre = new int[nodeCnt];   //전위 순회를 저장할 배열
	int* post = new int[nodeCnt];  //후위 순회를 저장할 배열
	for (int i = 0; i < nodeCnt; i++) {   //for문으로 전위순회 입력받기 
		scanf("%d", &pre[i]);
	} 
	for (int i = 0; i < nodeCnt; i++) {   //for문으로 후위순회 입력받기 
		scanf("%d", &post[i]);
	}

	Tree tree(nodeCnt, pre, post);   //클래스를 main()에서 실행
	tree.printInOrder(tree.getRoot()); //출력하는 함수 불러옴 

	printf("\n");
	delete[] pre;
	delete[] post;

	return 0;
}