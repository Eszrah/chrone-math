#pragma once

#include "NativeType.h"
#include "ComponentMapper.h"


namespace chrone::math
{

template<
	class T,
	Uint8 index0>
struct Vector1DComponent
{
	using ComponentType = typename T::Type;
	using AggregateTypeRef = std::add_lvalue_reference_t<ComponentType>;
	using AggregateTypeCRef = std::add_lvalue_reference_t<ComponentType const>;

	inline Vector1DComponent() = default;
	inline Vector1DComponent(ComponentType const value);
	inline ~Vector1DComponent() = default;


	template<Uint8 otherIndex>
	inline Vector1DComponent&	operator=(Vector1DComponent<T, otherIndex> const& other);

	template<Uint8 otherIndex>
	inline Vector1DComponent&	operator=(Vector1DComponent<T, otherIndex>&& other);


	inline Vector1DComponent&	operator=(ComponentType const value);
	inline operator const ComponentType() const;

	ComponentType	components[1];
};


template<
	class T, 
	Uint8 index0>
inline 
Vector1DComponent<T, index0>::Vector1DComponent(ComponentType const value)
{
	components[index0] = value;
}


template<
	class T,
	Uint8 index0>
	template<Uint8 otherIndex>
inline Vector1DComponent<T, index0>&
Vector1DComponent<T, index0>::operator=(
	Vector1DComponent<T, otherIndex> const& other)
{
	components[index0] = other.components[otherIndex];
	return (*this);
}


template<
	class T,
	Uint8 index0>
	template<Uint8 otherIndex>
inline Vector1DComponent<T, index0>&
Vector1DComponent<T, index0>::operator=(
	Vector1DComponent<T, otherIndex>&& other)
{
	components[index0] = other.components[otherIndex];
	return (*this);
}


template<
	class T, 
	Uint8 index0>
inline Vector1DComponent<T, index0>&
Vector1DComponent<T, index0>::operator=(ComponentType const value)
{
	components[index0] = value;
	return *this;
}


template<
	class T, 
	Uint8 index0>
inline 
Vector1DComponent<T, index0>::operator const ComponentType() const
{
	return components[index0];
}




template<
	class T,
	Uint8 index0,
	Uint8 index1>
struct Vector2DComponent 
{
	using ComponentType = typename T::Type;
	using Type2D = typename T::Type2D;
	using Type2DRef = std::add_lvalue_reference_t<Type2D>;
	using Type2DCRef = std::add_lvalue_reference_t<Type2D const>;
	using Type2DRRef = std::add_rvalue_reference_t<Type2D>;

	inline Vector2DComponent() = default;
	inline ~Vector2DComponent() = default;

	inline Vector2DComponent(ComponentType const value0, ComponentType const value1);
	inline Vector2DComponent(ComponentType const value);

	inline operator typename ComponentMapper2D<T, index0, index1>::Type2DRef();


	inline Vector2DComponent& operator=(Type2DCRef aggregate);
	inline Vector2DComponent& operator=(Type2DRRef aggregate);


	template<Uint8 otherIndex0, Uint8 otherIndex1>
	inline Vector2DComponent& operator=(Vector2DComponent<T, otherIndex0, otherIndex1> const& other);

