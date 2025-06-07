#include <iostream>

using namespace std;

class Node
{
private:
	int data;
	Node *left;
	Node *right;
public:
	Node(int n)
	{
		data = n;
	}
	int get_data()
	{
		return data;
	}
	Node *get_left()
	{
		return left;
	}
	Node *get_right()
	{
		return right;
	}
	void make_left(int x)
	{
		left = new Node(x);
	}
	void make_right(int x)
	{
		right = new Node(x);
	}
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
	int get_data(int i)
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
	void make_tree(order Preorder, order Postorder, int n)
	{
		int i;
		int x;
		Stack sta;

		for (i = 0; i < n; i++)
		{
			x = Preorder.get_data(i);
			if (i == 0)
			{
				root = new Node(x);
				current = root;
			}
			else
			{
				if (Postorder.get_position(x) < Postorder.get_position(current->get_data()))
				{
					current->make_left(x);
					sta.push(current);
					current = current->get_left();
				}
				else
				{
					while (Postorder.get_position(x) > Postorder.get_position(current->get_data()))
					{
						current = sta.pop();
					}
					current->make_right(x);
					sta.push(current);
					current = current->get_right();
				}
			}
		}
	}
	void In(Node *current_)
	{
		if (current_->get_left() != NULL) 
			In(current_->get_left());

		cout << current_->get_data() << " ";
		if (current_->get_right() != NULL) In(current_->get_right());
	}
};

int main()
{
	tree a;
	int *data;
	int n;
	cin >> n;
	data = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	order Pre(data, n);

	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	order Post(data, n);

	a.make_tree(Pre, Post, n);
	a.In(a.get_root());
}