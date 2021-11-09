#pragma once
#include<iostream>
#include<exception>

template <class VectorType>class CVector
{
public:

	CVector();
	CVector(const std::initializer_list<VectorType>& initializerElements);
	~CVector();

	int size();
	int capacity();
	void pushBack(const int& addElement);
	void popBack();
	VectorType front();
	VectorType back();
	void reserve(const int& newSize);
	VectorType at(int elementIndex);
	VectorType* begin();
	VectorType* end();
	void insert(VectorType* iter, const VectorType& addElement);
	void erase(int index);
	void printAll();
	void clear();
	bool empty();

	bool operator==(const CVector& rightValue) const;
	bool operator!=(const CVector& rightValue) const;
	VectorType& operator[](int elementIndex);

private:
	int capacity_;
	int size_;
	VectorType* array_;

	void increaseMemory();
	void increaseMemory(int newSize);
};
