// Використовуючи ієрархію й композицію класів, створити бінарне дерево. У бінарного дерева є кореневий вузол. Ми можемо вставляти вузол. Ми можемо обходити спочатку ліве під-дерево, потім праве (послідовний обхід) і зворотний обхід. Вузол може бути поміщений у дерево двійкового пошуку тільки в якості кінцевого вузла. Якщо дерево є порожнім, то створюється новий екземпляр класу вузол дерева й вузол міститься в дерево. Якщо дерево не є порожнім, то програма порівнює, що вставляється в дерево значення зі значенням у кореневому вузлі і якщо менше, те поміщає в ліві під-дерева, а якщо більше, те в праві. Якщо значення рівні, то виводиться повідомлення, що повтор і не вставляється.

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
        else if (root->getValue() == value)
        {
            cout << "Value " << value << " already exists" << endl;
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
    tree.insert(5);
    tree.insert(8);
    tree.print();
    cout << endl;
    tree.printReverse();
    return 0;
}
