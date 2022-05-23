#ifndef SHARED_ptr_H
#define SHARED_ptr_H

#include<QApplication>
using namespace std;

template<typename T>
struct ControlBlock{
    std::size_t *shareCount = new std::size_t(0);
    std::size_t *weakCount = new std::size_t(0);
    T* _ptr = nullptr;

};

template<typename T>
class WeakPtr;

template<typename T>
class SharePtr
{
public:


    SharePtr(const SharePtr& rvs){
        _cntrlBlock->_ptr = rvs._cntrlBlock->_ptr;
        _cntrlBlock->shareCount = rvs._cntrlBlock->shareCount;
        _cntrlBlock->weakCount = rvs._cntrlBlock->weakCount;
        ++*_cntrlBlock->shareCount;
    };

    SharePtr(const SharePtr&& rvs){
        _cntrlBlock->_ptr = rvs._cntrlBlock->_ptr;
        _cntrlBlock->shareCount = rvs._cntrlBlock->shareCount;
        _cntrlBlock->weakCount = rvs._cntrlBlock->weakCount;
        ++*_cntrlBlock->shareCount;
    };

    SharePtr(T* ptr = nullptr){
        _cntrlBlock->_ptr = ptr;
        _cntrlBlock->shareCount = new std::size_t(1);
        _cntrlBlock->weakCount = new std::size_t(0);
    };


    ~SharePtr(){
        --*_cntrlBlock->shareCount;
         if(*_cntrlBlock->weakCount == 0 && *_cntrlBlock->shareCount == 0){
            qDebug() <<"Control block is deleted";
            delete _cntrlBlock;
        }
        if(*_cntrlBlock->shareCount == 0 && *_cntrlBlock->weakCount != 0 ){
            qDebug() <<"Cant delete cause exist WeakPtr deleted";
        }

        qDebug() << "One of SharePtr is deleted";

        return;
    };

    T* get() const{
        return _cntrlBlock->_ptr;
    };

    void reset(T* newPtr = nullptr){
        --*_cntrlBlock->shareCount;
        _cntrlBlock = new ControlBlock<T>;

        if(newPtr != nullptr){
            _cntrlBlock->_ptr = newPtr;
            ++*_cntrlBlock->shareCount;
        }
    };

    bool uniq()const{
        return !(*_cntrlBlock->shareCount - 1);
    }

    int shareCount()const{
        return *_cntrlBlock->shareCount;
    }

    void swap(SharePtr<T>& rhs){
        qSwap(_cntrlBlock->_ptr,rhs._cntrlBlock->_ptr);
        qSwap(_cntrlBlock->shareCount,rhs._cntrlBlock->shareCount);
        qSwap(_cntrlBlock->weakCount,rhs._cntrlBlock->weakCount);
    }

    T& operator*()noexcept{
        return *_cntrlBlock->_ptr;
    };

    T* operator->()const noexcept{
        return _cntrlBlock->_ptr;
    };

    operator bool()const {
        if(_cntrlBlock == nullptr)
            return false;

        return true;
    }

    SharePtr& operator=(const SharePtr& rhs) noexcept{
        if(rhs._cntrlBlock->_ptr == _cntrlBlock->_ptr)
            return *this;

        delete _cntrlBlock->_ptr;
        delete _cntrlBlock->shareCount;
        delete _cntrlBlock->weakCount;

        _cntrlBlock->_ptr = rhs._cntrlBlock->_ptr;
        _cntrlBlock->shareCount = rhs._cntrlBlock->shareCount;
        _cntrlBlock->weakCount = rhs._cntrlBlock->weakCount;

        return *this;
    };

    friend class WeakPtr<T>;

private:

    SharePtr(ControlBlock<T> *controlBlock){
        _cntrlBlock->_ptr = controlBlock->_ptr;
        _cntrlBlock->shareCount = controlBlock->shareCount;
        _cntrlBlock->weakCount = controlBlock->weakCount;
         ++*_cntrlBlock->shareCount;
    };

    ControlBlock<T> *_cntrlBlock = new ControlBlock<T>();
};


#endif // SHAREDcontrolBlock->_ptr_H
