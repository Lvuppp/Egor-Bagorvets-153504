#ifndef WEAK_PTR_H
#define WEAK_PTR_H

#include<iostream>
#include"shared_ptr.h"
template <typename T>
class WeakPtr
{

public:
    constexpr WeakPtr(){};
    WeakPtr(const SharePtr<T> &ptr) : _cntrlBlock(ptr._cntrlBlock){++*_cntrlBlock->weakCount;};
    WeakPtr(const WeakPtr<T> &ptr) : _cntrlBlock(ptr._cntrlBlock){++*_cntrlBlock->weakCount;};

    ~WeakPtr() noexcept{
        --*_cntrlBlock->weakCount;
        if(*_cntrlBlock->weakCount == 0 && *_cntrlBlock->shareCount == 0)
        {
            qDebug() << "Last WeakPtr and all block is delete";
            delete _cntrlBlock;
        }

         qDebug() << "One of WeakPtr is deleted";

        return;

    }

    bool expired()const noexcept{
        return !*_cntrlBlock->shareCount;
    }

    void reset()noexcept{
        --*_cntrlBlock->weakCount;
        _cntrlBlock = new ControlBlock<T>;
    }


    SharePtr<T> lock(){
        return SharePtr<T>(_cntrlBlock);
    }

    void swap(WeakPtr<T> &rhs){
        qSwap(_cntrlBlock,rhs._cntrlBlock);
    }

    int shareCount()const noexcept{
        return *_cntrlBlock->shareCount;
    }

    bool ownerBefore(const SharePtr<T> & rhs){
        return _cntrlBlock->_ptr == rhs.getControlBlock()->_ptr;
    }

    bool ownerBefore(const WeakPtr<T> & rhs){
        return _cntrlBlock->_ptr != rhs._cntrlBlock->_ptr;
    }


    WeakPtr<T>& operator=(SharePtr<T>&& rhs) noexcept{
        --*_cntrlBlock->weakCount();

        _cntrlBlock->_ptr = rhs._cntrlBlock;
        ++*_cntrlBlock->weakCount;
    };

    WeakPtr<T>& operator=(const SharePtr<T>& rhs) noexcept{
        --*_cntrlBlock->weakCount();

        _cntrlBlock->_ptr = rhs._cntrlBlock;
        ++*_cntrlBlock->weakCount;
    };

private:
    ControlBlock<T> *_cntrlBlock;
};




#endif // WEAK_PTR_H
