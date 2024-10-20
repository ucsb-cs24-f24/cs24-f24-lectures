#include <iostream>
using namespace std;

class BST
{
public:
    BST() { root = nullptr; }
    ~BST() { clear(root); }
    void printInOrder() const;
    void createSmallBST();
    int getHeight(int value) const;
    int sum() const;
    bool insert(int value);

    int getHeight() const;
    bool find(int value) const;

private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        Node(int value)
        {
            left = nullptr;
            right = nullptr;
            data = value;
        };
    };

    Node *root;
    int getHeigh(Node *n, int value) const;
    void printInOrder(Node *n) const;
    int sum(Node *n) const;
    bool insert(Node *n, int value);
    void clear(Node *n);
    int getHeight(Node *n) const;
    bool find(int value, Node *n) const;
};

bool BST::insert(int value)
{
    if (!root)
    {
        root = new Node(value);
        return true;
    }

    return insert(root, value);
}

bool BST::insert(Node *n, int value)
{

    if (value < n->data)
    {
        if (!n->left)
        {
            n->left = new Node(value);
            return true;
        }
        else
        {
            return insert(n->left, value);
        }
    }

    else
    {
        if (!n->right)
        {
            n->right = new Node(value);
            return true;
        }
        else
        {
            return insert(n->right, value);
        }
    }
    return false;
}

int BST::sum(Node *n) const
{
    if (!n)
        return 0;

    return sum(n->left) + n->data + sum(n->right);
}

int BST::sum() const
{
    return sum(root);
}

int BST::getHeight(Node *n) const
{
    if (!n)
        return -1;

    return max(getHeight(n->left), getHeight(n->right)) + 1;
}

int BST::getHeight() const
{
    return getHeight(root);
}

void BST::printInOrder(Node *n) const
{
    if (!n)
        return;
    printInOrder(n->left);
    cout << n->data << " ";
    printInOrder(n->right);
}

void BST::printInOrder() const
{
    printInOrder(root);
}

void BST::clear(Node *n)
{
    if (!n)
        return;
    clear(n->left);
    clear(n->right);
    delete n;
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

    return find(value, n->left) || find(value, n->right);
}

int main()
{
    BST bst;
    bst.createSmallBST();
    bst.printInOrder();
    cout << boolalpha << bst.find(7) << endl;
}