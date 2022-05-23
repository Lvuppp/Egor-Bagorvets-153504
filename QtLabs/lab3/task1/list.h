#ifndef LIST_H
#define LIST_H
#include"QApplication"
#include<iostream>

template<typename T>
class Element{

public:
    std::size_t index;
    T data;

    Element *nextPtr;
    Element *prevPtr;

    ~Element(){
    }
};

template<typename T>
class List
{
public:
    List();
    List(const List&& rightValue);

    void addInHead(const T &data);
    void addInTail(const T &data);

    void insert(const T &data,const int &index);
    void clear();
    void erase(const std::size_t &index);
    std::size_t length() const;
    T& at(const std::size_t &index) const;
    void print();
    void swap(std::size_t firstIndex, std::size_t secondIndex);

    bool operator == (const List& rhs) const;
    bool operator != (const List& rhs) const;
    bool operator >= (const List& rhs) const;
    bool operator <= (const List& rhs) const;
    bool operator > (const List& rhs) const;
    bool operator < (const List& rhs) const;
    List<T>& operator=(const List<T> &rhs);

private:
    std::size_t _size;
    Element<T> *_headElem, *_tailElem;
};


template<typename T>
inline List<T>::List() {
    _size = 0;
    _headElem = _tailElem = nullptr;
}


template<typename T>
inline List<T>::List(const List&& rvs) {

    Element<T>* temp = new Element<T>();

    for(int i = 0; i < rvs._size + 1; i++){
        addInTail(temp->data);
        temp = temp->nextPtr;
    }

}

template<typename T>
inline void List<T>::addInHead(const T &data){
    Element<T> *temp = new Element<T>();

    temp->prevPtr = nullptr;
    temp->data = data;
    temp->nextPtr = _headElem;

    if(_headElem != nullptr)
        _headElem->prevPtr = temp;

    if(_size == 0)
        _headElem = _tailElem = temp;
    else
        _headElem = temp;

    _size++;
}

template<typename T>
inline void List<T>::addInTail(const T &data){
    Element<T>* temp = new Element<T>();

    temp->nextPtr = nullptr;
    temp->data = data;
    temp->prevPtr = _tailElem;

    if(_tailElem != nullptr)
        _tailElem->nextPtr = temp;

    if(_size == 0)
        _headElem = _tailElem = temp;
    else
        _tailElem = temp;

    _size++;
}


template<typename T>
inline void List<T>::insert(const T &data,const int &index)
{
    if(index < 1 || index > _size + 1)
        return;

    if(index == _size){
        addInTail(data);
    }
    else if(index == 0){
        addInHead(data);
    }
    else{
        int i;
        Element<T> *insertElem;

        if(index < _size / 2){
            i = 0;
            insertElem = _headElem;

            while(i != index){
                insertElem = insertElem->nextPtr();
                i++;
            }
        }
        else{
            i = _size - 1;
            insertElem = _tailElem;

            while(i != index){
                insertElem = insertElem->prevPtr();
                i--;
            }
        }

        insertElem->prevPtr->nextPtr = new Element<T>();
        insertElem->prevPtr = insertElem->prevPtr->nextPtr;

        insertElem->prevPtr->nextPtr = insertElem;
        insertElem->prevPtr->data = data;
        insertElem->prevPtr->prevPrt = insertElem->prevPtr;

    }

    _size++;
}

template<typename T>
inline void List<T>::List::erase(const std::size_t &index)
{
    if( index > _size - 1)
        return;

    if(index == _size - 1){
        auto tmp = _tailElem->prevPtr;

        delete _tailElem;

        _tailElem = tmp;

    }
    else if(index == 0){
        auto tmp = _headElem->nextPtr;

        delete _headElem;

        _headElem = tmp;
    }
    else{
        std::size_t i;
        Element<T> *eraseElem;

        if(index < _size / 2){
            i = 0;
            eraseElem = _headElem;

            while(i != index){
                eraseElem = eraseElem->nextPtr;
                i++;
            }
        }
        else{
            i = _size - 1;
            eraseElem = _tailElem;

            while(i != index){
                eraseElem = eraseElem->prevPtr;
                i--;
            }
        }

        eraseElem->prevPtr->nextPtr = eraseElem->nextPtr;
        eraseElem->nextPtr->prevPtr = eraseElem->prevPtr;
        delete eraseElem;
    }

    _size--;
}

