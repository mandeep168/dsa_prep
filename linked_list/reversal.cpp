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

//reversal in groups

Node * reverseK(Node* head, int k){
    if(head==NULL) return head;
    int count=0;
    Node* prev=NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
        head->next = reverseK(next,k);
    }
    return prev;
}

//reversal by iteration

void reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = (head);
    Node* nex;
    while(curr!=NULL){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
        //nex = nex->next;
    }
    (head) = prev;
}

//reversal by recursion

Node* rev_rec(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* shead = rev_rec(head->next);
    head->next->next = head;
    head->next=NULL;
    return shead;
}

int main() {
	Node* head = new Node(1);
	head -> next = new Node(2);
	head -> next -> next = new Node(3);
// 		while(head!=NULL){
// 	    cout<<head->data<<" ";
// 	    head = head->next;
// 	}
// 	head = rev_rec(head);
    // reverse(head);
    head = reverseK(head,2);
	while(head!=NULL){
	    cout<<head->data<<" ";
	    head = head->next;
	}
// 	return 0;
}