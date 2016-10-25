#include "bst.h"

using namespace std;


/*****************CONSTRUCTOR AND DESTRUCTOR********************/
BST::BST(){
	root = NULL;
}
				
BST::~BST(){}

/**********************CREATE NEW NODES*************************/
node* BST::createNode(int data){
	node* n = new node();	//Create new node		
	n->data = data;			//Enter data into new node

	return n;
}

node* BST::ROOT(){			//Return root node
	return root;
}
/*******************INSERT NEW NODES******************************/

void BST::insert(int data){
	insert(data, root);
}

void BST::insert(int data, node* n){
	if(root == NULL){
		root = createNode(data);
	}
	else if(data < n->data){
		if(n->left != NULL){
			insert(data, n->left);
		}
		else{
			n->left = createNode(data);
		}
	}
	else if(data > n->data){
		if(n->right != NULL){
			insert(data, n->right);
		}
		else{
			n->right = createNode(data);
		}
	}
	else
		std::cout << "\nData " << data << " already exists\n";
}
/**********************INORDER TRAVERSAL***********************/

void BST::inorder(){
	inorder(root);
}

void BST::inorder(node* n){
	if(root != NULL){
		if(n->left != NULL){
			inorder(n->left);
		}

		cout << n->data << " ";

		if(n->right != NULL){
			inorder(n->right);
		}
	}
	else{
		cout << "\nThe tree is empty\n";
	}
}
/******************MIN MAX VALUE********************************/

void BST::minvalue(){
	int min = minvalue(root);
	cout << endl << "Minimum value = " << min << endl;
}

int BST::minvalue(node* n){
	if(root == NULL){
		cout << "\nThe tree is empty\n";
		return 0;
	}
	else{
		if(n->left == NULL){
			return n->data;
		}
		else
			return minvalue(n->left);
	}
}

void BST::maxvalue(){
	int max = maxvalue(root);
	cout << endl << "Maximum value = " << max << endl;
}

int BST::maxvalue(node* n){
	if(root == NULL){
		cout << "\nThe tree is empty\n";
		return 0;
	}
	else{
		if(n->right == NULL){
			return n->data;
		}
		else
			return maxvalue(n->right);
	}
}
/**********************FIND FUNCTION****************************/

bool BST::find(int data){
	return (find(data, root));

}

bool BST::find(int data, node* n){
	if(n == NULL){
		return false;
	}
	else{
		if(n->data == data){
			return true;
		}
		else{
			if(data < n->data){
				return find(data, n->left);
			}
			else if(data > n->data){
				return find(data, n->right);
			}
		}
	}
}

/**************RETURN NODE GIVEN VALUE**************************/

node* BST::retNode(int data){
	return (retNode(data, root));
}

node* BST::retNode(int data, node* n){
	if(n == NULL){
		return NULL;
	}
	else{
		if(n->data == data){
			return n;
		}
		else{
			if(data < n->data){
				return retNode(data, n->left);
			}
			else if(data > n->data){
				return retNode(data, n->right);
			}
		}
	}
}

/**********************RETURN PARENT*****************************/

int BST::parent(int data){
	int P = 0;
	if(find(data) == 0)
		cout << "\nKey node does not exist in the tree\n";
	else
		P = parent(root, data);
	return P;
}

int BST::parent(node* root, int data){
	if(root == NULL){
		cout << "\nTree is empty\n";
		return 0;
	}
	if(root->left == NULL && root->right == NULL){
		return root->data;
	}
	if((root->left != NULL && root->left->data == data) || (root->right != NULL && root->right->data == data))
		return root->data;
	if(data < root->data)
		return parent(root->left, data);
	if(data > root->data)
		return parent(root->right, data);
}

/***************************SUCCESSOR****************************/

void BST::succ(int data){
	node* temp = new node();
	temp = retNode(data);
	if(find(data) == 0)
		cout << "\nKey node does not exist in tree\n";
	else
		succ(root, temp);
}

