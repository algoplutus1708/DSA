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
  Node(ll data,Node* next){
    this->data = data;
    this->next = NULL;
  }
};

// void insertAtHead(Node* &head, ll d){ //We have taken refrence of head such that a copy of the same is not made.
//     Node* temp= new Node(d);
//     temp-> next=head;
//     head=temp;
// }

signed main() {
  vll v={1,2,3,4,5,6};
  Node* node1= new Node(v[0],nullptr); // nullptr is a keyword when we expect a NULL value.
  cout<<node1->data<<nL;
  cout<<node1->next<<nL;
  return 0;
}