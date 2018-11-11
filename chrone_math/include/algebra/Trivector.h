#pragma once

#include "NativeType.h"


namespace chrone::math
{

template<
	class T,
	Uint32 CompCount>
struct Trivector
{
};


template<class T>
struct Trivector<T, 3>
{
	using Type = T;
	constexpr static CompCount = 1;

	inline Trivector() = default;
	inline Trivector(const Trivector&) = default;
	inline Trivector(Trivector&&) = default;
	~Trivector() = default;

	inline explicit Trivector(const T x);
	inline explicit Trivector(const T* srcData);

	T	data[CompCount];
};


template<class T>
struct Trivector<T, 4>
{
	using Type = T;
	//constexpr static CompCount = 1;

	inline Trivector() = default;
	inline Trivector(const Trivector&) = default;
	inline Trivector(Trivector&&) = default;
	~Trivector() = default;

	//inline explicit Trivector(const T x);
	//inline explicit Trivector(const T* srcData);

	//T	data[CompCount];
};
}