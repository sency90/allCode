#include<iostream>
using namespace std;

class node
{
private:
	int data;
	node *left;
	node *right;
public:
	node(){}
	node(int n)
	{
		data = n;
	}
	int get_data()
	{
		return data;
	}
	node* get_left()
	{
		return left;
	}
	node* get_right()
	{
		return right;
	}
	void make_left(int x)
	{
		left = new node(x);
	}
	void make_right(int x)
	{
		right = new node(x);
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

class stack
{
private:
	node *data[1000];
	int size;
public:
	stack()
	{
		size = 0;
	}
	void push(node *x)
	{
		data[size++] = x;
	}
	node *pop()
	{
		return data[--size];
	}
};

class tree
{
private:
	node *root;
	node *current;
public:
	node* get_root()
	{
		return root;
	}
	void make_tree(order preorder, order postorder, int n)
	{
		int i;
		int x;
		stack sta;
		
		for (i = 0; i < n; i++)
		{
			x = preorder.get_data(i);
			if (i == 0)
			{
				root = new node(x);
				current = root;
			}
			else
			{
				if (postorder.get_position(x) < postorder.get_position(current->get_data()))
				{
					current->make_left(x);
					sta.push(current);
					current = current->get_left();
				}
				else
				{
					while (postorder.get_position(x) > postorder.get_position(current->get_data()))
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
	void print_inorder(node *current_)
	{
		if (current_->get_left() != NULL) print_inorder(current_->get_left());
		cout << current_->get_data() << " ";
		if (current_->get_right() != NULL) print_inorder(current_->get_right());
	}
};

int main()
{
	tree a;
	int *data;
	int n;
	int i;

	cin >> n;
	data = new int[n];

	for (i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	order preorder(data, n);

	for (i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	order postorder(data, n);

	a.make_tree(preorder, postorder, n);
	a.print_inorder(a.get_root());
}