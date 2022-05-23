#ifndef LIST_H
#define LIST_H
#include<iostream>
#include<exception>
#include<QApplication>
#include <assert.h>
#include "emploee.h"

struct Element{
public:
    Element(){};
    Element(const Employee &data,const int &nextIndex,const int &prevIndex):
        data(data),nextIndex(nextIndex),prevIndex(prevIndex){} ;

    Employee data;
    int nextIndex, prevIndex;

};


class List
{

public:
    ~List();
    List();
    List(const List&& rhs);

    void addInHead(const Employee &data);
    void addInTail(const Employee &data);

    void insert(const Employee &data,const int &index);
    void erase(const int &index);
    void clear();

    int length() const;
    Element& at(const int &index);
    void sort();

    List& operator=(List&& rhs);

private:

    int _size = 0;
    std::vector<Element> _array;
    int _tailIndex = 0, _headIndex = 0;
};


inline List::List() {
}


inline List::List(const List&& rhs) {
    _size = rhs._size;
    _array = rhs._array;
}


inline List::~List() {
}



inline int List::length() const{
    return _size;

}


inline void List::addInHead(const Employee &data) {

    _array.resize(++_size);

    Element tmp(data,_headIndex,_tailIndex);
    _array.at(_headIndex).prevIndex = _size - 1;

    _headIndex = _size - 1;

    _array.push_back(tmp);

}



inline void List::addInTail(const Employee &data) {

    Element tmp(data,_headIndex,_tailIndex);

    if(_size++ == 0){
        _array.push_back(tmp);
        qDebug() << _array.at(0).data.firstName;
        return;
    }
    _array.resize(_size);

    _array.at(_tailIndex).nextIndex = _size - 1;

    _tailIndex = _size - 1;

    qDebug() << _headIndex << " " << _tailIndex;
    _array.push_back(tmp);

}


inline void List::erase(const int& index) {
    int i;
    Element element;

    if(index < _size / 2){
        i = 0;
        element = _array[_headIndex];

        while(i != index){
            element = _array[element.nextIndex];
            i++;
        }
    }
    else{
        i = _size - 1;
        element = _array[_tailIndex];

        while(i != index){
            element = _array[element.prevIndex];
            i--;
        }
    }

    Element nextElem = _array[element.nextIndex];
    Element prevElem = _array[element.prevIndex];

    nextElem.prevIndex = element.prevIndex;
    prevElem.nextIndex = element.nextIndex;

}


inline Element& List::at(const int& index) {
    int i, currentIndex;

    if(index < _size / 2){
        i = 0;
        currentIndex = _headIndex;

        while(i != index){
            currentIndex = _array.at(currentIndex).nextIndex;
            i++;
        }
    }
    else{
        i = _size - 1;
        currentIndex = _tailIndex;

        while(i != index){
            currentIndex = _array.at(currentIndex).prevIndex;
            i--;
        }
    }

    return _array.at(currentIndex);

}

inline void List::sort()
{

}



inline List& List::operator=(List &&rhs){
    this->~List();

    Element tmp = rhs._array[_headIndex];

    for(int i = 0;i < _size; i++)
    {
        addInTail(tmp.data);
        tmp = rhs._array[tmp.nextIndex];
    }

    _size = rhs._size;

    return *this;
}


inline void List::clear(){
    _array.clear();
    _size = 0;
}

#endif // LIST_H
