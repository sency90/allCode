#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TreeNode{
	int data;
	
	struct TreeNode *left, *right;
}TreeNode;

TreeNode *root;

// Init Tree
void InitTree(int data){
	TreeNode *new;
	new = (TreeNode*)(malloc(sizeof(TreeNode)));
	
	root = new;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
}
	
// Add Child
TreeNode *AddChild(TreeNode *parent, int data, char which){
	
	TreeNode *new;
	new = (TreeNode*)(malloc(sizeof(TreeNode)));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	
	if(which == 'r'){
		if(parent->right != NULL){
			printf("can not add \n");
			return 0;
		}
		parent->right = new;
	}else if(which == 'l'){
		if(parent->left != NULL){
			printf("can not add \n");
			return 0;
		}
		parent->left = new;
	}
	
	return new;
}

void find_tree(TreeNode *root, int *pre, int *post, int len);

// In Order Tree Function
void InOrder(TreeNode *root){
	if(root->left){
		InOrder(root->left);
	}
	
	printf("%d ",root->data);
	
	if(root->right){
		InOrder(root->right);
	}
}

int main(){
	
	int nodeNum = 0; // Node Number
	
	scanf("%d",&nodeNum); // Input the Node Number
	
	// When Node over 1000 or below 0
	if(nodeNum < 0 || nodeNum > 1000){
		printf("node number erorr ");
		return -1;
	}
	
	// Init Orders
	int preOrder[nodeNum];
	int postOrder[nodeNum];
	
	// Input Pre-Order orders
	for(int i=0; i<nodeNum; i++){
		scanf("%d",&preOrder[i]);
	}
	
	// Input Post-Order orders
	for(int i=0; i<nodeNum; i++){
		scanf("%d",&postOrder[i]);
	}
	
	// Init Tree Root Node
	InitTree(preOrder[0]);
	
	//find Tree
	find_tree(root,preOrder,postOrder,nodeNum);
		
	// Output In-Order orders
	InOrder(root);
	
	printf("\n");
}

void find_tree(TreeNode *rootNode, int *pre, int *post, int len){
	
	int indPreRight = 0;
	int indPostLeft = 0;
	
	int lenLeft = 0;
	int lenRight = 0;
	
	// find right root in pre-order
	for(int i=1; i<len; i++){
		if(pre[i] == post[len-2]){
			indPreRight = i;
			break;
		}
		lenLeft++;
	}
	
	lenRight = len-lenLeft-1;

	int newPreLeft[lenLeft];
	int newPreRight[lenRight];
	
	for(int i=1; i<indPreRight; i++){
		newPreLeft[i-1] = pre[i];
	}
	
	for(int i=indPreRight; i<len; i++){
		newPreRight[i-indPreRight] = pre[i];
	}
	
	// find left root in post-order
	for(int i=0; i<len; i++){
		if(post[i] == pre[1]){
			indPostLeft = i;
			break;
		}
	}
	
	int newPostLeft[lenLeft];
	int newPostRight[lenRight];
	
	for(int i=0; i<indPostLeft+1; i++){
		newPostLeft[i] = post[i];
	}
	
	for(int i=indPostLeft+1; i<len-1; i++){
		newPostRight[i-indPostLeft-1] = post[i];
	}
	
	TreeNode *new_left;
	new_left = (TreeNode*)(malloc(sizeof(TreeNode)));
	new_left->data = pre[1];
	new_left->left = NULL;
	new_left->right = NULL;
	
	TreeNode *new_right;
	new_right = (TreeNode*)(malloc(sizeof(TreeNode)));
	new_right->data = post[len-2];
	new_right->left = NULL;
	new_right->right = NULL;	
	
	if(lenLeft > 0){
		new_left = AddChild(rootNode,pre[1],'l');
	}
	
	if(lenRight > 0){
		new_right = AddChild(rootNode,post[len-2],'r');
	}

	if(len < 4) return;
	
	if(lenLeft > 0) {
		find_tree(new_left, newPreLeft, newPostLeft, lenLeft);
	}
	
	if(lenRight > 0){
		find_tree(new_right, newPreRight, newPostRight,lenRight);
	}
}
