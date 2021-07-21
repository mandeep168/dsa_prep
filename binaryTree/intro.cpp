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

node* build_levelOrder(vector<int> &v){
	queue<node*> q;
	node* temp = new node(v[0]);
	q.push(temp);

	int i=1;
	while(!q.empty()){
		node* parent = q.front();
		q.pop();
		if(v[i]!=-1){
			parent->left = new node(v[i]);
			q.push(parent->left);
		}i++;
		if(v[i]!=-1){
			parent->right = new node(v[i]);
			q.push(parent->right);
		}
		i++;
	}
	return temp;
}

int height(node* root){
	if(root==NULL) return 0;
	int h1 = height(root->left);
	int h2 = height(root->right);
	return 1+max(h1,h2);
}

//diameter of tree
// - max path length between any 2 nodes

// time complexity  O(n^2)
int diameter(node* root){
	//base case
	if(root==NULL) return 0;

	//if diamter will pass through root;
	int D1 = height(root->left) + height(root->right);
	
	//left subtree
	int D2 = diameter(root->left);

	//right subtree
	int D3 =  diameter(root->right);

	return max(D1,max(D2,D3));
}

class HDPair{
public:
	int height;
	int diameter;
};

//O(N)
HDPair optDiameter(node* root){
	HDPair p;
	//base case
	if(root == NULL) {
		p.height = 0;
		p.diameter = 0;
		return p;
	}

	//rec case
	HDPair Left = optDiameter(root->left);
	HDPair Right = optDiameter(root->right);

	p.height = max(Left.height, Right.height) + 1;

	int D1 = Left.height + Right.height;
	int D2 = Left.diameter;
	int D3 = Right.diameter;

	p.diameter = max(D1, max(D2,D3));

	return p;
}

int replace_with_sum_of_descendants(node* root){
	//base case 
	if(root==NULL) return 0;

	if(!root->left && !root->right) return root->data;

	int data = root->data;
	root->data = replace_with_sum_of_descendants(root->left)+replace_with_sum_of_descendants(root->right);
	return data + root->data;
	
}

pair<int, bool> isHeightBalanced(node* root){
	pair<int, bool> p,Left,Right;
	if(root==NULL){
		p.first=0;
		p.second = true;
		return p;
	}
	Left = isHeightBalanced(root->left);
	Right = isHeightBalanced(root->right);

	p.first = max(Left.first, Right.first) + 1;

	if(abs(Left.first - Right.first) <= 1 && Left.second && Right.second) p.second = true;
	else p.second = false;

	return p;
}

class maxSumPair{
public:
	int inc;
	int exc;
};

void PrintAtLevelK(node* root, int k){
	if(k==0) {
		if(root) cout<<root->data<<" ";
		return;
	}
	if(k==1){
		if(root->left) cout<<root->left->data<<" ";
		if(root->right) cout<<root->right->data<<" ";
		return;
	}
	PrintAtLevelK(root->left,k-1);
	PrintAtLevelK(root->right,k-1);

	return;
}

//O(N) time
maxSumPair maxSumOfTree(node* root){
	maxSumPair p;
	//base case
	if(root==NULL){
		p.inc =0,p.exc=0;
		return p;
	}
	maxSumPair Left = maxSumOfTree(root->left);
	maxSumPair Right = maxSumOfTree(root->right);
	p.inc = root->data + Left.exc + Right.exc;

	p.exc = max(Left.inc, Left.exc) + max(Right.inc, Right.exc);

	return p;
}

int main(){
	// node* root = buildTree();
	// levelOrder(root);


	vector<int> v {1,2,3,4,5,-1,6,-1 , -1, 7 ,-1,-1,-1,-1,-1};
	node* root= build_levelOrder(v);
	// cout<<diameter(root);

	// HDPair diameter = optDiameter(root);
	// cout<<diameter.diameter;

	// int val = replace_with_sum_of_descendants(root);
	// levelOrder(root);;

	// pair<int,bool> p = isHeightBalanced(root);
	// if(p.second){
	// 	cout<<"Given binary tree is Balanced.\n";
	// }
	// maxSumPair maxSum = maxSumOfTree(root);
	// cout<<"MAX SUM IS :-: "<< max(maxSum.inc,maxSum.exc);

	PrintAtLevelK(root,2);
}