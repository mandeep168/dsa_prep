#include<iostream>
using namespace std;

class node{
public:
	int key;
	node* left;
	node* right;

	node(int key){
		this->key = key;
		this->left = NULL;
		this->right = NULL;
	}
};
 
//building a bst
node* insert(node* root, int key){
	if(root == NULL) {
		root = new node(key);
		return root;
	}
	if(key<=root->key){
		root->left= insert(root->left, key);
	}
	else
		root->right = insert(root->right, key);
	return root; 
}

void printInOrder(node* root){
	if(root==NULL) return;

	printInOrder(root->left);
	cout<<root->key<<" ";
	printInOrder(root->right);
}

bool search(node* root, int key){
	if(root == NULL) return 0;
	if(root->key == key) return 1;

	if(key < root->key) return search(root->left,key);
	return search(root->right,key);
}

int main(){
	node* root=NULL;
	int a[] = {8,3,10,1,6,14,4,7,13};

	for(int x:a){
		root = insert(root,x);
	}
	printInOrder(root);

	cout<<"\n";

	cout<<search(root, 13);

}