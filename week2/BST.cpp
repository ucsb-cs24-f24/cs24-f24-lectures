#include <iostream>
using namespace std;

class BST
{
public:
    BST() {root =  nullptr;}
    bool find(int value) const;
    void printInOrder() const;
    void createSmallBST();

private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        Node(int value) {
            left =nullptr;
            right=nullptr;
            data = value;
        };
    };

    Node *root;
    bool find(int value, Node * n) const;
    void printInOrder(Node* n) const;
};

void BST::printInOrder(Node* n) const{
if(!n)
    return;
printInOrder(n->left);
cout << n->data << " ";
printInOrder(n->right);
}

void BST::printInOrder() const{
    printInOrder(root);
}

void BST::createSmallBST()
{
    root = new Node(50);
    root->right = new Node(100);
    root->left = new Node(20);
    root->left->left = new Node(7);
    root->left->right = new Node(25);
    root->left->left->right = new Node(8);

}

bool BST::find(int value) const
{
    return find(value, root);
}

bool BST::find(int value, Node *n) const
{
    if (n == nullptr)
        return false;

    if (value == n->data)
        return true;
    if (value < n->data)
        return find(value, n->left) ;
    else
        return find(value, n->right) ;
}


int main(){
    BST bst;
    bst.createSmallBST();
    bst.printInOrder();
    cout << boolalpha<<bst.find(744)<< endl;
}