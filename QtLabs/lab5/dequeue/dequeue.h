#ifndef DEdequeue_H
#define DEdequeue_H
#include<iostream>
#include<memory>
#include<QApplication>
template<class T>
class node{
public:
    node(){};
    ~node(){
        delete prev;
        delete next;
        delete []data;
    }
    std::size_t count = 0;
    node<T> *prev = nullptr;
    node<T> *next = nullptr;
    T *data = new T[4];
};


template<class T>
class dequeue
{
public:
    dequeue();
    ~dequeue(){};
    T &back();
    T &front();
    void push_back(const T &addItem);
    void push_front(const T &addItem);
    void pop_back();
    void pop_front();
    bool empty();
    std::size_t size();
    void print();

private:
    node<T> *_front;
    node<T> *_back;
    size_t _capacity = 0;
    size_t _size = 0;
};

template<class T>
dequeue<T>::dequeue(){

}

template<class T>
T &dequeue<T>::back()
{
    return _back->data[_back->count - 1];
}


template<class T>
T &dequeue<T>::front()
{
    return _front->data[0];
}

template<class T>
void dequeue<T>::push_back(const T &addItem){
   if(_capacity == 0){
       _front = new node<T>;
       _back = _front;
       _back->data[0] = addItem;
       _back->count++;
       ++_capacity;
   }
   else{
       if(_back->count < 4){
           _back->data[_back->count] = addItem;
           _back->count++;
       }
       else{
            _back->prev = new node<T>;
            _back->prev->next = _back;
            _back = _back->prev;
            _back->data[_back->count] = addItem;
            _back->count++;
            ++_capacity;
       }
   }

   ++_size;
}

template<class T>
void dequeue<T>::push_front(const T & addItem){
    if(_capacity == 0){
        _back = _front = std::make_shared<node<T>>();
        _front->data[0] = addItem;
        _front->count++;
        _front->prev = _back;
        ++_capacity;
    }
    else{
        if(_front->count < 4){
            for(auto i = 0; i < _front->count; i++){
                auto tmp = _front->data[i + 1];
                _front->data[i + 1] = _front->data[i];
            }
            _front->data[0] = addItem;
            _front->count++;

        }
        else{
             _front->next = new node<T>;
             _front->next->prev = _front;
             _front = _front->next;
             _front->data[0] = addItem;
             _front->count++;
             ++_capacity;
        }
    }

    ++_size;
}


template<class T>
void dequeue<T>::pop_back()
{
    try {
        if(_back->count == 1){
            auto tmp = _back;
            _back = _back->next;
            delete tmp;
            --_capacity;
        }
        else{
            _back->data[_back->count--] = 0;
        }
    }  catch (const std::exception & ex) {
        ex.what();
    }
}

template<class T>
void dequeue<T>::pop_front()
{
    try {
        if(_front->count <= 1){
            node<T> * tmp = _front;
            _front = _front->prev;
            delete tmp;
            --_capacity;
        }
        else{
            _front->data[0] = rand();
            for(auto i = 1; i < _front->count; i++){
                _front->data[i - 1] = _front->data[i];
            }
        }
    }  catch (const std::exception & ex) {
        ex.what();
    }
}


template<class T>
bool dequeue<T>::empty()
{
    return !_size;
}

template<class T>
std::size_t dequeue<T>::size()
{
    return _size;
}

template<class T>
void dequeue<T>::print()
{
    node<T>* tmp = _front;
    for(auto i = 0; i < _capacity;i++){
        for(auto j = 0;j < 4;j++){
            qDebug() << tmp->data[j];
        }
        tmp = tmp->prev;
    }
    qDebug() << "";
}


#endif //DEdequeue_H
