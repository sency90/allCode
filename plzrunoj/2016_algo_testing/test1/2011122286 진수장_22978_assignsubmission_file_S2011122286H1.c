#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> pre_order, post_order;
int isExist(int num, vector<int> arr);
void make_inorder(vector<int> pre, vector<int> post);
int Root;

int main()
{
	int tmp;
	scanf("%d", &Root);
	for (int i = 0; i < Root; i++){
		scanf("%d ", &tmp);
		if( tmp >=1 && tmp<= 1000 && !isExist(tmp, pre_order) )	pre_order.push_back(tmp);
	}

	for (int i = 0; i < Root; i++){
		scanf("%d ", &tmp);
		if ( tmp >= 1 && tmp <= 1000 && !isExist(tmp, post_order) )	post_order.push_back(tmp);
	}
	
	make_inorder(pre_order, post_order);

	return 0;
}

// if a number exists in that node than return arr's index
int isExist(int num, vector<int> arr)
{
	if (find(arr.begin(), arr.end(), num) != arr.end())
		return true;
	else
		return false;
}

void make_inorder(vector<int> pre, vector<int> post)
{
	int root = 0;
	root = pre.at(0);
	vector<int> L_pre, L_post, R_pre, R_post;

	vector<int>::iterator end_point = find(post.begin(), post.end(), pre.at(1));
	vector<int>::iterator start = post.begin();

	int index = (end_point - start) + 1;	// 1부터 indexing 시작했으므로 연산 결과에서 1 더함
	
	//////////////// Retrieve L ///////////////////
	for (int i = 1; i < 1 + index; i++)
	{
		L_pre.push_back(pre.at(i));
	}
	
	for (int i = 0; i < index; i++)
	{
		L_post.push_back(post.at(i));
	}
	//////////////// Retrieve R ///////////////////
	for (int i = index + 1; i < pre.size(); i++)
	{
		R_pre.push_back(pre.at(i));
	}

	for (int i = index; i < post.size() - 1; i++)
	{
		R_post.push_back(post.at(i));
	}

	///////////////////output part///////////////////

	if (L_pre.size() == 1 && L_post.size() == 1){
		printf("%d ", L_pre.at(0));
	}
	else
		make_inorder(L_pre, L_post);

	printf("%d ", root);

	if (R_pre.size() == 1 && R_pre.size() == 1)
		printf("%d ", R_pre.at(0));
	else{
		if (R_pre.size() != 0 && R_post.size() != 0)
			make_inorder(R_pre, R_post);
	}
}