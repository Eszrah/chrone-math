#pragma once

#include "NativeType.h"
#include "VectorComponent.h"

namespace chrone::math
{

template<class T>
struct Vector2D
{
	using ComponentType = typename T::Type;

	inline Vector2D() = default;
	inline Vector2D(Vector2D const&) = default;
	inline Vector2D(Vector2D&&) = default;
	inline ~Vector2D() = default;

	inline explicit Vector2D(ComponentType const value0, ComponentType const value1);
	inline explicit Vector2D(ComponentType const value);

	inline Vector2D& operator=(Vector2D const&) = default;
	inline Vector2D& operator=(Vector2D&&) = default;

	union
	{
		Vector1DComponent<T, 0> x;
		Vector1DComponent<T, 1>	y;

		Vector2DComponent<T, 0, 1>	xy{};
		Vector2DComponent<T, 1, 0>	yx;
	};
};


template<class T>
inline 
Vector2D<T>::Vector2D(
	ComponentType const value0, 
	ComponentType const value1):
	xy{value0, value1}
{
}


template<class T>
inline 
Vector2D<T>::Vector2D(ComponentType const value):
	xy{value, value}
{
}


template<class T>
Vector2D<T>	operator+(
	Vector2D<T> const& l,
	const Vector2D<T>& r)
{
	return Vector2D<T>{l.x + r.x, l.y + r.y};
}


template<class T>
Vector2D<T>	operator-(
	Vector2D<T> const& l,
	const Vector2D<T>& r)
{
	return Vector2D<T>{l.x - r.x, l.y - r.y};
}


template<class T>
struct Vector2DMapData
{
	using Type = T;
	using Type2D = Vector2D<Vector2DMapData>;
};


using Vector2DMapDataDec32 = Vector2DMapData<Decimal32>;
using Vector2DMapDataDec64 = Vector2DMapData<Decimal64>;
using Vector2DDec32 = Vector2D<Vector2DMapDataDec32>;
using Vector2DDec64 = Vector2D<Vector2DMapDataDec64>;

template<class T>
struct Vector3D
{
	using ComponentType = typename T::Type;

	using TypeVector2DMapData = Vector2DMapData<ComponentType>;

	inline Vector3D() = default;
	inline Vector3D(Vector3D const&) = default;
	inline Vector3D(Vector3D &&) = default;
	inline ~Vector3D() = default;

	inline explicit Vector3D(ComponentType const value0, ComponentType const value1, ComponentType const value2);
	inline explicit Vector3D(ComponentType const value);

	inline Vector3D& operator=(Vector3D const&) = default;
	inline Vector3D& operator=(Vector3D &&) = default;

	union
	{
		Vector1DComponent<T, 0> x;
		Vector1DComponent<T, 1>	y;
		Vector1DComponent<T, 2>	z;

		Vector2DComponent<TypeVector2DMapData, 0, 1>	xy;
		Vector2DComponent<TypeVector2DMapData, 1, 0>	yx;
		Vector2DComponent<TypeVector2DMapData, 0, 2>	xz;
		Vector2DComponent<TypeVector2DMapData, 2, 0>	zx;
		Vector2DComponent<TypeVector2DMapData, 1, 2>	yz;
		Vector2DComponent<TypeVector2DMapData, 2, 1>	zy;

		Vector3DComponent<T, 0, 1, 2> xyz;
		Vector3DComponent<T, 0, 2, 1> xzy;
		Vector3DComponent<T, 1, 0, 2> yxz;
		Vector3DComponent<T, 1, 2, 0> yzx;
		Vector3DComponent<T, 2, 0, 1> zxy;
		Vector3DComponent<T, 2, 1, 0> zyx;
	};
};


template<class T>
inline Vector3D<T>::Vector3D(
	ComponentType const value0,
	ComponentType const value1,
	ComponentType const value2) :
	xyz{ value0, value1, value2 }
{
}


template<class T>
inline Vector3D<T>::Vector3D(ComponentType const value) :
	xyz{ value, value, value }
{
}


template<class T>
Vector3D<T>	operator+(
	Vector3D<T> const& l,
	const Vector3D<T>& r)
{
	return Vector3D<T>{l.x + r.x, l.y + r.y, l.z + r.z};
}


template<class T>
Vector3D<T>	operator-(
	Vector3D<T> const& l,
	const Vector3D<T>& r)
{
	return Vector3D<T>{l.x - r.x, l.y - r.y, l.z - r.z};
}

template<class T>
struct Vector3DMapData
{
	using Type = T;
	using Type2D = Vector2D<Vector2DMapData<T>>;
	using Type3D = Vector3D<Vector3DMapData>;
};


using Vector3DMapDataDec32 = Vector3DMapData<Decimal32>;
using Vector3DMapDataDec64 = Vector3DMapData<Decimal64>;
using Vector3DDec32 = Vector3D<Vector3DMapDataDec32>;
using Vector3DDec64 = Vector3D<Vector3DMapDataDec64>;




template<class T>
struct Vector4D
{
	using ComponentType = typename T::Type;
	using TypeVector3D = typename T::Type3D;

