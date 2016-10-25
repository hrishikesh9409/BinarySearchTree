#include "bst.h"

using namespace std;

int main(){

	BST* bst = new BST();
	
	int n;

	cout << "\nChoose one of the following options : \n";
	cout << "1. insert new nodes\n"; 
	cout << "2. inorder traversal \n";
	cout << "3. minimum value in the tree \n";
	cout << "4. maximum value in the tree \n";
	cout << "5. find node for given value in the tree \n";
	cout << "6. parent of a node \n";
	cout << "7. Successor of a node \n";
	cout << "8. Predecessor of a node \n";
	cout << "9. Delete node \n";
	cout << "10. Exit program\n";
	cout << endl;

	while(true){
		cin >> n;
		if(n >= 1 && n <= 10){
			if(n == 1){
				cout << "\nSpecify the number of elements to be inserted : ";
				int size;
				cin >> size;
				int tree[size];
				cout << "\nEnter tree elements : \n";
				for(int i = 0; i < size; i++){
					cin >> tree[i];
					bst->insert(tree[i]);
				}
			}
			else if(n == 2){
				bst->inorder();
			}
			else if(n == 3){
				bst->minvalue();
			}
			else if(n == 4){
				bst->maxvalue();
			}
			else if(n == 5){
				cout << "\nEnter the key to be searched : \n";
				int key;
				cin >> key;
				if(bst->find(key) == 0)
					cout << "\nKey value does not exist in tree\n";
				else
					cout << "\nKey value exists in tree\n";
			}
			else if(n == 6){
				cout << "\nEnter the node value whose parent is to be found : \n";
				int key;
				cin >> key;
				int p = bst->parent(key);
				cout << "Parent node value : " << p << endl;
			}
			else if(n == 7){
				cout << "\nEnter the value whose successor is to be found : \n";
				int key;
				cin >> key;
				bst->succ(key);
			}
			else if(n == 8){
				cout << "\nEnter the value whose predecessor is to be found : \n";
				int key;
				cin >> key;
				bst->pred(key);
			}
			else if(n == 9){
				cout << "\nEnter the value to be deleted : \n";
				int key;
				cin >> key;
				bst->Delete(key);
			}
			else if(n == 10){
				cout << "Exiting.....";
				break;
			}
		}
		else{
			cout << "\nEnter values between 1 and 10 only\nPlease try again : \n";
		}
		cout << "\nEnter new operation to be performed : \n";
	}

	cout << endl << endl;

	return 0;
}