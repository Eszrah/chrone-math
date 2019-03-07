#pragma once

#include "NativeType.h"

namespace chrone::math
{

template<class T, Uint32 Dim>
struct Vector
{
	inline Vector() = default;
	inline Vector(const Vector&) = default;
	inline Vector(Vector&&) = default;
	~Vector() = default;

	T	data[Dim];
};


template<class T>
struct Vector<T, 2>
{
	using Type = T;
	constexpr static CompCount = 2;

	inline Vector() = default;
	inline Vector(const Vector&) = default;
	inline Vector(Vector&&) = default;
	~Vector() = default;

	inline explicit Vector(const T x, const T y);
	inline explicit Vector(const T* srcData);

	T	data[CompCount];
};


template<class T>
struct Vector<T, 3>
{
	using Type = T;
	constexpr static CompCount = 3;

	inline Vector() = default;
	inline Vector(const Vector&) = default;
	inline Vector(Vector&&) = default;
	~Vector() = default;

	inline explicit Vector(const T x, const T y, const T z);
	inline explicit Vector(const T* srcData);

	T	data[CompCount];
};


template<class T>
struct Vector<T, 4>
{
	using Type = T;
	constexpr static CompCount = 4;

	inline Vector() = default;
	inline Vector(const Vector&) = default;
	inline Vector(Vector&&) = default;
	~Vector() = default;

	inline explicit Vector(const T x, const T y, const T z, const T w);
	inline explicit Vector(const T* srcData);

	T	data[CompCount];
};


template<class T>
inline 
Vector<T, 2>::Vector(
	const T x, 
	const T y):
	x{ x },
	y{ y }
{
}

template<class T>
inline 
Vector<T, 2>::Vector(
	const T* srcData)
{
	std::memcpy(data, srcData, sizeof(T) * CompCount);
}


template<class T>
inline 
Vector<T, 3>::Vector(
	const T x, 
	const T y, 
	const T z):
	x{ x },
	y{ y },
	z{ z }
{
}


template<class T>
inline
Vector<T, 3>::Vector(
	const T* srcData)
{
	std::memcpy(data, srcData, sizeof(T) * CompCount);
}


template<class T>
inline 
Vector<T, 4>::Vector(
	const T x, 
	const T y, 
	const T z, 
	const T w):
	x{ x },
	y{ y },
	z{ z },
	w{ w }
{
}

template<class T>
inline
Vector<T, 4>::Vector(
	const T* srcData)
{
	std::memcpy(data, srcData, sizeof(T) * CompCount);
}


template<class T>
using Vector3 = Vector<T, 3>;
using Vector3D32 = Vector3<Decimal32>;
using Vector3D64 = Vector3<Decimal64>;

template<class T>
using Vector4 = Vector<T, 4>;
using Vector4D32 = Vector4<Decimal32>;
using Vector4D64 = Vector4<Decimal64>;

}