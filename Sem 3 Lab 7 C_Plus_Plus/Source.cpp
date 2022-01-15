#include <iostream>

using namespace std;

struct Node
{
	int x;

	Node* l, * r;
};

void show(Node*& Tree)
{
	if (Tree != NULL)
	{
		show(Tree->l);

		cout << Tree->x << " ";

		show(Tree->r);
	}
}

void add_node(int x, Node*& tree)
{
	if (NULL == tree)
	{
		tree = new Node;

		tree->x = x;

		tree->l = tree->r = NULL;
	}
	if (x < tree->x)
	{
		if (tree->l != NULL)
		{
			add_node(x, tree->l);
		}
		else
		{
			tree->l = new Node;

			tree->l->l = tree->l->r = NULL;

			tree->l->x = x;
		}
	}
	if (x > tree->x)
	{
		if (tree->r != NULL)
		{
			add_node(x, tree->r);
		}
		else
		{
			tree->r = new Node;

			tree->r->l = tree->r->r = NULL;

			tree->r->x = x;
		}
	}
}

int main()
{
	Node* Tree = NULL;

	add_node(6, Tree);

	add_node(4, Tree);

	add_node(6, Tree);

	add_node(1, Tree);

	add_node(0, Tree);

	add_node(3, Tree);

	add_node(-9, Tree);

	add_node(5, Tree);

	show(Tree);
}