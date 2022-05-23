#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>

using namespace std;

template <class T>
struct node {
    T data{};
    node* left = nullptr;
    node* right = nullptr;
    node* parent = nullptr;
    int height;

    T getData(node<T> info){
        return info.data;
    }
};

template <class T>
class Tree{

private:
    node<T>* root;

public:
    Tree() : root(nullptr) {}

    node<T>* getNode() {
        return root;
    }

    int max(int a, int b) {
        return (a > b ? a : b);
    }

    void getPregnant(node<T>* tmp, int &haveKids) {
        if(tmp == nullptr){
            return;
        }

        if(tmp->left!=nullptr && tmp->right!=nullptr){
            haveKids++;
        }

        getPregnant(tmp->left, haveKids);
        getPregnant(tmp->right, haveKids);
    }

    void insert(T stuff) {
        if(root == nullptr){
            root = new node<T>();
            root->data = stuff;
            cout << "Element inserted.\n";
            root-> height = 0;
            root->parent = nullptr;
        }
        else {
            auto linker = getNode();
            node<T>* newnode = new node<T>();
            newnode->data = stuff;

            while(linker != nullptr){
                if(linker->data > stuff){

                    if(linker->left == nullptr){

                        linker->left = newnode;
                        newnode->height = 0;
                        newnode->parent = linker;
                        cout << "Element inserted.\n"; break;
                    }

                    else {

                        linker = linker->left;

                    }
                }

                else {
                    if(linker->right == nullptr){

                        linker->right = newnode;
                        newnode->height = 0;
                        newnode->parent = linker;
                        cout << "Element inserted.\n"; break;
                    }
                    else {
                        linker = linker->right;
                    }
                }
            }
            rebalancer(newnode);
        }
    }

    int height(node<T>* tmp) {
        return ((tmp == nullptr) ? -1 : tmp->height);
    }

    int bFactor(node<T>* tmp) {
        return (height(tmp->right) - height(tmp->left));
    }


    void highBalance(node<T>* tmp) {
        int l = -1, r = -1  ;

        if(tmp->left){
            l = tmp->left->height;
        }

        if(tmp->right){
            r = tmp->right->height;
        }

        tmp->height = max(l, r) + 1;
    }

    void fix(node<T>* tmp) {
        if(bFactor(tmp) == 2){
            if(bFactor(tmp->right) < 0){
                rightRotate(tmp->right);
            }

            leftRotate(tmp);
            highBalance(tmp);
        }
        else if(bFactor(tmp) == -2){
            if(bFactor(tmp->left) > 0){
                leftRotate(tmp->left);
            }
            rightRotate(tmp);
            highBalance(tmp);
        }
    }

    void rebalancer(node<T>* tmp) {
        if(tmp == root){
            fix(root);
        }

        else {

            while(tmp != nullptr){

                highBalance(tmp);
                tmp = tmp->parent;

                if(tmp) {
                    fix(tmp);
                }
            }
        }
    }

    void leftRotate(node<T>* x) {
        node<T>* newNode = new node<T>();

        if(x->right->left) {
            newNode->right = x->right->left;
        }

        newNode->left = x->left;
        newNode->data = x->data;
        x->data = x->right->data;

        x->left = newNode;
        if(newNode->left){
            newNode->left->parent = newNode;
        }
        if(newNode->right){
            newNode->right->parent = newNode;
        }
        newNode->parent = x;

        if(
            x->right->right){ x->right = x->right->right;
        }
        else {
            x->right = nullptr;
        }

        if(x->right){ x->right->parent = x; }

        highBalance(x->left);
        if(x->right){
            highBalance(x->right);
        }
        highBalance(x);
    }

    void rightRotate(node<T>* x) {
        node<T>* newNode = new node<T>();

        if(x->left->right){
            newNode->left = x->left->right;
        }

        newNode->right = x->right;
        newNode->data = x->data;

        x->data = x->left->data;

        x->right = newNode;

        if(newNode->left){
            newNode->left->parent = newNode;
        }
        if(newNode->right){
            newNode->right->parent = newNode;
        }
        newNode->parent = x;

        if(x->left->left){
            x->left = x->left->left;
        }
        else {
            x->left = nullptr;
        }

        if(x->left){
            x->left->parent = x;
        }

        highBalance(x->right);
        if(x->left){
            highBalance(x->left);
        }
        highBalance(x);
    }

    node<T>* search(T stuff) {
        auto tmp = getNode();

        if(tmp == nullptr) {
            return nullptr;
        }

        while(tmp) {
            if(stuff == tmp->data){
                return tmp;
            }
            else if(stuff < tmp->data){
                tmp = tmp->left;
            }
            else {
                tmp = tmp->right;
            }
        }
        return nullptr;
    }

    void preorderTraversal(node<T>* tmp, vector<T> &contain) {
        if(tmp == nullptr){
            return;
        }

        contain.push_back(tmp->data);

        preorderTraversal(tmp->left, contain);
        preorderTraversal(tmp->right, contain);
    }

    void postorderTraversal(node<T> *tmp,vector<T> &contain ) {
        if(tmp == nullptr){
            return;
        }

        postorderTraversal(tmp->left,contain);
        postorderTraversal(tmp->right,contain);
        contain.push_back(tmp->data);
    }

    void removeNode(node<T>* Parent, node<T>* curr, T stuff) {
        if(curr == nullptr) {
            return;
        }
        if(curr->data == stuff) {

            if(curr->left == nullptr && curr->right == nullptr){
                if(Parent->data == curr->data){
                    root = nullptr;
                }
                else if(Parent->right == curr){
                    Parent->right = nullptr;
                }
                else {
                    Parent->left = nullptr;
                }
                rebalancer(Parent);
            }

            else if(curr->left != nullptr && curr->right == nullptr) {
                T sp = curr->data;
                curr->data = curr->left->data;
                curr->left->data = sp;
                removeNode(curr, curr->left, stuff);
            }

            else if(curr->left == nullptr && curr->right != nullptr) {
                T sp = curr->data;
                curr->data = curr->right->data;
                curr->right->data = sp;
                removeNode(curr, curr->right, stuff);
            }

            else {
                node<T>* tmp = curr->right;
                int flag = 0;

                while(tmp->left){
                    flag = 1; Parent = tmp; tmp = tmp->left;
                }
                if(!flag){
                    Parent = curr;
                }
                T sp = curr->data;

                curr->data = tmp->data;
                tmp->data = sp;

                removeNode(Parent, tmp, tmp->data);
            }
        }
    }

    void remove(T stuff){
        auto tmp = root;
        auto Parent = tmp;
        bool flag = false;
        if(tmp == nullptr){
            removeNode(nullptr, nullptr, stuff);
        }

        while(tmp) {
            if(stuff == tmp->data){
                flag = true;
                removeNode(Parent, tmp, stuff);
                break;
            }
            else if(stuff < tmp->data){
                Parent = tmp ;
                tmp = tmp->left;
            }
            else { Parent = tmp ; tmp = tmp->right; }
        }

    }
};


#endif // NODE_H
