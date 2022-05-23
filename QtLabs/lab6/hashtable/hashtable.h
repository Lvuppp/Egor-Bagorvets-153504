#ifndef HashTable_H
#define HashTable_H
#include<iostream>
#include<stack.h>
#include<QApplication>

template<class T>
struct Node{
    Node(T data, int key): data(data), key(key){};
    T data;
    int key;
};

using namespace std;

template<class T>
class HashTable
{
public:
    HashTable();
    ~HashTable();
    void insert(int key, T newData);
    void remove(int key);
    T search(int key);
private:
    void resize();
    void rehash();
    int hash(int key);

    int _count = 0;
    int _arrSize = 20;

    Stack<Node<T>>* _arr = new Stack<Node<T>>[20];
};


template<class T>
HashTable<T>::HashTable()
{
    for(int i = 0; i < _arrSize; i++){
        _arr[i] = Stack<Node<T>>();
    }
}

template<class T>
HashTable<T>::~HashTable()
{
    delete[] _arr;
}

template<class T>
void HashTable<T>::insert(int key, T newData)
{

    Stack<Node<T>>* record = &_arr[hash(key)];
    Stack<Node<T>> tmp;
    bool isFind = false;
    int sizeTmp = record->length();

    for(int i = 0; i < _arrSize; i++){
        qDebug() << _arr[i].length();
    }

    for(int i = 0; i < sizeTmp; i++){
        if(record->front().key == key){
            isFind = true;
            qDebug() << "Element find";
            break;
        }
        tmp.push(record->front());
        record->erase();
    }

    if(isFind){
        qDebug() << "Element find, change it";
        record->front().data = newData;
    }

    while(tmp.length()){
        record->push(tmp.front());
        tmp.erase();
    }

    if(!isFind){
        qDebug() << "Element no find, add";
        if(_count + 1 > _arrSize)
            resize();
        record->push(Node<T>(newData,key));
        _count++;
    }

}

template<class T>
void HashTable<T>::remove(int key)
{
    Stack<Node<T>>*record = &_arr[hash(key)];
    Stack<Node<T>> tmp;
    bool isFind = false;

    for(int i = 0; i < _arrSize; i++){
        if(record->front().key == key){
            isFind = true;
            qDebug() << "Element find";
            break;
        }
        tmp.push(record->front());
        record->erase();
    }

    if(isFind){
        qDebug() << "Element find, delete";
        record->erase();
    }

    while(tmp.length()){
        record->push(tmp.front());
        tmp.erase();
    }

}

template<class T>
T HashTable<T>::search(int key)
{
    Stack<Node<T>>* record = &_arr[hash(key)];
    Stack<Node<T>> tmp;
    T data;
    int sizeTmp = record->length();

    for(int i = 0; i < sizeTmp; i++){
        if(record->front().key == key){
            qDebug() << "Element find";
            data = record->front().data;
            break;
        }
        tmp.push(record->front());
        record->erase();
    }

    while(tmp.length()){
        record->push(tmp.front());
        tmp.erase();
    }

    return data;
}

template<class T>
void HashTable<T>::resize()
{
    int sizeTmp = _arrSize;
    _arrSize *= 2;
    Stack<Node<T>>* arrTmp = new Stack<Node<T>>[_arrSize];

    for(int i = 0; i< sizeTmp; i++){
        Stack<Node<T>>* record = &_arr[i];
        while(record->length()){
            int index = hash(record->front().key);
            arrTmp[index].push(Node<T>(record->front().data,record->front().key));
            record->erase();
        }
    }

    _arr = arrTmp;
}

template<class T>
int HashTable<T>::hash(int key)
{
    const double V = 0.618033;

    double temp = abs(key) * V;
    temp = temp - int(temp);
    return int(_arrSize * temp);
}



#endif // HashTable_H
