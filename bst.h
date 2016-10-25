#pragma once 

#include "node.h"

class BST{
private:
	node* root;

	node* createNode(int data);
	void insert(int data, node* n);

	void inorder(node* n);

	int minvalue(node* n);
	int maxvalue(node* n);

	
	node* retNode(int data, node* n);
	int parent(node* root, int data);
	bool find(int data, node* n);

	void succ(node* root, node* n);
	void pred(node* root, node* n);

	node* FindMin(node* n);
	//node* Delete(node* root, int data);
	
	void Delete(int data, node* parent);
	void deleteRoot();
	void deleteNode(node* parent, node* match, bool LEFT);
public:
	BST();
	~BST();

	node* ROOT();

	void insert(int data);
	void inorder();

	void minvalue();
	void maxvalue();

	bool find(int data);
	node* retNode(int data);
	int parent(int data);

	void succ(int data);
	void pred(int data);

	void Delete(int data);
};