	ComponentType	components[2];
};


template<
	class T, 
	Uint8 index0, 
	Uint8 index1>
inline Vector2DComponent<T, index0, index1>::Vector2DComponent(
	ComponentType const value0, 
	ComponentType const value1)
{
	components[index0] = value0;
	components[index1] = value1;
}


template<
	class T, 
	Uint8 index0, 
	Uint8 index1>
inline Vector2DComponent<T, index0, index1>::Vector2DComponent(
	ComponentType const value)
{
	components[index0] = value;
	components[index1] = value;
}


template<
	class T, 
	Uint8 index0, 
	Uint8 index1>
inline 
Vector2DComponent<T, index0, index1>::operator typename 
ComponentMapper2D<T, index0, index1>::Type2DRef()
{
	return ComponentMapper2D<T, index0, index1>::Map(components);
}


template<
	class T, 
	Uint8 index0, 
	Uint8 index1>
inline Vector2DComponent<T, index0, index1>& 
Vector2DComponent<T, index0, index1>::operator=(
	Type2DCRef aggregate)
{
	components[index0] = aggregate.x;
	components[index1] = aggregate.y;
	return *this;
}


template<
	class T,
	Uint8 index0,
	Uint8 index1>
inline Vector2DComponent<T, index0, index1>&
Vector2DComponent<T, index0, index1>::operator=(
	Type2DRRef aggregate)
{
	components[index0] = aggregate.x;
	components[index1] = aggregate.y;
	return *this;
}


template<
	class T, 
	Uint8 index0, 
	Uint8 index1>
template<
	Uint8 otherIndex0, 
	Uint8 otherIndex1>
inline Vector2DComponent<T, index0, index1>& 
Vector2DComponent<T, index0, index1>::operator=(
	Vector2DComponent<T, otherIndex0, otherIndex1> const & other)
{
	components[index0] = other.components[otherIndex0];
	components[index1] = other.components[otherIndex1];
	return *this;
}




template<
	class T,
	Uint8 index0,
	Uint8 index1,
	Uint8 index2>
struct Vector3DComponent
{
	using ComponentType = typename T::Type;
	using Type3D = typename T::Type3D;
	using Type3DRef = std::add_lvalue_reference_t<Type3D>;
	using Type3DCRef = std::add_lvalue_reference_t<Type3D const>;
	using Type3DRRef = std::add_rvalue_reference_t<Type3D>;

	inline Vector3DComponent() = default;
	inline ~Vector3DComponent() = default;

	inline Vector3DComponent(ComponentType const value0, ComponentType const value1, ComponentType const value2);
	inline Vector3DComponent(ComponentType const value);

	inline operator typename ComponentMapper3D<T, index0, index1, index2>::Type3DRef();


	inline Vector3DComponent& operator=(Type3DCRef aggregate);
	inline Vector3DComponent& operator=(Type3DRRef aggregate);


	template<Uint8 otherIndex0, Uint8 otherIndex1, Uint8 otherIndex2>
	inline Vector3DComponent& operator=(Vector3DComponent<T, otherIndex0, otherIndex1, otherIndex2> const& other);


	ComponentType	components[3];
};

template<
	class T, 
	Uint8 index0, 
	Uint8 index1, 
	Uint8 index2>
inline Vector3DComponent<T, index0, index1, index2>::Vector3DComponent(
	ComponentType const value0, 
	ComponentType const value1, 
	ComponentType const value2)
{
	components[index0] = value0;
	components[index1] = value1;
	components[index2] = value2;
}

template<
	class T,
	Uint8 index0,
	Uint8 index1,
	Uint8 index2>
inline Vector3DComponent<T, index0, index1, index2>::Vector3DComponent(
	ComponentType const value)
{
	components[index0] = value;
	components[index1] = value;
	components[index2] = value;
}


template<
	class T,
	Uint8 index0,
	Uint8 index1,
	Uint8 index2>
inline Vector3DComponent<T, index0, index1, index2>::operator typename ComponentMapper3D<T, index0, index1, index2>::Type3DRef()
{
	return ComponentMapper3D<T, index0, index1, index2>::Map(components);
}


template<
	class T,
	Uint8 index0,
	Uint8 index1,
	Uint8 index2>
inline Vector3DComponent<T, index0, index1, index2>&
Vector3DComponent<T, index0, index1, index2>::operator=(
	Type3DCRef aggregate)
{
	components[index0] = aggregate.x;
	components[index1] = aggregate.y;
	components[index2] = aggregate.z;
	return (*this);
}


template<
	class T,
	Uint8 index0,
	Uint8 index1,
	Uint8 index2>
inline Vector3DComponent<T, index0, index1, index2>&
Vector3DComponent<T, index0, index1, index2>::operator=(
	Type3DRRef aggregate)
{
	components[index0] = aggregate.x;
	components[index1] = aggregate.y;
	components[index2] = aggregate.z;
	return (*this);
}


template<
	class T, 
	Uint8 index0, 
	Uint8 index1, 
	Uint8 index2>
template<
	Uint8 otherIndex0, 
	Uint8 otherIndex1, 
	Uint8 otherIndex2>
inline Vector3DComponent<T, index0, index1, index2>& 
Vector3DComponent<T, index0, index1, index2>::operator=(
	Vector3DComponent<T, otherIndex0, otherIndex1, otherIndex2> const & other)
{
	components[index0] = other.components[otherIndex0];
	components[index1] = other.components[otherIndex1];
	components[index2] = other.components[otherIndex2];
	return (*this);
}




template<
	class T,
	Uint8 index0,
	Uint8 index1,
	Uint8 index2,
	Uint8 index3>
struct Vector4DComponent
{
	using ComponentType = typename T::Type;
	using Type4D = typename T::Type4D;
	using Type4DRef = std::add_lvalue_reference_t<Type4D>;
	using Type4DCRef = std::add_lvalue_reference_t<Type4D const>;
	using Type4DRRef = std::add_rvalue_reference_t<Type4D>;

