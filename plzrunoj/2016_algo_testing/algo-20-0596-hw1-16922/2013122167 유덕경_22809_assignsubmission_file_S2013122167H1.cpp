#include <iostream>

using namespace std;



class Node
{
private:
	int data;
	Node *left;
	Node *right;
public:

	Node(int n) {data = n;}

	int bring_data() {return data;}
	
	Node *input_left() {return left;}
	Node *input_right() {return right;}

	void arrange_left(int x) {left = new Node(x);}
	void arrange_right(int x) {right = new Node(x);}

};

class order
{
private:
	int *data;
	int n;
public:
	order() {}
	order(int *data_, int n_)
	{
		data = new int[n_];
		n = n_;
		int i;

		for (i = 0; i < n; i++)
		{
			data[i] = data_[i];
		}
	}
	int bring_data(int i)
	{
		return data[i];
	}
	int get_position(int x)
	{
		int i;
		for (i = 0; i < n; i++)
		{
			if (data[i] == x) return i;
		}
		return -1;
	}
};

class Stack
{
private:
	Node *data[1000];
	int Size;
public:
	Stack()
	{
		Size = 0;
	}
	void push(Node *x)
	{
		data[Size++] = x;
	}
	Node *pop()
	{
		return data[--Size];
	}
};

class tree
{
private:
	Node *root;
	Node *current;
public:
	Node* get_root()
	{
		return root;
	}
	void arrage_tree(order Preorder, order Postorder, int n)
	{
		int i;
		int x;
		Stack sta;

		for (i = 0; i < n; i++)
		{
			x = Preorder.bring_data(i);
			if (i == 0)
			{
				root = new Node(x);
				current = root;
			}
			else
			{
				if (Postorder.get_position(x) < Postorder.get_position(current->bring_data()))
				{
					current->arrange_left(x);
					sta.push(current);
					current = current->input_left();
				}
				else
				{
					while (Postorder.get_position(x) > Postorder.get_position(current->bring_data()))
					{
						current = sta.pop();
					}
					current->arrange_right(x);
					sta.push(current);
					current = current->input_right();
				}
			}
		}
	}
	void show_inorder(Node *current_)
	{
		if (current_->input_left() != NULL) show_inorder(current_->input_left());
	
		cout << current_->bring_data() << " ";

		if (current_->input_right() != NULL) show_inorder(current_->input_right());
	}
};

int main()
{
	tree a;
	int *data;
	int n;
	int i;
	cout << "숫자 n을 입력하세요";
	cin >> n;
	data = new int[n];


	cout << "전위 순회한 결과값:";
	for (i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	order Preorder(data, n);

	cout << "후위 순회한 결과값:";
	for (i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	order Postorder(data, n);

	a.arrage_tree(Preorder, Postorder, n);
	cout << "중위 순회된 값:";
	a.show_inorder(a.get_root());
	
	system("pause");
}