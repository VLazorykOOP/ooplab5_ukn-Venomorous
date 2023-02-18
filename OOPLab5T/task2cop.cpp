// Using class hierarchy and composition, create a binary tree. A binary tree has a root node. We can insert a node. We can traverse first the left subtree, then the right (sequential traversal) and the reverse bypass. A node can be placed in a binary search tree only as a end node. If the tree is empty, a new instance of the class is created a node of a tree and a node contained in a tree. If the tree is not empty, then the program compares what is inserted into the value tree with the value at the root node and if less, it places the subtrees on the left, and if more, then on the right. If the values are equal, then a message is displayed that the repeat is not inserted.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Node
{
private:
    int value;
    Node *left;
    Node *right;

public:
    Node(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
    }
    Node(const Node &node)
    {
        this->value = node.value;
        this->left = node.left;
        this->right = node.right;
    }
    int getValue()
    {
        return value;
    }
    void setValue(int value)
    {
        this->value = value;
    }
    Node *getLeft()
    {
        return left;
    }
    void setLeft(Node *left)
    {
        this->left = left;
    }
    Node *getRight()
    {
        return right;
    }
    void setRight(Node *right)
    {
        this->right = right;
    }
    void print()
    {
        cout << "Value: " << value << endl;
    }
    ~Node()
    {
        cout << "Node destructor" << endl;
    }
};

class Tree
{
private:
    Node *root;

public:
    Tree()
    {
        root = NULL;
    }
    Tree(const Tree &tree)
    {
        this->root = tree.root;
    }
    Node *getRoot()
    {
        return root;
    }
    void setRoot(Node *root)
    {
        this->root = root;
    }
    void insert(int value)
    {
        Node *node = new Node(value);
        if (root == NULL)
        {
            root = node;
        }
        else
        {
            Node *current = root;
            Node *parent = NULL;
            while (true)
            {
                parent = current;
                if (value < current->getValue())
                {
                    current = current->getLeft();
                    if (current == NULL)
                    {
                        parent->setLeft(node);
                        return;
                    }
                }
                else
                {
                    current = current->getRight();
                    if (current == NULL)
                    {
                        parent->setRight(node);
                        return;
                    }
                }
            }
        }
    }
    void print(Node *node)
    {
        if (node != NULL)
        {
            print(node->getLeft());
            node->print();
            print(node->getRight());
        }
    }
    void print()
    {
        print(root);
    }
    void printReverse(Node *node)
    {
        if (node != NULL)
        {
            printReverse(node->getRight());
            node->print();
            printReverse(node->getLeft());
        }
    }
    void printReverse()
    {
        printReverse(root);
    }
    ~Tree()
    {
        cout << "Tree destructor" << endl;
    }
};

int main()
{
    Tree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.print();
    cout << endl;
    tree.printReverse();
    return 0;
}
