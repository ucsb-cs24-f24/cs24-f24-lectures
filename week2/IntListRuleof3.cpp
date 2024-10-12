#include <iostream>
using namespace std;

class IntList
{
public:
    IntList() { head = nullptr; }
    IntList(const IntList & other){copy(other);}
   ~IntList(){clear();}
    void print() const;
    void push_front(int value);
    // operator=(const IntList & other);
    IntList & operator=(const IntList & other);
   

private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head;
    void clear();
    void copy(const IntList & other);
};


IntList & IntList::operator=(const IntList & other){
    clear();
    copy(other);
    return * this;
}

// IntList::operator=(const IntList & other){
//     clear();
//     copy(other);
// }

void IntList::copy(const IntList & other)
{
    if (!other.head)
    {
        head  = nullptr;
    }
    else
    {
        head = new Node{other.head->data, nullptr};

        Node * curr = head;
        Node * otherCurr = other.head->next;
        while(otherCurr)
        {   
            curr->next = new Node{otherCurr->data, nullptr};
            curr = curr->next;
            otherCurr = otherCurr->next;
        }
    }
}

void IntList::clear()
{
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
}

void IntList::push_front(int value)
{
    head = new Node{value, head};
}

void IntList::print() const
{
    Node *p = head;
    while (p)
    {
        cout << "[" << p->data << "]";
        p = p->next;
        if (p)
            cout << "->";
    }
    cout << endl;
}

// int main()  // Test 1, Defined Destructor.
// {
//     // IntList x, y; 
//     // x.push_front(10);
//     // x.push_front(20);

//     // y = x;
//     // y.print();
//     // return 0;
//     int * x;
//     delete x; // free() segmentation fault

//     int *a = new int (1); // double free() segmentation fault
//     int* b = a;
   
//     delete a; // = free(a);
//     delete b;
// } 

int main() // Test 2, Defined Destructor, Copy Constructor.
{
    IntList x;
    x.push_front(10);
    x.push_front(20);

    IntList y(x);
    y.push_front(30);
    y.push_front(40);

    IntList z;
    z = y = x;
    z.print();
}