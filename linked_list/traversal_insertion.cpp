// #include<bits/stdc++.h>
// using namespace std;

// //size of node is double the size of the data type present
// // if parameter and argument both are pointer than a copy of that pointer will be made in the function

//  struct Node{
//  	int data;
//  	struct Node* next;
//  	Node( int d){
//  		data = d;
//  		next=nullptr;
//  	}
// };
// void insertAtBegin(Node** head, int d){
// 	Node *new_node = new Node(d);
// 	new_node->next = (*head);
// 	(*head) = new_node;
// }
// void insertAtEnd(Node** head, int d){
// 	Node *new_node = new Node(10);
// 	Node* node = (*head);
// 	if((*head)==nullptr) (*head) = new_node;
// 	else{
// 		while(node->next !=nullptr){
// 			node = node->next;
// 		}
// 		node->next = new_node;
// 	}
// }
// void forward_traversal(Node* head){
// 	Node * temp = head;
// 	while(temp!=nullptr){
// 		cout<<temp->data<<" ";
// 		temp = temp->next;
// 	}
// }

// void freeing(Node * head){
// 	Node * node = head;
// 	while(head!=nullptr){
// 		node = head->next;
// 		free(head);
// 		head = node;
// 	// }
// }

// int main(){
// 	Node* first = nullptr;
// 	Node* second;
// 	Node*  third;
// 	first = new Node(1);
// 	// second = new Node(2);
// 	// third = new Node(3);

// 	// first->next = second;
// 	// second->next = third;

// 	insertAtBegin(&first,6);
// 	insertAtEnd(&first, 10);
// 	forward_traversal(first);

// 	// Node * temp = first;
// 	// while(temp!=nullptr){
// 	// 	cout<<temp->data<<" ";
// 	// 	temp = temp->next;
// 	// }
// 	freeing(first);
// }