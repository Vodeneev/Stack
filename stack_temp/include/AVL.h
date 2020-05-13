#pragma once
#include "iostream"
using namespace std;

struct Node
{
	int id;
	int height;
	Node* right;
	Node* left;
	Node()
	{
		height = 1;
		right = NULL;
		left = NULL;
		id = 0;
	}
};

class AVL
{
	Node* tree;
	
public:
	AVL() 
	{
		tree = new Node;
	}

	int height(Node* i)
	{
		if (i != 0)
			return i->height;
		else
			return 0;
	}

	int balance(Node* i)
	{
		return height(i->right) - height(i->left);
	}

	void fixheight(Node* i) //высота самой длинной цепочки + 1(ребро соединения)
	{
		int hl = height(i->left);
		int hr = height(i->right);
		if (hl > hr)
			i->height = hl + 1;
		else
			i->height = hr + 1;
	}

	Node* rightroate(Node* i)
	{
		Node* k = i->left;
		i->left = k->right; // перевешиваем один узел
		k->right = i;  // перевешиваем поддерево 
		fixheight(i);
		fixheight(k);
		return k;
	}

	Node* leftroate(Node* i)
	{
		Node* k = i->right;
		i->right = k->left; // перевешиваем один узел
		k->left = i;  // перевешиваем поддерево 
		fixheight(i);
		fixheight(k);
		return k;
	}

	Node* balanceroate(Node* i)
	{
		fixheight(i);
		if (balance(i) == 2)
		{
			if (balance(i->right) < 0)
				i->right = rightroate(i->right);
			return leftroate(i);
		}
		if (balance(i) == -2)
		{
			if (balance(i->left) > 0)
				i->left = leftroate(i->left);
			return rightroate(i);
		}
		return i;
	}

	Node* fakeinsert(Node* p, int key)
	{
	
		if (p == NULL)
		{
			Node* k = new Node;
			k->id = key;
			return k;
		}
		if (p->id == 0)
		{
			p->id = key;
			return p;
		}
		else if (p->id > key)
			p->left = fakeinsert(p->left, key);
		else
			p->right = fakeinsert(p->right, key);
		return balanceroate(p);
	}

	void insert(int key)
	{
		tree = fakeinsert(tree, key);
	}
	
	Node* findmin(Node*p)
	{
		if (p->left != NULL)
			findmin(p->left);
		else
			return p;	
	}

	Node* removemin(Node* p)
	{
		if (p->left == NULL)
			return p->right;
		p->left = removemin(p->left);
		return balanceroate(p);
	}

	Node* fakeremove(Node* p, int key)
	{
		if (p == NULL)
			return 0;
		if (p->id > key)
			p->left = fakeremove(p->left, key);
		else if(p->id < key)
			p->right = fakeremove(p->right, key);
		else
		{
			Node* r = p->right;
			Node* q = p->left;
			delete p;
			if (r == NULL)
				return q;
			Node* min = findmin(r);
			min->right = removemin(r);
			min->left = q;
			return balanceroate(min);
		}
		return balanceroate(p);
	}

	void remove(int key)
	{
		tree = fakeremove(tree, key);
	}

	void coutright()
	{
		cout << tree->right->id;
	}

	void coutleft()
	{
		cout << tree->left->id;
	}

	void coutid()
	{
		cout << tree->id;
	}

	Node* tr()
	{
		return tree;
	}

};

