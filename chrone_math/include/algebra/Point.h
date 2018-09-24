#pragma once

#include "NativeType.h"
#include "VectorComponent.h"

namespace chrone::math
{

template<class T>
struct Point2D
{
	using ComponentType = typename T::Type;


	inline Point2D() = default;
	inline Point2D(Point2D const&) = default;
	inline Point2D(Point2D &&) = default;
	inline ~Point2D() = default;

	inline explicit Point2D(ComponentType const value0, ComponentType const value1);
	inline explicit Point2D(ComponentType const value);

	inline Point2D& operator=(Point2D const&) = default;
	inline Point2D& operator=(Point2D &&) = default;

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
Point2D<T>::Point2D(
	ComponentType const value0,
	ComponentType const value1) :
	xy{ value0, value1 }
{
}


template<class T>
inline
Point2D<T>::Point2D(ComponentType const value) :
	xy{ value, value }
{
}


template<class T>
struct Point2DMapData
{
	using Type = T;
	using Type2D = Point2D<Point2DMapData>;
};



template<class T>
struct Point3D
{
	using ComponentType = typename T::Type;


	inline Point3D() = default;
	inline Point3D(Point3D const&) = default;
	inline Point3D(Point3D &&) = default;
	inline ~Point3D() = default;

	inline explicit Point3D(ComponentType const value0, ComponentType const value1, ComponentType const value2);
	inline explicit Point3D(ComponentType const value);

	inline Point3D& operator=(Point3D const&) = default;
	inline Point3D& operator=(Point3D &&) = default;

	union
	{
		Vector1DComponent<T, 0> x;
		Vector1DComponent<T, 1>	y;
		Vector1DComponent<T, 2>	z;

		Vector2DComponent<T, 0, 1>	xy;
		Vector2DComponent<T, 1, 0>	yx;
		Vector2DComponent<T, 0, 2>	xz;
		Vector2DComponent<T, 2, 0>	zx;
		Vector2DComponent<T, 1, 2>	yz;
		Vector2DComponent<T, 2, 1>	zy;

		Vector3DComponent<T, 0, 1, 2> xyz;
		Vector3DComponent<T, 0, 2, 1> xzy;
		Vector3DComponent<T, 1, 0, 2> yxz;
		Vector3DComponent<T, 1, 2, 0> yzx;
		Vector3DComponent<T, 2, 0, 1> zxy;
		Vector3DComponent<T, 2, 1, 0> zyx;
	};
};

template<class T>
inline Point3D<T>::Point3D(
	ComponentType const value0,
	ComponentType const value1,
	ComponentType const value2) :
	xyz{ value0, value1, value2 }
{
}


template<class T>
inline Point3D<T>::Point3D(ComponentType const value) :
	xyz{ value, value, value }
{
}


template<class T>
struct Point3DMapData
{
	using Type = T;
	using Type2D = Vector2D<Point2DMapData<T>>;
	using Type3D = Vector3D<Point3DMapData>;
};


}