void BST::succ(node* root, node* n){
	if(n->right != NULL){
		int successor = minvalue(n->right);
		cout << endl << "Successor of " << n->data << " = " << successor << endl;
	}
	else if(n->right == NULL){
		node* successor = new node();

		while(root != NULL){
			if(n->data < root->data){
				successor = root;
				root = root->left;
			}
			else if(n->data > root->data){
				root = root->right;
			}
			else{
				break;
			}

		}
		if(successor->data > 0)
			cout << endl << "Successor of " << n->data << " = " << successor->data << endl;
		else
			cout << endl << "Successor of " << n->data << " cannot be displayed as it is the edge most leaf node of the tree" << endl;
	}	
}
/*******************PREDECESSOR*********************/

void BST::pred(int data){
	node* temp = new node();
	temp = retNode(data);
	if(find(data) == 0)
		cout << "\nKey node does not exist in tree\n";
	else
		pred(root, temp);
}

void BST::pred(node* root, node* n){
	if(n->left != NULL){
		int predecessor = maxvalue(n->left);
		cout << endl << "Predecessor of " << n->data << " = " << predecessor << endl;
	}
	else{
		node* predecessor = new node();

		while(root != NULL){
			if(n->data > root->data){
				predecessor = root;
				root = root->right;
			}
			else if(n->data < root->data){
				root = root->left;
			}
			else 
				break;
		}
		if(predecessor->data > 0)
			cout << endl << "Predecessor of " << n->data << " = " << predecessor->data << endl;
		else
			cout << endl << "Predecessor of " << n->data << " cannot be displayed as it is the root node of the tree" << endl;
	}	
}
/************************DELETE NODE*****************************/

void BST::Delete(int data){
	Delete(data, root);
}

void BST::Delete(int data, node* parent){
	if(root != NULL){
		if(data == root->data){
			deleteRoot();
		}
		else{
			if(data < parent->data && parent->left != NULL){
				if(data == parent->left->data){
					deleteNode(parent, parent->left, true);
				}
				else{
					Delete(data, parent->left);
				}
			}
			else if(data > parent->data && parent->right != NULL){
				if(data == parent->right->data){
					deleteNode(parent, parent->right, false);
				}
				else{
					Delete(data, parent->right);
				}
			}
			else{
				cout << "\nThe key " << data << " is not present in the tree\n";
			}
		}
	}
	else{
		cout << "\nError cannot delete node, the tree is empty\n";
	}
}
/*************************************/

void BST::deleteRoot(){
	if(root != NULL){
		node* del = root;
		int data = root->data;
		int smallestRightSubtree;

		// 0 children
		if(root->left == NULL && root->right == NULL){
			root = NULL;
			delete del;
		}

		// 1 child
		else if(root->left == NULL && root->right != NULL){
			root = root->right;
			del->right = NULL;
			delete del;
		}
		else if(root->right == NULL && root->left != NULL){
			root = root->left;
			del->left = NULL;
			delete del;
		}

		//2 children
		else{
			smallestRightSubtree = minvalue(root->right);
			Delete(smallestRightSubtree, root);
			root->data = smallestRightSubtree;
		}
	}
	else{
		cout << "\nError cannot delete node, the tree is empty\n";
	}
}
/*************************************/

void BST::deleteNode(node* parent, node* match, bool LEFT){
	if(root != NULL){
		node* del;
		int matchKey = match->data;
		int smallestRightSubtree;

		//0 children
		if(match->left == NULL && match->right == NULL){
			del = match;
			if(LEFT == true){
				parent->left = NULL;
			}
			else{
				parent->right = NULL;
			}
			delete del;
		}

		//1 child
		else if(match->left == NULL && match->right != NULL){
			if(LEFT == true){
				parent->left = match->right;
			}
			else{
				parent->right = match->right;
			}
			match->right = NULL;
			del = match;
			delete del;
		}
		else if(match->right == NULL && match->left != NULL){
			if(LEFT == true){
				parent->right = match->left;
			}
			else{
				parent->right= match->left;
			}
			match->left = NULL;
			del = match;
			delete del;
		}

		//2 children
		else{
			smallestRightSubtree = minvalue(match->right);
			Delete(smallestRightSubtree, match);
			match->data = smallestRightSubtree;
		}
	}
	else{
		cout << "\nThe tree is empty, cannot delete node\n";
	}
}


