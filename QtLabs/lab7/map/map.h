#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <list>

using namespace std;

template <class T1, class T2>
struct Node {
    pair<T1, T2> p;
    Node* left;
    Node* right;
    Node* parent;
    int height;

    Node(pair<T1, T2> p) :left(nullptr), right(nullptr), parent(nullptr), height(0) {
        this->p.first = p.first;
        this->p.second = p.second;
    }
};

template <class T1, class T2>
class Map {
protected:


    Node<T1, T2>* root;

    list<Node<T1, T2>*> tree_list;

    void in_order(Node<T1, T2>* node) {
        if (node) {

            in_order(node->left);
            tree_list.push_back(node);
            in_order(node->right);
        }
    }

public:

    class Iterator {
    private:
        Node<T1, T2>* node;
        Node<T1, T2>* root;

    public:

        Iterator(Node<T1, T2>* root, Node<T1, T2>* node)
            : node(root), root(node) {

        }

        Iterator& operator=(const Iterator& other) {
            this->root = other.root;
            this->node = other.node;

            return *this;
        }

        pair<T1, T2>& operator*() {
            return node->p;
        }

        Iterator& operator++() {
            if (node == nullptr) {
                node = root;

                if (node == nullptr)
                    return *this;

                while (node->left != nullptr) {
                    node = node->left;
                }
            }
            else if (node->right != nullptr) {
                node = node->right;

                while (node->left != nullptr) {
                    node = node->left;
                }
            }
            else {
                Node<T1, T2>* p = node->parent;
                while (p != nullptr && node == p->right) {
                    node = p;
                    p = p->parent;
                }

                node = p;
            }
            return *this;
        }

        Iterator& operator--() {
            if (node == nullptr) {
                node = root;

                if (node == nullptr)
                    return *this;

                while (node->right != nullptr) {
                    node = node->right;
                }
            }
            else if (node->left != nullptr) {
                node = node->left;

                while (node->right != nullptr) {
                    node = node->right;
                }
            }
            else {
                Node<T1, T2>* p = node->parent;
                while (p != nullptr && node == p->left) {
                    node = p;
                    p = p->parent;
                }

                node = p;
            }
            return *this;
        }

        bool operator==(const Iterator& other) {
            return node == other.node;
        }

        bool operator!=(const Iterator& other) {
            return !(node == other.node);
        }
    };

    Iterator insertIt(pair<T1, T2> item) {
        Map<T1, T2>::insert(item);
        return Iterator(Map<T1, T2>::root);
    }

    Iterator erase(const T1& key) {
        Map<T1, T2>::remove(key);
        return Iterator(Map<T1, T2>::root);
    }

    Iterator begin() {
        Node<T1, T2>* node = Map<T1, T2>::root;

        while (node->left != nullptr) {
            node = node->left;
        }

        return Iterator(node, Map<T1, T2>::root);
    }

    Iterator end() {
        return Iterator(nullptr, Map<T1, T2>::root);
    }

    class IteratorList {

    private:
        list<Node<T1, T2>> tree_list;
        typename list<Node<T1, T2>*>::iterator it;


    public:

        IteratorList(const list<Node<T1, T2>>& other, bool begin) {
            tree_list = other;

            if (begin)
                it = tree_list.begin();
            else
                it = tree_list.end();
        }
        list<Node<T1,T2>> getList(){
            return tree_list;
        }
        pair<T1, T2> operator*() {
            return (*it)->p;
        }

        IteratorList& operator++() {
            ++it;
            return *this;
        }

        IteratorList& operator--() {
            --it;
            return *this;
        }

    };

    IteratorList lebgin() {
        tree_list.clear();
        in_order(Map<T1, T2>::root);
        return IteratorList(tree_list, true);
    }

    IteratorList lend() {
        tree_list.clear();
        in_order(Map<T1, T2>::root);
        return IteratorList(tree_list, false);

    }



    Map() : root(nullptr) {}

    Node<T1, T2>* getRoot() {
        return root;
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }

    void insert(pair<T1, T2> p) {
        if (root == nullptr) {
            root = new Node<T1, T2>(p);
            root->height = 0;
            root->parent = nullptr;
        }
        else {
            Node<T1, T2>* linker = getRoot();
            Node<T1, T2>* new_node = new Node<T1, T2>(p);

            while (linker != nullptr) {
                if (linker->p.first > p.first) {
                    if (linker->left == nullptr) {
                        linker->left = new_node;
                        new_node->height = 0;
                        new_node->parent = linker;

                        cout << "Element inserted.\n";
                        break;
                    }
                    else
                        linker = linker->left;
                }
                else {
                    if (linker->right == nullptr) {
                        linker->right = new_node;
                        new_node->height = 0;
                        new_node->parent = linker;

                        cout << "Element inserted.\n";
                        break;
                    }
                    else
                        linker = linker->right;
                }
            }
            rebalancer(new_node);
        }
    }

    void rebalancer(Node<T1, T2>* temp) {
        if (temp == root)
            treeFix(root);
        else {
            while (temp != nullptr) {
                heightBalance(temp);
                temp = temp->parent;
                if (temp)
                    treeFix(temp);
            }
        }
    }

