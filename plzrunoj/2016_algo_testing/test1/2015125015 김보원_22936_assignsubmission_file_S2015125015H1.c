#include <stdio.h>

using namespace std;

//��带 �����ϴ� Ŭ����
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

//������ 
Node::Node(int data)
{
	mData = data;
	left = NULL;
	right = NULL;
}

//�ı��� 
Node::~Node(void)
{
}

//Ʈ�� Ŭ���� 
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

//������ 
Tree::Tree(int count, int* pre, int* post)
{
	mNodeCount = count;
	root = makeTree(pre, post, count);
}

//�ı��� 
Tree::~Tree(void)
{
}

//���� Ʈ���� ��ȯ 
Node* Tree::makeTree(int* pre, int* post, int count) {
	int preIndex = 0;
	return makeTreeRecur(pre, post, &preIndex, 0, count - 1, count);
}


// ���� ���� ����� ������ Ʈ���� ���� //����Լ� ��� 
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

//����Լ�
void Tree::printInOrder(Node* node) {
	//��尡 �����Ѵٸ� 
	if (node) {
		printInOrder(node->left); //���� 
		printf("%d ", node->getData());  //���
		printInOrder(node->right); //������  
	}
}

int main(int argc, char** argv) {
	int nodeCnt; //����� ���� �޴� ���� 
	scanf("%d", &nodeCnt);  //�Է¹ޱ� 
	if (nodeCnt > 1000 || nodeCnt < 1) {
		printf ("������ �߸��Ǿ����ϴ�. ���α׷��� �����մϴ�. " );
		return 0;
	}
	int* pre = new int[nodeCnt];   //���� ��ȸ�� ������ �迭
	int* post = new int[nodeCnt];  //���� ��ȸ�� ������ �迭
	for (int i = 0; i < nodeCnt; i++) {   //for������ ������ȸ �Է¹ޱ� 
		scanf("%d", &pre[i]);
	} 
	for (int i = 0; i < nodeCnt; i++) {   //for������ ������ȸ �Է¹ޱ� 
		scanf("%d", &post[i]);
	}

	Tree tree(nodeCnt, pre, post);   //Ŭ������ main()���� ����
	tree.printInOrder(tree.getRoot()); //����ϴ� �Լ� �ҷ��� 

	printf("\n");
	delete[] pre;
	delete[] post;

	return 0;
}