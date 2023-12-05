#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nL endl
#define vll vector<ll>

class Node{
public:
  ll data;
  Node *next;
  // Constructor
  Node(ll data, Node *next){
    this->data = data;
    this->next = next;
  }
};

// Insertion at Head
Node *insHead(Node *head, ll data){
  Node *temp = new Node(data, NULL);
  temp->next = head;
  head = temp;
  return head;
}
Node *insHeadAlt(Node *head, ll data){ // We have implemented it in shortcut
  return new Node(data, head);
}

// Insertion at Tail
Node *insTail(Node *head, ll data){
  if (head == NULL)
    return new Node(data, NULL);
  Node *temp = head;
  Node *newNode = new Node(data, NULL);
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}

// Insertion at Kth Element
Node* insKth(Node *head, ll data, ll k){
  if (head == NULL){
    if (k == 1) return new Node(data, NULL);
    return NULL;
  }
  if(k==1) return new Node(data,head);
  ll cnt=0;
  Node *temp = head;
  while(temp!=NULL){
    cnt++;
    if(cnt>=(k-1)){
      Node * newNode=Node(ll data,NUll);
      newNode->next=temp->next;
      temp->next=newNode;
      break;
    }
    temp=temp->next;
  }
  return head;
}

// Insertion before any value given
Node* insBeforeVal(Node* data,ll data,ll val){
  if (head == NULL) return NULL;

  if(head->data==val) return new Node(data,head);
  ll cnt=0;
  Node *temp = head;
  while(temp!=NULL){
    cnt++;
    if(temp->next->data=val){
      Node * newNode=Node(ll data,NUll);
      newNode->next=temp->next;
      temp->next=newNode;
      break;
    }
    temp=temp->next;
  }
  return head; 
}

Node *convArrToLL(vll &arr){ // We can't return the whole linked list, so we return the pointer to the head.
  Node *head = new Node(arr[0]);
  Node *mover = head;
  for (ll i = 1; i <= arr.size(); i++)
  {
    Node *temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

signed main(){
  vll v = {1, 2, 3, 4, 5, 6};
  Node *head = convArrToLL(v);
  cout << head->data << nL;
  return 0;
}