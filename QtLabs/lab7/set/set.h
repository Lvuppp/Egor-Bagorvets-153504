#ifndef SET_H
#define SET_H


#include <iostream>
#include <list>
using namespace std;

template <class T2>
struct Node {
    T2 p;
    Node* left;
    Node* right;
    Node* parent;
    int height;

    Node(T2 p) :left(nullptr), right(nullptr), parent(nullptr), height(0) {
        p = p;
    }
};

template <class T2>
class Set {
protected:


    Node<T2>* root;

    list<Node<T2>*> tree_list;

    void in_order(Node<T2>* node) {
        if (node) {

            in_order(node->left);
            tree_list.push_back(node);
            in_order(node->right);
        }
    }

public:

    class Iterator {
    private:
        Node<T2>* node;
        Node<T2>* root;

    public:

        Iterator(Node<T2>* root, Node<T2>* node)
            : node(root), root(node) {

        }

        Iterator& operator=(const Iterator& other) {
            this->root = other.root;
            this->node = other.node;

            return *this;
        }

        T2& operator*() {
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
                Node<T2>* p = node->parent;
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
                Node<T2>* p = node->parent;
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

    Iterator insert(T2 item) {
        Set<T2>::InsertNode(item);
        return Iterator(Set<T2>::root);
    }

    Iterator erase(const T2& key) {
        Set<T2>::Remove(key);
        return Iterator(Set<T2>::root);
    }

    Iterator begin() {
        Node<T2>* node = Set<T2>::root;

        while (node->left != nullptr) {
            node = node->left;
        }

        return Iterator(node, Set<T2>::root);
    }

    Iterator end() {
        return Iterator(nullptr, Set<T2>::root);
    }




    class IteratorList {
    private:
        list<Node<T2>> tree_list;
        typename list<Node<T2>*>::iterator it;


    public:

        IteratorList(const list<Node<T2>>& other, bool begin) {
            tree_list = other;

            if (begin)
                it = tree_list.begin();
            else
                it = tree_list.end();
        }
        list<Node<T2>> getList(){
            return tree_list;
        }
        T2 operator*() {
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
        in_order(Set<T2>::root);
        return IteratorList(tree_list, true);
    }

    IteratorList lend() {
        tree_list.clear();
        in_order(Set<T2>::root);
        return IteratorList(tree_list, false);

    }



    Set() : root(nullptr) {}

    Node< T2>* getRoot() {
        return root;
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }

    void InsertNode(T2 p) {
        if (root == nullptr) {
            root = new Node< T2>(p);
            root->height = 0;
            root->parent = nullptr;
        }
        else {
            Node< T2>* linker = getRoot();
            Node< T2>* new_node = new Node< T2>(p);

            while (linker != nullptr) {
                if (linker->p > p) {
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
            Rebalancer(new_node);
        }
    }

    void Rebalancer(Node< T2>* temp) {
        if (temp == root)
            TreeFix(root);
        else {
            while (temp != nullptr) {
                HeightBalance(temp);
                temp = temp->parent;
                if (temp)
                    TreeFix(temp);
            }
        }
    }

    void TreeFix(Node< T2>* temp) {
        if (BalanceFactor(temp) == 2) {
            if (BalanceFactor(temp->right) < 0)
                RightRotate(temp->right);

            LeftRotate(temp);
            HeightBalance(temp);
        }
        else if (BalanceFactor(temp) == -2) {
            if (BalanceFactor(temp->left) > 0)
                LeftRotate(temp->left);

            RightRotate(temp);
            HeightBalance(temp);
        }
    }

    int BalanceFactor(Node< T2>* temp) {
        return (GetHeight(temp->right) - GetHeight(temp->left));
    }

    void HeightBalance(Node<T2>* temp) {
        int l = -1, r = -1;

        if (temp->left)
            l = temp->left->height;
        if (temp->right)
            r = temp->right->height;

        temp->height = max(l, r) + 1;
    }

    int GetHeight(Node< T2>* temp) {
        return ((temp == nullptr) ? -1 : temp->height);
    }

    void LeftRotate(Node< T2>* x) {
        T2 temp=0;
        Node<T2>* new_node = new Node<T2>(temp);
        if (x->right->left)
            new_node->right = x->right->left;

        new_node->left = x->left;
        new_node->p = x->p;
        x->p = x->right->p;

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

        HeightBalance(x->left);
        if (x->right) { HeightBalance(x->right); }
        HeightBalance(x);
    }

    void RightRotate(Node< T2>* x) {
        T2 temp= 0;
        Node< T2>* new_node = new Node< T2>(temp);
        if (x->left->right)
            new_node->left = x->left->right;

        new_node->right = x->right;
        new_node->p = x->p;
        x->p = x->left->p;

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

        HeightBalance(x->right);
        if (x->left) { HeightBalance(x->left); }
        HeightBalance(x);
    }

    Node< T2>* TreeSearch(T2 key) {
        Node<T2>* temp = getRoot();
        if (temp == nullptr)
            return nullptr;

        while (temp) {
            if (key == temp->p)
                return temp;
            else if (key < temp->p)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return nullptr;
    }

    void PreorderTraversal(Node<T2>* temp) {
        if (temp == nullptr)
            return;

        cout << "->" << temp->p;
        PreorderTraversal(temp->left);
        PreorderTraversal(temp->right);
    }

    void PostorderTraversal(Node< T2>* temp) {
        if (temp == nullptr)
            return;

        PostorderTraversal(temp->left);
        PostorderTraversal(temp->right);
        cout << "->" << temp->p.first;
    }

    void RemoveNode(Node< T2>* Parent, Node< T2>* curr) {
        if (curr == nullptr)
            return;

        if (curr->p == curr->p) {

            if (curr->left == nullptr && curr->right == nullptr) {
                if (Parent->p == curr->p)
                    root = nullptr;
                else if (Parent->right == curr)
                    Parent->right = nullptr;
                else
                    Parent->left = nullptr;
                Rebalancer(Parent);
            }

            else if (curr->left != nullptr && curr->right == nullptr) {
                T2 sp = curr->p;
                curr->p = curr->left->p;
                curr->left->p = sp;
                RemoveNode(curr, curr->left);
            }
            else if (curr->left == nullptr && curr->right != nullptr) {
                T2 sp = curr->p;
                curr->p = curr->right->p;
                curr->right->p = sp;
                RemoveNode(curr, curr->right);
            }

            else {
                Node< T2>* temp = curr->right;
                int flag = 0;
                while (temp->left) {
                    flag = 1;
                    Parent = temp;
                    temp = temp->left;
                }
                if (!flag)
                    Parent = curr;

                T2 sp = curr->p;
                curr->p = temp->p;
                temp->p = sp;
                RemoveNode(Parent, temp);
            }
        }
    }

    void Remove(T2 key) {
        auto temp = root;
        auto Parent = temp;
        bool flag = false;

        if (temp == nullptr)
            RemoveNode(nullptr, nullptr);

        while (temp) {
            if (key == temp->p) {
                flag = true;
                RemoveNode(Parent, temp);
                break;
            }
            else if (key < temp->p) {
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
        if (TreeSearch(key))
            return TreeSearch(key)->p;
        else
            throw "no matches!";
    }

};

#endif // SET_H
