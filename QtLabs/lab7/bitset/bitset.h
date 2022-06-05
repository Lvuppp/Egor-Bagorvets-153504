#ifndef BITSET_H
#define BITSET_H
#include<iostream>
#include<vector>
#include<QApplication>

using namespace std;

template<unsigned long long N>
class BitSet
{
public:
    BitSet(){};

    BitSet(unsigned long long value){
        for (int i = 0; i < N && value != 0; i++) {
            _arr[i / _size] |= ((value % 2) << i % _size);
            value /= 2;
        }
    };

    bool all() const{
        for(unsigned long long i = 0;i != _size;i++){
            if(!(_arr[i / _size] & (1 << (i % _size))))
                return false;
        }
        return true;
    };

    bool any() const{
        for(unsigned long long i = 0;i != _size;i++){
            if((_arr[i / _size] & (1 << (i % _size))))
                return true;
        }
        return false;
    };

    bool count(){
        unsigned long long tmp = 0;

        for(unsigned long long i = 0; i < N; i++){
            if((_arr[i / _size] & (1 << (i % _size))))
                tmp++;
            qDebug() << tmp << " " << i;
        }

        return tmp;
    }

    BitSet<N> flip(){
        for (unsigned long long i = 0; i <= N; i++) {
            _arr[i / _size] ^= (1 << (i % _size));
        }
        return *this;
    }

    BitSet<N> flip(unsigned long long index){
        _arr[index / _size] ^= (1 << (index % _size));

        return *this;
    }

    bool none(){
        for(unsigned long long i = 0;i != _size;i++){
            if(_arr[i / _size] & (1 << (i % _size))){
                return true;
            }
        }
        return false;

    };

    BitSet<N> reset(){
        for(unsigned long long i = 0;i <= N / _size;i++){
            _arr[i] = _arr[i] & (unsigned long long)0;
        }
        return *this;
    }

    BitSet<N> reset(unsigned long long index){
        qDebug() << _arr[index / _size];
        _arr[index / _size] &= ~(1 << index % _size);
    }

    BitSet<N> set(){
        for(unsigned long long i = 0;i < _size;i++){
            _arr[i / _size] |= (1 << i % _size);
        }
    }

    BitSet<N> set(unsigned long long index){
        _arr[index / _size] |= (1 << index % _size);
    }

    unsigned long long size(){
        return N;
    }

    bool test(unsigned long long index){
        if (index >= N)
            return false;

        return _arr[index / _size] >> index % _size & 1;
    }

    string toString(){
        std::string str;
            for (int i = N - 1; i >= 0; i--)
            {
                str += (int)this->operator[](i) + '0';
            }
            return str;
    }

    unsigned long long toULong(){
        unsigned long long tmp = 0;
        unsigned long long degree = 1;

        for(unsigned long long i = 0; i < _size;i++){
            tmp += _arr[i] * degree;
            degree*=2;
        }

        return tmp;
    }


    bool operator[](unsigned long long index) const{
        bool tmp = _arr[index / _size] & (1 << index % _size);
        return tmp;
    };

    BitSet<N> operator~() const{
        this->flip();
    };

    BitSet<N>& operator&=(BitSet<N>& rhs){
        for(unsigned long long i = 0; i <= N /_size; i++){
            _arr[i] &= rhs._arr[i];
        }
        return *this;
    };

    bool operator& (BitSet<N> rhs){
        for(unsigned long long i = 0;i <= N/  _size;i++){
            if(_arr[i / _size] == rhs._arr[i]){
                return true;
            }
        }
    };

    BitSet<N>& operator |=(BitSet<N> rhs){
        for(unsigned long long i = 0; i <= N / _size; i++){
            _arr[i] |= rhs._arr[i];
        }
        return *this;
    };

    BitSet<N> operator|(BitSet<N>& rhs){
        BitSet<N> tmp;
        for (int i = 0; i <= N / _size; i++){
            tmp._arr[i] = _arr[i] | rhs._arr[i];
        }
        return tmp;
    };

    BitSet<N>& operator^=(const BitSet<N>& rhs){
        for (int i = 0; i <= N / _size; i++){
            _arr[i] ^= rhs._arr[i];
        }
        return *this;
    };

    BitSet<N> operator^(BitSet<N>& rhs){
        BitSet<N> tmp;
        for (int i = 0; i <= N / _size; i++){
            tmp._arr[i] = _arr[i] ^ rhs._arr[i];
        }
        return tmp;
    };

private:
    unsigned long long _size = 8 * sizeof(unsigned long long);
    unsigned long long _arr[(N % (sizeof(unsigned long long) * 8) == 0) ?
            N / (sizeof(unsigned long long) * 8) : N / (sizeof(unsigned long long) * 8) + 1]{0};
};

#endif // BITSET_H
