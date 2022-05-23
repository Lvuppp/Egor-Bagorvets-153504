#ifndef STACK_H
#define STACK_H
template<class T>
class Stack{
private:

    class Node{
    public:
        Node(T data):data(data){};

        Node *prev = nullptr;
        T data;
    };

public:
    Stack(){};
    ~Stack(){
        while(_size-- > 0)
            this->erase();
    };

    void push(T data);
    T& front();
    int length(){return _size;};
    void erase();
private:
    int _size = 0;
    Node *_head = nullptr;
};

template<class T>
inline void Stack<T>::push(T data)
{
    if(_size == 0){
        _head = new Node(data);
        _size++;

        return;
    }

    auto tmp = _head;
    _head = new Node(data);
    _head->prev = tmp;

    _size++;

}

template<class T>
T& Stack<T>::front()
{
    return _head->data;
}

template<class T>
inline void Stack<T>::erase()
{
    if(_head == nullptr)
        return;
    if(_head->prev == nullptr){
        delete _head;
        _size--;
        return;
    }
    Node* tmp = _head->prev;

    delete _head;
    _head = tmp;

    --_size;
}


#endif // STACK_H
