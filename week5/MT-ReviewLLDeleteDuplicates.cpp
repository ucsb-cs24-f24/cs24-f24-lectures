#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

Node* deleteDuplicates(Node* head) {
    if (!head) {
        return nullptr;
    }

    Node* temp = head;
    Node* temp2 = head->next;
    int last = head->val;

    while (temp2 != nullptr) {             // while end of Linked list
        if (temp2->val == last) {          // Current number same as last number
            if (temp2->next == nullptr) {  // If last element, just delete and break loop
                temp->next = nullptr;
                break;
            }
            temp2 = temp2->next;  // Not last, then delete that element
            temp->next = temp2;   // and move to next element
        } else {                  // If not the same as last element, jump to next node
            temp = temp2;
            last = temp->val;
            temp2 = temp2->next;
        }
    }

    return head;  // return the head back
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a sorted linked list: 1 -> 1 -> 2 -> 3 -> 3
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);

    cout << "Original list: ";
    printList(head);

    // Remove duplicates
    head = deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    // Cleanup memory
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