    void treeFix(Node<T1, T2>* temp) {
        if (balanceFactor(temp) == 2) {
            if (balanceFactor(temp->right) < 0)
                rightRotate(temp->right);

            leftRotate(temp);
            heightBalance(temp);
        }
        else if (balanceFactor(temp) == -2) {
            if (balanceFactor(temp->left) > 0)
                leftRotate(temp->left);

            rightRotate(temp);
            heightBalance(temp);
        }
    }

    int balanceFactor(Node<T1, T2>* temp) {
        return (getHeight(temp->right) - getHeight(temp->left));
    }

    void heightBalance(Node<T1, T2>* temp) {
        int l = -1, r = -1;

        if (temp->left)
            l = temp->left->height;
        if (temp->right)
            r = temp->right->height;

        temp->height = max(l, r) + 1;
    }

    int getHeight(Node<T1, T2>* temp) {
        return ((temp == nullptr) ? -1 : temp->height);
    }

    void leftRotate(Node<T1, T2>* x) {
        pair<T1, T2> temp{0, 0};
        Node<T1, T2>* new_node = new Node<T1, T2>(temp);
        if (x->right->left)
            new_node->right = x->right->left;

        new_node->left = x->left;
        new_node->p.first = x->p.first;
        new_node->p.second = x->p.second;
        x->p.second = x->right->p.second;
        x->p.first = x->right->p.first;

        x->left = new_node;

        if (new_node->left)
            new_node->left->parent = new_node;
        if (new_node->right)
            new_node->right->parent = new_node;

        new_node->parent = x;

        if (x->right->right)
            x->right = x->right->right;
        else
            x->right = nullptr;

        if (x->right)
            x->right->parent = x;

        heightBalance(x->left);
        if (x->right) { heightBalance(x->right); }
        heightBalance(x);
    }

    void rightRotate(Node<T1, T2>* x) {
        pair<T1, T2> temp{0, 0};
        Node<T1, T2>* new_node = new Node<T1, T2>(temp);
        if (x->left->right)
            new_node->left = x->left->right;

        new_node->right = x->right;
        new_node->p.first = x->p.first;
        new_node->p.second = x->p.second;
        x->p.second = x->left->p.second;
        x->p.first = x->left->p.first;

        x->right = new_node;

        if (new_node->left)
            new_node->left->parent = new_node;

        if (new_node->right)
            new_node->right->parent = new_node;

        new_node->parent = x;

        if (x->left->left)
            x->left = x->left->left;
        else
            x->left = nullptr;

        if (x->left)
            x->left->parent = x;

        heightBalance(x->right);
        if (x->left) { heightBalance(x->left); }
        heightBalance(x);
    }

    Node<T1, T2>* treeSearch(T1 key) {
        Node<T1, T2>* temp = getRoot();
        if (temp == nullptr)
            return nullptr;

        while (temp) {
            if (key == temp->p.first)
                return temp;
            else if (key < temp->p.first)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return nullptr;
    }

    void preorderTraversal(Node<T1, T2>* temp) {
        if (temp == nullptr)
            return;

        cout << "->" << temp->p.first;
        preorderTraversal(temp->left);
        preorderTraversal(temp->right);
    }

    void postorderTraversal(Node<T1, T2>* temp) {
        if (temp == nullptr)
            return;

        postorderTraversal(temp->left);
        postorderTraversal(temp->right);
        cout << "->" << temp->p.first;
    }

    void removeNode(Node<T1, T2>* Parent, Node<T1, T2>* curr, T1 key) {
        if (curr == nullptr)
            return;

        if (curr->p.first == key) {

            if (curr->left == nullptr && curr->right == nullptr) {
                if (Parent->p.first == curr->p.first)
                    root = nullptr;
                else if (Parent->right == curr)
                    Parent->right = nullptr;
                else
                    Parent->left = nullptr;
                rebalancer(Parent);
            }

            else if (curr->left != nullptr && curr->right == nullptr) {
                T1 sp = curr->p.first;
                curr->p.first = curr->left->p.first;
                curr->left->p.first = sp;
                removeNode(curr, curr->left, key);
            }
            else if (curr->left == nullptr && curr->right != nullptr) {
                T1 sp = curr->p.first;
                curr->p.first = curr->right->p.first;
                curr->right->p.first = sp;
                removeNode(curr, curr->right, key);
            }

            else {
                Node<T1, T2>* temp = curr->right;
                int flag = 0;
                while (temp->left) {
                    flag = 1;
                    Parent = temp;
                    temp = temp->left;
                }
                if (!flag)
                    Parent = curr;

                T1 sp = curr->p.first;
                curr->p.first = temp->p.first;
                temp->p.first = sp;
                removeNode(Parent, temp, temp->p.first);
            }
        }
    }

    void remove(T1 key) {
        auto temp = root;
        auto Parent = temp;
        bool flag = false;

        if (temp == nullptr)
            removeNode(nullptr, nullptr, key);

        while (temp) {
            if (key == temp->p.first) {
                flag = true;
                removeNode(Parent, temp, key);
                break;
            }
            else if (key < temp->p.first) {
                Parent = temp;
                temp = temp->left;
            }
            else {
                Parent = temp;
                temp = temp->right;
            }
        }

        if (!flag)
             cout << "Element doesn't exist in the table\n";
        else
            cout << "Element removed.\n";
    }

    int& operator[](int key) {
        if (treeSearch(key))
            return treeSearch(key)->p.second;
        else
            throw "no matches!";
    }

};




#endif // MAP_H