template<typename T>
inline void List<T>::clear()
{
    while(_size != 0){
        this->erase(0);
    }
}

template<typename T>
inline std::size_t List<T>::length() const
{
    return _size;
}

template<typename T>
inline T& List<T>::at(const std::size_t &index) const
{
    std::size_t i;
    Element<T> *element;

    if(index == 0)
        return _headElem->data;

    if(index == _size - 1)
        return _tailElem->data;


    if(index < _size / 2){
        i = 0;
        element = _headElem;

        while(i != index){
            element = element->nextPtr;
            i++;
        }
    }
    else{
        i = _size - 1;
        element = _tailElem;

        while(i != index){
            element = element->prevPtr;
            i--;
        }
    }

    return element->data;

}
template<typename T>
inline void List<T>::swap(std::size_t firstIndex, std::size_t secondIndex)
{
    std::size_t i;
    Element<T> *firstElement, *secondElement;

    if(firstIndex == 0)
        firstElement = _headElem;

    if(firstIndex == _size - 1)
        firstElement = _tailElem;


    if(firstIndex < _size / 2){
        i = 0;
        firstElement = _headElem;

        while(i != firstIndex){
            firstElement = firstElement->nextPtr;
            i++;
        }
    }
    else{
        i = _size - 1;
        firstElement = _tailElem;

        while(i != firstIndex){
            firstElement = firstElement->prevPtr;
            i--;
        }
    }

    if(secondIndex == 0)
        secondElement = _headElem;

    if(secondIndex == _size - 1)
        secondElement =  _tailElem;


    if(secondIndex < _size / 2){
        i = 0;
        secondElement = _headElem;

        while(i != secondIndex){
            secondElement = firstElement->nextPtr;
            i++;
        }
    }
    else{
        i = _size - 1;
        secondElement = _tailElem;

        while(i != secondIndex){
            secondElement = secondElement->prevPtr;
            i--;
        }
    }

    qSwap(firstElement->data,secondElement->data);
}

template<typename T>
inline List<T>& List<T>::operator=(const List<T> &rhs)
{
    if(this == &rhs)
        return *this;

    this->~List();

    Element<T> *tmp = rhs._headElem;

    while(tmp != 0)
    {
        this->addInTail(tmp->data);
        tmp = tmp->nextPtr;
    }

    _size = rhs._size;

    return *this;
}

template<typename T>
inline bool List<T>::operator == (const List& rhs)const
{
    if(_size != rhs._size)
        return false;

    Element<T> *firstTmp , *secondTmp;

    firstTmp = _headElem;
    secondTmp = rhs._headElem;

    while(firstTmp != 0)
    {
        if(firstTmp->data != secondTmp->data)
            return false;

        firstTmp = firstTmp->nextPtr;
        secondTmp = secondTmp->nextPtr;
    }

    return true;
}

//template<typename T>
//inline void List<T>::print()
//{
//    Element<T> *tmp = _headElem;
//    for(int i = 0; i < _size + 1; i++){
//        qDebug() << tmp->data;
//        tmp = tmp->nextPtr;
//    }
//}


template<typename T>
inline bool List<T>::operator != (const List<T> &rhs)const
{
    return !(*this == rhs);
}

template<typename T>
inline bool List<T>::operator >= (const List<T> &rhs)const
{
    if(_size >= rhs._size)
        return true;
    if(*this == rhs)
        return true;

    return false;
}

template<typename T>
inline bool List<T>::operator <= (const List<T> &rhs)const
{
    if(_size < rhs._size)
        return true;
    if(*this == rhs)
        return true;

    return false;
}

template<typename T>
inline bool List<T>::operator > (const List<T> &rhs)const
{
    if(_size > rhs._size)
        return true;

    return false;
}

template<typename T>
inline bool List<T>::operator < (const List<T> &rhs)const
{
    if(_size < rhs._size)
        return true;

    return false;
}

#endif
