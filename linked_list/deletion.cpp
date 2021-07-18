// #include<iostream>
// using namespace std;

// 
// template<typename T>
// class Node{
//     T data;
//     Node<T> *next;
// public:
//     Node(T data){
//         this->data = data;
//         next = nullptr;
//     }
// }
// struct Node{
// 	int data;
// 	Node* next;
// 	Node(int d){
// 		data = d;
// 		next = nullptr;
// 	}
// };

// void deletionAtBegin(Node** head){
// 	if((*head)==nullptr) return;
// 	Node* node = (*head);
// 	(*head) = (*head)->next;
// 	free(node);
// }

// void deletionAtLast(Node** head){
// 	if((*head)==nullptr) return;
// 	Node* node = (*head);
// 	if(node->next==nullptr) {
// 		(*head) = nullptr;
// 		free(node);
// 	}
// }

// void forward_traversal(Node *head){
// 	while(head!=nullptr){
// 		cout<<head->data<<" ";
// 		head=head->next;
// 	}
// 	cout<<"\n";
// }

// int main(){
// 	Node* head = new Node(10);
// 	head->next = new Node(15);
// 	deletionAtBegin(&head);
// 	forward_traversal(head);

// }