          #include <iostream>
          using namespace std;

          struct Node {
              int val;
              Node* next;
              Node(int x) : val(x), next(NULL) {}
          };

          bool hasCycle(Node* head) {
              if (head == nullptr || head->next == nullptr) {
                  return false;
              }
              Node* slow = head;
              Node* fast = head->next;
              while (slow != fast) {
                  if (fast == nullptr || fast->next == nullptr) {
                      return false;
                  }
                  slow = slow->next;
                  fast = fast->next->next;
              }
              return true;
          }

          // Helper function to create a linked list with a cycle for testing
          Node* createLinkedListWithCycle() {
              Node* head = new Node(3);
              Node* node1 = new Node(2);
              Node* node2 = new Node(0);
              Node* node3 = new Node(-4);

              head->next = node1;
              node1->next = node2;
              node2->next = node3;
              node3->next = node1; // Creating a cycle

              return head;
          }

          // Helper function to create a linked list without a cycle for testing
          Node* createLinkedListWithoutCycle() {
              Node* head = new Node(1);
              Node* node1 = new Node(2);

              head->next = node1;
              node1->next = nullptr; // No cycle

              return head;
          }

          int main() {
              // Test with a linked list that has a cycle
              Node* headWithCycle = createLinkedListWithCycle();
              if (hasCycle(headWithCycle)) {
                  cout << "The linked list has a cycle." << endl;
              } else {
                  cout << "The linked list does not have a cycle." << endl;
              }

              // Test with a linked list that does not have a cycle
              Node* headWithoutCycle = createLinkedListWithoutCycle();
              if (hasCycle(headWithoutCycle)) {
                  cout << "The linked list has a cycle." << endl;
              } else {
                  cout << "The linked list does not have a cycle." << endl;
              }

              // Cleanup for the first list with cycle (manual cleanup due to cycle)
              delete headWithCycle->next->next->next; // node3
              delete headWithCycle->next->next;       // node2
              delete headWithCycle->next;             // node1
              delete headWithCycle;                   // head

              // Cleanup for the second list without cycle
              delete headWithoutCycle->next;          // node1
              delete headWithoutCycle;                // head

              return 0;
          }
