#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

Node* SortTwoSortedLists(Node* &h1, Node* &h2){
    if(h1==NULL) return h2;
    if(h2==NULL) return h1;
    Node* head=NULL;
    Node* prev=NULL;
    if(h1->data < h2->data) { 
        head=h1;
        prev=h1;
        h1=h1->next;
    }
    else{
        head=h2;
        prev=h2;
        h2=h2->next;
    }
    // Node* prev = NULL;
    while(h1!=NULL && h2!=NULL){
        if(h1->data<h2->data){
            prev->next=h1;
            h1=h1->next;
        }else{
            prev=h2;
            h2=h2->next;
        }
    }if(h2==NULL){
        prev->next=h1;
    }else{
        prev->next=h2;
    }
    return head;
}

int main() {
	Node* head = new Node(1);
	head -> next = new Node(4);
	head -> next -> next = new Node(50);
// 		while(head!=NULL){
// 	    cout<<head->data<<" ";
// 	    head = head->next;
// 	}
// 	head = rev_rec(head);
    // reverse(head);
    // head = reverseK(head,2);
    Node* head1 = new Node(2);
    head1->next = new Node(5);
    head1->next->next = new Node(10);
    head = SortTwoSortedLists(head,head1);
    
	while(head!=NULL){
	    cout<<head->data<<" ";
	    head = head->next;
	}
// 	return 0;
}