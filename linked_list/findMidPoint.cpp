#include<bits/stdc++.h>
using namespace std;

//Runners Technique

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

int getMid(node *head){
      if(head==NULL) return -1;
    //Complete this function to return data middle node
    node* head2=head;
    if(head->next==NULL) return head->data;
    while(head->next!=NULL && head->next->next!=NULL){
        // cout<<head->data;
        head=head->next->next;
        head2 = head2->next;
    }
    return head2->data;
    
    
    
}int main(){
    node* head=new node(1);
   node* second=new node(2);
  node* third= new node(3);
//   head->next->next=third;
  head->next=second;
  second->next=third;
    // head->next->next->next=
    node* forth=new node(4);
    third->next=forth;
    cout<<getMid(head);
}