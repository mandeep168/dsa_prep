#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};

queue<node*> visited_nodes;


void levelOrder(node* root){
	if(root == NULL) return;

	visited_nodes.push(root);
	visited_nodes.push(NULL);

	while(!visited_nodes.empty()){
		node* temp = visited_nodes.front();
		visited_nodes.pop();
		if(temp==NULL && !visited_nodes.empty()) visited_nodes.push(NULL);
		
		if(temp!=NULL) {cout<<temp->data<<" ";
				if(temp->left) visited_nodes.push(temp->left);
				if(temp->right) visited_nodes.push(temp->right);
			}
		else cout<<"\n";
	}
}

node* buildTree(){
	int d;
	cin>>d;

	if(d==-1) return NULL;

	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}

int main(){
	node* root = buildTree();
	levelOrder(root);
}