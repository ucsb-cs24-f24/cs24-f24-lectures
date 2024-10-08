// OOP style Linked list
#include <iostream>
using namespace std;

// IntList is an Abstract Data Type
class IntList{
 public:
    //initialization routine: constructor
    IntList() { head = nullptr;}
    // accessors or getter
    int sum() const;
    int front() const;
    int back() const;
    void print() const;

    // mutators or setter
    void reverse();
    void push_front(int value);
    void clear();
    void pop_front();
    void erase(int value);

 private:
    struct Node{
        int data;
        Node* next;
    };
    Node* head;
    Node* reverse(Node* h);
};

int IntList::sum() const{
    return 42;

}
int IntList::front() const{
    return 42;
}
int IntList::back() const{
    return 42;

}
void IntList::print() const{
    Node* p = head;
    while(p){
        cout << "["<< p->data << "]";
        p = p->next;
        if(p) cout << "->";
    }
    cout << endl;

}
typename IntList::Node* IntList::reverse(Node* h){
    if(!h) return nullptr;
    if(!h->next) return h;
    Node* new_head = reverse(h->next);
    h->next->next = h;
    h->next = nullptr;
    return new_head; 

}

// mutators or setter
void IntList::reverse(){
    head = reverse(head);
}
void IntList::push_front(int value){
    head = new Node{value, head};
}
void IntList::clear(){

}
void IntList::pop_front(){

}
void IntList::erase(int value){

}
int main() {
    IntList ll; // object of the class
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);
    ll.print();
    ll.reverse();
    ll.print();
    return 0;
}