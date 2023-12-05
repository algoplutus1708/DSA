#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nL endl
#define vll vector<ll>

class Node{
public:
  ll data;
  Node* next;
  //Constructor
  Node(ll data){
    this->data = data;
    this->next = NULL;
  }
};

Node* convArrToLL(vll &arr){ //We can't return the whole linked list, so we return the pointer to the head.
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(ll i=1;i<=arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover-> next=temp;
        mover=temp;
    }
    return head;
}

//Deletion of Head
Node* delHead(Node* head){//This code doesn.t work in some edge cases.
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

Node* remHead(Node* head){
    if(head==NULL) return head;// If the linked list is empty.
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

//Deletion Of Tail
Node* delTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;// If the linked list has 1 or 0 elements.
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}

//Deletion Of Kth Element
Node* delKth(Node* head,ll k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    ll cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
}

//Deletion of a Given Value
Node* delEl(Node* head,ll k){
    if(head==NULL) return head;
    if(head->data==k){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==k){
            prev->next=prev->next->next;
            free(temp);
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
}
signed main() {
  vll v={1,2,3,4,5,6};
  Node* head=convArrToLL(v);
  cout<<head->data<<nL;
  head=delTail(head);
  return 0;
}