	inline Vector4DComponent() = default;
	inline ~Vector4DComponent() = default;

	inline Vector4DComponent(ComponentType const value0, ComponentType const value1, ComponentType const value2, ComponentType const value3);
	inline Vector4DComponent(ComponentType const value);

	inline operator typename ComponentMapper4D<T, index0, index1, index2, index3>::Type4DRef();


	inline Vector4DComponent& operator=(Type4DCRef aggregate);
	inline Vector4DComponent& operator=(Type4DRRef aggregate);


	template<Uint8 otherIndex0, Uint8 otherIndex1, Uint8 otherIndex2, Uint8 otherIndex3>
	inline Vector4DComponent& operator=(Vector4DComponent<T, otherIndex0, otherIndex1, otherIndex2, otherIndex3> const& other);


	ComponentType	components[4];
};


template<
	class T, 
	Uint8 index0, 
	Uint8 index1, 
	Uint8 index2, 
	Uint8 index3>
inline 
Vector4DComponent<T, index0, index1, index2, index3>::Vector4DComponent(
	ComponentType const value0, 
	ComponentType const value1, 
	ComponentType const value2, 
	ComponentType const value3)
{
	components[index0] = value0;
	components[index1] = value1;
	components[index2] = value2;
	components[index3] = value3;
}


template<
	class T,
	Uint8 index0,
	Uint8 index1,
	Uint8 index2,
	Uint8 index3>
inline 
Vector4DComponent<T, index0, index1, index2, index3>::Vector4DComponent(
	ComponentType const value)
{
	components[index0] = value;
	components[index1] = value;
	components[index2] = value;
	components[index3] = value;
}


template<
	class T,
	Uint8 index0,
	Uint8 index1,
	Uint8 index2,
	Uint8 index3>
inline Vector4DComponent<T, index0, index1, index2, index3>::operator typename 
ComponentMapper4D<T, index0, index1, index2, index3>::Type4DRef()
{
	return ComponentMapper4D<T, index0, index1, index2, index3>::Map(components);
}


template<
	class T,
	Uint8 index0,
	Uint8 index1,
	Uint8 index2,
	Uint8 index3>
inline Vector4DComponent<T, index0, index1, index2, index3>&
Vector4DComponent<T, index0, index1, index2, index3>::operator=(
	Type4DCRef aggregate)
{
	components[index0] = aggregate.x;
	components[index1] = aggregate.y;
	components[index2] = aggregate.z;
	components[index3] = aggregate.w;
	return (*this);
}


template<
	class T,
	Uint8 index0,
	Uint8 index1,
	Uint8 index2,
	Uint8 index3>
inline Vector4DComponent<T, index0, index1, index2, index3>&
Vector4DComponent<T, index0, index1, index2, index3>::operator=(
	Type4DRRef aggregate)
{
	components[index0] = aggregate.x;
	components[index1] = aggregate.y;
	components[index2] = aggregate.z;
	components[index3] = aggregate.w;
	return (*this);
}


template<
	class T,
	Uint8 index0,
	Uint8 index1,
	Uint8 index2,
	Uint8 index3>
template<
	Uint8 otherIndex0, 
	Uint8 otherIndex1, 
	Uint8 otherIndex2, 
	Uint8 otherIndex3>
inline Vector4DComponent<T, index0, index1, index2, index3>& 
Vector4DComponent<T, index0, index1, index2, index3>::operator=(
	Vector4DComponent<T, otherIndex0, otherIndex1, otherIndex2, otherIndex3> const& other)
{
	components[index0] = other.components[otherIndex0];
	components[index1] = other.components[otherIndex1];
	components[index2] = other.components[otherIndex2];
	components[index3] = other.components[otherIndex3];
	return (*this);
}

}