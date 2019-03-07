#pragma once

#include "Vector.h"
#include "Bivector.h"

namespace chrone::math
{

template<
	class T, 
	Uint32 Dim>
inline Vector<T, Dim>
operator+(Vector<T, Dim> const& l, Vector<T, Dim> const& r)
{
	Vector<T, Dim>	res;

	for(Uint32 i = 0u; i < Dim; ++i)
	{
		res.data[i] = l.data[i] + r.data[i];
	}

	return res;
}


template<
	class T,
	Uint32 Dim>
inline Vector<T, Dim>
operator-(Vector<T, Dim> const& l, Vector<T, Dim> const& r)
{
	Vector<T, Dim>	res;

	for(Uint32 i = 0u; i < Dim; ++i)
	{
		res.data[i] = l.data[i] - r.data[i];
	}

	return res;
}


template<
	class U,
	class T,
	Uint32 Dim>
inline Vector<T, Dim>
operator*(U integral, Vector<T, Dim> const& r)
{
	Vector<T, Dim>	res;

	for(Uint32 i = 0u; i < Dim; ++i)
	{
		res.data[i] = integral * r.data[i];
	}

	return res;
}


template<
	class U,
	class T,
	Uint32 Dim>
inline Vector<T, Dim>
operator*(Vector<T, Dim> const& l, U integral)
{
	Vector<T, Dim>	res;

	for(Uint32 i = 0u; i < Dim; ++i)
	{
		res.data[i] = l.data[i] * integral;
	}

	return res;
}


template<
	class T,
	Uint32 Dim>
T InnerProduct(Vector<T, Dim> const& l, Vector<T, Dim> const& r)
{
	T	result{static_cast<T>( 0 )};

	for(Uint32 i = 0u; i < Dim; ++i)
	{
		result += l.data[i] * r.data[i];
	}

	return result;
}


template<class T>
inline Bivector<T, 2>
OuterProduct(Vector<T, 2> const& l, Vector<T, 2> const& r)
{
	return Bivector<T, 2>{l.data[0] * r.data[1] - l.data[1] * r.data[0]};
}


template<class T>
inline Bivector<T, 3>
OuterProduct(Vector<T, 3> const& l, Vector<T, 3> const& r)
{
	return Bivector<T, 3>{
		l.data[1] * r.data[2] - l.data[2] * r.data[1],
		l.data[0] * r.data[2] - l.data[2] * r.data[0],
		l.data[0] * r.data[1] - l.data[1] * r.data[0]};
}



}