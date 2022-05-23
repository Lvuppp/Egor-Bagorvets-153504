#ifndef UniqPtr_H
#define UniqPtr_H

#include<memory>
#include<QApplication>


template<typename T>
class UniqPtr
{
public:
    constexpr UniqPtr() noexcept{};
    explicit UniqPtr(T* ptr = nullptr) :_ptr(ptr){};
    UniqPtr(UniqPtr<T>&& rhs){
        _ptr = rhs._ptr;
        rhs._ptr = nullptr;
    };

    UniqPtr(UniqPtr<T>& uPtr) = delete;
    UniqPtr(UniqPtr<T> const& rhs) = delete;

    ~UniqPtr() noexcept {
        qDebug() <<"obj delete"  ;
        delete _ptr;
    };

    void reset(T* newPtr){
        _ptr =nullptr;
        _ptr = newPtr;
    };

    std::default_delete<T> getDeleter(){
        return std::default_delete<T>();
    };

    T* get() const{
        return _ptr;
    };

    T* realese(){
        T* tmp = _ptr;
        _ptr = nullptr;
        return tmp;
    };

    void swap(UniqPtr&& rhs){
        auto tmp = this->_ptr;
        this->_ptr = rhs._ptr;
        rhs._ptr = tmp;
    };

    T& operator*(){
        return *_ptr;
    };

    T* operator->()const noexcept{
        return _ptr;
    };

    UniqPtr<T>& operator=(UniqPtr& rhs) = delete;

    UniqPtr<T>& operator=(UniqPtr&& rhs) noexcept{

        delete _ptr;

        _ptr = rhs._ptr;
        rhs._ptr = nullptr;

        return *this;
    }

private:
    T* _ptr = nullptr;

};


#endif // UniqPtr_H
