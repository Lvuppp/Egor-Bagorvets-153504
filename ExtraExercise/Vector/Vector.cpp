#include "Vector.h"
#include"Vector.h"

template<class VectorType>
inline CVector<VectorType>::CVector::CVector(const std::initializer_list<VectorType>& initializerElements) {
	capacity_ = (VectorType)initializerElements.size();
	size_ = 0;
	array_ = new VectorType[capacity_];
	for (auto& element : initializerElements)
	{
		array_[size_] = element;
		++size_;
	}

}
template<class VectorType>
inline CVector<VectorType>::CVector::CVector() {
	size_ = 0;
	capacity_ = 1;
	array_ = new VectorType[capacity_];
}

template<class VectorType>
inline CVector<VectorType>::CVector::~CVector() {
	delete[] array_;
}

template<class VectorType>
inline int CVector<VectorType>::CVector::size() {
	return size_;
}

template<class VectorType>
inline int CVector<VectorType>::CVector::capacity() {
	return capacity_;
}

template<class VectorType>
inline void CVector<VectorType>::CVector::pushBack(const int& addElement) {
	if (size_ + 1 > capacity_) {
		increaseMemory();
	}
	array_[size_] = addElement;
	size_++;
}

template<class VectorType>
inline void CVector<VectorType>::CVector::popBack() {
	if (size_ != 0)
	{
		size_--;
	}
	else
	{
		throw std::exception("size of vector is 0");
	}
}

template<class VectorType>
inline VectorType CVector<VectorType>::CVector::front() {
	return array_[0];
}

template<class VectorType>
inline VectorType CVector<VectorType>::CVector::back() {
	return array_[size_ - 1];
}

template<class VectorType>
inline void CVector<VectorType>::CVector::reserve(const int& newSize) {
	if (newSize > capacity_) {
		increaseMemory(newSize);
	}
	else
	{
		throw std::exception(" you cannot reserve less memory than ");
	}
}

template<class VectorType>
inline VectorType CVector<VectorType>::CVector::at(int elementIndex) {
	if (elementIndex < size_ && size_ > 0)
		return array_[elementIndex];
	else
		throw std::exception("no such element exists");
}

template<class VectorType>
inline VectorType* CVector<VectorType>::CVector::begin() {
	return &array_[0];
}

template<class VectorType>
inline VectorType* CVector<VectorType>::CVector::end() {
	return &array_[size_ - 1];
}

template<class VectorType>
inline void CVector<VectorType>::CVector::insert(VectorType* iter, const VectorType& addElement) {
	if (size_ + 1 > capacity_)
	{
		increaseMemory();
	}
	++size_;
	for (size_t i = size_ + 1; i > iter - &array_[0]; i--)
	{
		array_[i] = array_[i - 1];
	}
	*iter = addElement;
}

template<class VectorType>
inline void CVector<VectorType>::CVector::erase(int index) {
	if (index > -1 && index < size_) {
		for (size_t i = index; i < size_; i++)
		{
			array_[i] = array_[i + 1];
		}
	}
	else {
		throw std::exception("imposible");
	}
}

template<class VectorType>
inline void CVector<VectorType>::CVector::printAll() {
	for (int i = 0; i < size_; i++)
	{
		std::cout << array_[i] << " ";
	}
	std::cout << " || ";
	for (int i = size_; i < capacity_; i++)
	{
		std::cout << array_[i] << " ";
	}
	std::cout << std::endl;
}

template<class VectorType>
inline void CVector<VectorType>::CVector::clear() {
	delete[] array_;
	size_ = 0;
	capacity_ = 1;
	array_ = new VectorType[capacity_];
}

template<class VectorType>
inline bool CVector<VectorType>::CVector::empty() {
	return size_ > 0 ? false : true;
}

template<class VectorType>
inline bool CVector<VectorType>::CVector::operator==(const CVector& rightValue) const {
	if (size_ == rightValue.size_)
	{
		for (int i = 0; i < size_; i++)
		{
			if (array_[i] != rightValue.array_[i])
				return 0;
		}
		return 1;
	}

	return 0;
}
template<class VectorType>
inline bool CVector<VectorType>::CVector::operator!=(const CVector& rightValue) const {
	return !(*this == rightValue);
}

template<class VectorType>
inline VectorType& CVector<VectorType>::CVector::operator[](int elementIndex)
{
	return array_[elementIndex];
}


template<class VectorType>
inline void CVector<VectorType>::CVector::increaseMemory() {
	VectorType* _oldArray = array_;
	capacity_ *= 2;
	array_ = new VectorType[capacity_];
	for (int i = 0; i < size_; i++)
	{
		array_[i] = _oldArray[i];
	}
	delete[] _oldArray;
}
template<class VectorType>
inline void CVector<VectorType>::CVector::increaseMemory(int newSize) {
	VectorType* _oldArray = array_;
	capacity_ = newSize;
	array_ = new VectorType[capacity_];
	for (int i = 0; i < size_; i++)
	{
		array_[i] = _oldArray[i];
	}
	delete[] _oldArray;
}