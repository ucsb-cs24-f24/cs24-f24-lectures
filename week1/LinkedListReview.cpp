// Non-OOP style implementation to contrast against the OOP style
#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* push_front(Node* h, int value){
  // Node * newNode = new Node;
  // newNode->data = value;
  // newNode->next = h;
  // return newNode;
    return new Node{value, h};
}

Node* reverseList(Node* head) {
    if(!head) return nullptr;
    if(!head->next) return head;
    Node* new_head = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head; 
}

void printList(Node* head){
    Node* curr = head;
    while(curr){
        cout << "["<< curr->data << "]";
        curr = curr->next;
        if(curr) cout << "->";
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    head = push_front(head, 10);
    head = push_front(head, 20);
    head = push_front(head, 30);
    head = push_front(head, 40);
    printList(head);
    head = reverseList(head);
    printList(head);
    return 0;
}