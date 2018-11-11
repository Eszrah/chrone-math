#pragma once

#include "NativeType.h"

namespace chrone::math
{

template<
	class T, 
	Uint32 ColumnCount, 
	Uint32 RowCount>
struct Matrix
{
	constexpr static CompCount = ColumnCount* RowCount;

	inline Matrix() = default;
	inline Matrix(const Matrix&) = default;
	inline Matrix(Matrix&&) = default;
	~Matrix() = default;

	T	data[CompCount];
};


template<class T>
struct Matrix<T, 3, 3>
{
	constexpr static ColumnCount = 3;
	constexpr static RowCount = 3;
	constexpr static CompCount = ColumnCount* RowCount;
	inline Matrix() = default;
	inline Matrix(const Matrix&) = default;
	inline Matrix(Matrix&&) = default;
	~Matrix() = default;

	inline explicit Matrix(const T* srcData);
	inline explicit Matrix(const T* col0, const T* col1, const T* col2);


	T	data[CompCount];
};


template<class T>
struct Matrix<T, 4, 4>
{
	constexpr static ColumnCount = 4;
	constexpr static RowCount = 4;
	constexpr static CompCount = ColumnCount* RowCount;

	inline Matrix() = default;
	inline Matrix(const Matrix&) = default;
	inline Matrix(Matrix&&) = default;
	~Matrix() = default;

	inline explicit Matrix(const T* srcData);
	inline explicit Matrix(const T* col0, const T* col1, const T* col2, const T* col3);


	T	data[CompCount];
};



template<class T>
inline 
Matrix<T, 3, 3>::Matrix(
	const T* srcData)
{
	std::memcpy(data, srcData, sizeof(T) * CompCount);
}


template<class T>
inline 
Matrix<T, 3, 3>::Matrix(
	const T* col0, 
	const T* col1, 
	const T* col2)
{
	std::memcpy(data, col0, sizeof(T) * RowCount);
	std::memcpy(data + 3, col1, sizeof(T) * RowCount);
	std::memcpy(data + 6, col2, sizeof(T) * RowCount);
}


template<class T>
inline 
Matrix<T, 4, 4>::Matrix(
	const T* srcData)
{
	std::memcpy(data, srcData, sizeof(T) * CompCount);
}


template<class T>
inline 
Matrix<T, 4, 4>::Matrix(
	const T* col0, 
	const T* col1, 
	const T* col2, 
	const T* col3)
{
	std::memcpy(data, col0, sizeof(T) * RowCount);
	std::memcpy(data + 4, col1, sizeof(T) * RowCount);
	std::memcpy(data + 8, col2, sizeof(T) * RowCount);
	std::memcpy(data + 12, col3, sizeof(T) * RowCount);
}


}