	using TypeVector2DMapData = Vector2DMapData<ComponentType>;
	using TypeVector3DMapData = Vector3DMapData<ComponentType>;

	inline Vector4D() = default;
	inline Vector4D(Vector4D const&) = default;
	inline Vector4D(Vector4D &&) = default;
	inline ~Vector4D() = default;

	inline explicit Vector4D(ComponentType const value0, ComponentType const value1, 
		ComponentType const value2, ComponentType const value3);

	inline explicit Vector4D(ComponentType const value);
	inline explicit Vector4D(TypeVector3D const& vector3D);

	inline Vector4D& operator=(Vector4D const&) = default;
	inline Vector4D& operator=(Vector4D &&) = default;

	union
	{
		Vector1DComponent<T, 0> x;
		Vector1DComponent<T, 1>	y;
		Vector1DComponent<T, 2>	z;
		Vector1DComponent<T, 3>	w;

		Vector2DComponent<TypeVector2DMapData, 0, 1>	xy;
		Vector2DComponent<TypeVector2DMapData, 0, 2>	xz;
		Vector2DComponent<TypeVector2DMapData, 0, 3>	xw;

		Vector2DComponent<TypeVector2DMapData, 1, 0>	yx;
		Vector2DComponent<TypeVector2DMapData, 1, 2>	yz;
		Vector2DComponent<TypeVector2DMapData, 1, 3>	yw;

		Vector2DComponent<TypeVector2DMapData, 2, 0>	zx;
		Vector2DComponent<TypeVector2DMapData, 2, 1>	zy;
		Vector2DComponent<TypeVector2DMapData, 2, 3>	zw;

		Vector2DComponent<TypeVector2DMapData, 3, 0>	wx;
		Vector2DComponent<TypeVector2DMapData, 3, 1>	wy;
		Vector2DComponent<TypeVector2DMapData, 3, 2>	wz;


		Vector3DComponent<TypeVector3DMapData, 0, 1, 2>	xyz;
		Vector3DComponent<TypeVector3DMapData, 0, 1, 3> xyw;

		Vector3DComponent<TypeVector3DMapData, 0, 2, 1> xzy;
		Vector3DComponent<TypeVector3DMapData, 0, 2, 3> xzw;

		Vector3DComponent<TypeVector3DMapData, 1, 0, 2> yxz;
		Vector3DComponent<TypeVector3DMapData, 1, 0, 3> yxw;

		Vector3DComponent<TypeVector3DMapData, 1, 2, 0> yzx;
		Vector3DComponent<TypeVector3DMapData, 1, 2, 3> yzw;

		Vector3DComponent<TypeVector3DMapData, 2, 0, 1> zxy;
		Vector3DComponent<TypeVector3DMapData, 2, 0, 3> zxw;

		Vector3DComponent<TypeVector3DMapData, 2, 1, 0> zyx;
		Vector3DComponent<TypeVector3DMapData, 2, 1, 3> zyw;

		Vector4DComponent<T, 0, 1, 2, 3> xyzw;
	};
};


template<class T>
inline 
Vector4D<T>::Vector4D(
	ComponentType const value0, 
	ComponentType const value1, 
	ComponentType const value2, 
	ComponentType const value3):
	xyzw{ value0, value1, value2, value3 }
{
}


template<class T>
inline 
Vector4D<T>::Vector4D(
	ComponentType const value):
	xyzw{ value, value, value, value }
{
}

template<class T>
inline 
Vector4D<T>::Vector4D(
	TypeVector3D const& vector3D):
	xyz{ vector3D.xyz }
{
	w = static_cast<typename T::Type>(0);
}


template<class T>
struct Vector4DMapData
{
	using Type = T;
	using Type2D = Vector2D<Vector2DMapData<T>>;
	using Type3D = Vector3D<Vector3DMapData<T>>;
	using Type4D = Vector4D<Vector4DMapData<T>>;
};

using Vector4DMapDataDec32 = Vector4DMapData<Decimal32>;
using Vector4DMapDataDec64 = Vector4DMapData<Decimal64>;
using Vector4DDec32 = Vector4D<Vector4DMapDataDec32>;
using Vector4DDec64 = Vector4D<Vector4DMapDataDec64>;

}