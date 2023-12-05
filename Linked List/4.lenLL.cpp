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

ll lenLL(Node* head){
    ll cnt=0;
    Node* temp=head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

signed main() {
  vll v={1,2,3,4,5,6};
  Node* head=convArrToLL(v);
  Node* temp=head;
  while(temp){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  ll len=lenLL(head);
  cout<<len<<nL; 
  return 0;
}