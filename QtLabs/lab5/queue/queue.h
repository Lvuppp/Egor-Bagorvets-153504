#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include<memory>
template<class T>
class node{
public:
    node(T* data) : data(data){};
    ~node(){
        delete prev;
        delete next;
        delete data;
    }
    node<T> *prev = nullptr;
    node<T> *next = nullptr;
    T *data = nullptr;
};


template<class T>
class queue
{
public:
    queue();
    ~queue(){};
    T &back();
    T &front();
    void push(const T &addItem );
    void pop();
    bool empty();
    std::size_t size();

private:
    std::unique_ptr<node<T>> _front;
    std::unique_ptr<node<T>> _back;
    size_t _size = 0;
};

template<class T>
queue<T>::queue(){

}

template<class T>
T &queue<T>::back()
{
    return *_back->data;
}


template<class T>
T &queue<T>::front()
{
    return *_front->data;
}

template<class T>
void queue<T>::push(const T & addItem)
{
    if(_size == 0){
        _front = _back = new node<T>(new T(addItem));
    }
    else{
        _back->prev = new node<T>(new T(addItem));
        _back->prev->next = _back;
        _back = _back->prev;
    }

    ++_size;
}

template<class T>
void queue<T>::pop()
{
    try {
        auto tmp = _front;
        _front = _front->prev;
        --_size;
    }  catch (const std::exception & ex) {
        ex.what();
    }
}

template<class T>
bool queue<T>::empty()
{
    return !_size;
}

template<class T>
std::size_t queue<T>::size()
{
    return _size;
}



#endif // QUEUE_H
