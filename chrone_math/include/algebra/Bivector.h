#pragma once

#include "NativeType.h"

namespace chrone::math
{

template<
	class T, 
	Uint32 CompCount>
struct Bivector
{
};


template<class T>
struct Bivector<T, 2>
{
	using Type = T;
	constexpr static CompCount = 1;

	inline Bivector() = default;
	inline Bivector(const Bivector&) = default;
	inline Bivector(Bivector&&) = default;
	~Bivector() = default;

	inline explicit Bivector(const T x);
	inline explicit Bivector(const T* srcData);

	T	data[CompCount]; //[a1b2 - a2b1] e1^e2 (I)
};


template<class T>
struct Bivector<T,3>
{
	using Type = T;
	constexpr static CompCount = 3;

	inline Bivector() = default;
	inline Bivector(const Bivector&) = default;
	inline Bivector(Bivector&&) = default;
	~Bivector() = default;

	inline explicit Bivector(const T x, const T y, const T z);
	inline explicit Bivector(const T* srcData);

	T	data[CompCount]; //[a2b3 - a3b2]e2^e3; [a3b1 - a1b3]e3^e1; [a1b2 - a2b1]e1^e2
};


template<class T>
inline 
Bivector<T, 2>::Bivector(
	const T x)
{
}


template<class T>
inline 
Bivector<T, 2>::Bivector(
	const T * srcData)
{
}


template<class T>
inline 
Bivector<T, 3>::Bivector(
	const T x, 
	const T y, 
	const T z)
{

}

}