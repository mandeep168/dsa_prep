#include<iostream>
#include<vector>
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

// O(n)
node* buildBalancedBST(vector<int> &v, int start_index, int end_index){
	if(start_index > end_index){
		 return NULL;
	}
	int mid = start_index+(end_index-start_index)/2;
	node* root = new node(v[mid]);
	root->left = buildBalancedBST(v,start_index,mid-1);
	root->right = buildBalancedBST(v,mid+1,end_index);

	return root;
}

int inorderSuccessor(node* root, int key){
	int successor;
	while(root!=NULL){
		if(root->key > key) successor = root->key;
		if(key<root->key) root=root->left;
		else root=root->right;
	}
	return successor;
}

class  LinkedList{
public: 
	node* head;
	node* tail;
};

// O(n)
LinkedList tree2LL(node* root){
	LinkedList l;
	if(root==NULL){
		l.head = l.tail = NULL;
		return l;
	} 

	if(root->left == NULL and root->right == NULL){
		l.head = l.tail = root;
	}else if(root->left == NULL and root->right != NULL){
		LinkedList RightLL = tree2LL(root->right);
		root->right = RightLL.head;

		l.head = root;
		l.tail = RightLL.tail;
	}else if(root->left != NULL and root->right == NULL){
		LinkedList LeftLL = tree2LL(root->left);
		LeftLL.tail->right = root;

		l.head = LeftLL.head;
		l.tail = root;	
	}
	else{
		LinkedList RightLL = tree2LL(root->right);
		LinkedList LeftLL = tree2LL(root->left);

		LeftLL.tail->right = root;
		root->right = RightLL.head;

		l.head = LeftLL.head;
		l.tail = RightLL.tail;
	}
	return l;
}

// O(n)
void printInOrder(node* root){
	if(root==NULL) return;

	printInOrder(root->left);
	cout<<root->key<<" ";
	printInOrder(root->right);
}

// O(height)
int closestToX(node* root,int key){
	int closest = root->key;
	int diff = INT_MAX;


	while(root!=NULL){
		
		if(diff==0) return root->key;

		if(abs(root->key - key) < diff){
			diff = abs(root->key - key);
			closest = root->key;
		}
		if(key<root->key) root=root->left;
		else root=root->right;
	}
	return closest;
}

int main(){
	vector<int> v = {1,2,3,4,5,6,63};
	node* root = buildBalancedBST(v, 0, 6);
	printInOrder(root);
	cout<<"\n";
	// LinkedList LL = tree2LL(root);
	// root = LL.head;
	// while(root!=NULL){
	// 	cout<<root->key<<", ";
	// 	root=root->right;
	// }
	

	// cout<<closestToX(root,60);

	cout<<inorderSuccessor(root,1);

}
