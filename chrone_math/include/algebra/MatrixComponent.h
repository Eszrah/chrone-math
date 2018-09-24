#pragma once

#include "NativeType.h"
#include "VectorComponent.h"

#include <cstring>

namespace chrone::math
{

template<
	class T,
	Uint8 m00Index, Uint8 m10Index, Uint8 m20Index,
	Uint8 m01Index, Uint8 m11Index, Uint8 m21Index,
	Uint8 m02Index, Uint8 m12Index, Uint8 m22Index>
struct Matrix3x3Component 
{
	using ComponentType = typename T::Type;
	using TypeMatrix3x3 = typename T::TypeMatrix3x3;
	using TypeMatrix3x3Ref = std::add_lvalue_reference_t<TypeMatrix3x3>;
	using TypeMatrix3x3CRef = std::add_lvalue_reference_t<TypeMatrix3x3 const>;
	using TypeMatrix3x3RRef = std::add_rvalue_reference_t<TypeMatrix3x3>;

	using TypeVector3D = typename T::TypeVector3D;
	using TypeVector3DRef = std::add_lvalue_reference_t<TypeVector3D>;
	using TypeVector3DCRef = std::add_lvalue_reference_t<TypeVector3D const>;
	using TypeVector3DRRef = std::add_rvalue_reference_t<TypeVector3D>;
	static constexpr auto	Vector3DSize{ sizeof(TypeVector3D) };

	inline Matrix3x3Component() = default;
	inline ~Matrix3x3Component() = default;

	inline Matrix3x3Component(ComponentType const m00, ComponentType const m10, ComponentType const m20, 
		ComponentType const m01, ComponentType const m11, ComponentType const m21,
		ComponentType const m02, ComponentType const m12, ComponentType const m22);

	inline Matrix3x3Component(TypeVector3DCRef col0, TypeVector3DCRef col1, TypeVector3DCRef col2);

	inline operator typename Matrix3x3Mapper<T,
		m00Index, m10Index, m20Index,
		m01Index, m11Index, m21Index,
		m02Index, m12Index, m22Index>::TypeMatrix3x3Ref();


	inline Matrix3x3Component& operator=(TypeMatrix3x3CRef aggregate);

	template<
		Uint8 otherM00Index, Uint8 otherM10Index, Uint8 otherM20Index,
		Uint8 otherM01Index, Uint8 otherM11Index, Uint8 otherM21Index,
		Uint8 otherM02Index, Uint8 otherM12Index, Uint8 otherM22Index>
	inline Matrix3x3Component& operator=(
		Matrix3x3Component<T, otherM00Index, otherM10Index, otherM20Index,
		otherM01Index, otherM11Index, otherM21Index,
		otherM02Index, otherM12Index, otherM22Index> const& other);

	ComponentType	components[9];
};



template<
	class T,
	Uint8 m00Index, Uint8 m10Index, Uint8 m20Index,
	Uint8 m01Index, Uint8 m11Index, Uint8 m21Index,
	Uint8 m02Index, Uint8 m12Index, Uint8 m22Index>
inline Matrix3x3Component<T, 
	m00Index, m10Index, m20Index, 
	m01Index, m11Index, m21Index, 
	m02Index, m12Index, m22Index>::Matrix3x3Component(
		ComponentType const m00, ComponentType const m10, 
		ComponentType const m20, ComponentType const m01, 
		ComponentType const m11, ComponentType const m21, 
		ComponentType const m02, ComponentType const m12, 
		ComponentType const m22):
	components{ m00, m10, m20, m01, m11, m21, m02, m12, m22 }
{
}


template<
	class T,
	Uint8 m00Index, Uint8 m10Index, Uint8 m20Index,
	Uint8 m01Index, Uint8 m11Index, Uint8 m21Index,
	Uint8 m02Index, Uint8 m12Index, Uint8 m22Index>
inline Matrix3x3Component<T,
	m00Index, m10Index, m20Index,
	m01Index, m11Index, m21Index,
	m02Index, m12Index, m22Index>::Matrix3x3Component(
	TypeVector3DCRef col0, 
	TypeVector3DCRef col1, 
	TypeVector3DCRef col2)
{
	std::memcpy(components, std::addressof(col0), Vector3DSize);
	std::memcpy(components + 3, std::addressof(col1), Vector3DSize);
	std::memcpy(components + 6, std::addressof(col2), Vector3DSize);
}


template<
	class T,
	Uint8 m00Index, Uint8 m10Index, Uint8 m20Index,
	Uint8 m01Index, Uint8 m11Index, Uint8 m21Index,
	Uint8 m02Index, Uint8 m12Index, Uint8 m22Index>
inline Matrix3x3Component<T, 
	m00Index, m10Index, m20Index, 
	m01Index, m11Index, m21Index, 
	m02Index, m12Index, m22Index>::operator 
	typename Matrix3x3Mapper<T, 
	m00Index, m10Index, m20Index, 
	m01Index, m11Index, m21Index, 
	m02Index, m12Index, m22Index>::TypeMatrix3x3Ref()
{
	return Matrix3x3Mapper<T,
		m00Index, m10Index, m20Index,
		m01Index, m11Index, m21Index,
		m02Index, m12Index, m22Index>::Map(components);
}


template<
	class T,
	Uint8 m00Index, Uint8 m10Index, Uint8 m20Index,
	Uint8 m01Index, Uint8 m11Index, Uint8 m21Index,
	Uint8 m02Index, Uint8 m12Index, Uint8 m22Index>
inline Matrix3x3Component <T,
	m00Index, m10Index, m20Index,
	m01Index, m11Index, m21Index,
	m02Index, m12Index, m22Index>&
Matrix3x3Component<T,
	m00Index, m10Index, m20Index,
	m01Index, m11Index, m21Index,
	m02Index, m12Index, m22Index>::operator=(typename Matrix3x3Component<T,
		m00Index, m10Index, m20Index,
		m01Index, m11Index, m21Index,
		m02Index, m12Index, m22Index>::TypeMatrix3x3CRef aggregate)
{
	std::memcpy(components, std::addressof(aggregate), sizeof(decltype(*this)));
	return (*this);
}


template<
	class T,
	Uint8 m00Index, Uint8 m10Index, Uint8 m20Index,
	Uint8 m01Index, Uint8 m11Index, Uint8 m21Index,
	Uint8 m02Index, Uint8 m12Index, Uint8 m22Index>
template<
	Uint8 otherM00Index, Uint8 otherM10Index, Uint8 otherM20Index, 
	Uint8 otherM01Index, Uint8 otherM11Index, Uint8 otherM21Index, 
	Uint8 otherM02Index, Uint8 otherM12Index, Uint8 otherM22Index>
inline Matrix3x3Component <T,
	m00Index, m10Index, m20Index,
	m01Index, m11Index, m21Index,
	m02Index, m12Index, m22Index>& 
Matrix3x3Component<T, 
	m00Index, m10Index, m20Index, 
	m01Index, m11Index, m21Index, 
	m02Index, m12Index, m22Index>::operator=(Matrix3x3Component<T, otherM00Index, otherM10Index, otherM20Index, otherM01Index, otherM11Index, otherM21Index, otherM02Index, otherM12Index, otherM22Index> const & other)
{
	components[m00Index] = other.components[otherM00Index];
	components[m10Index] = other.components[otherM10Index];
	components[m20Index] = other.components[otherM20Index];

	components[m01Index] = other.components[otherM01Index];
	components[m11Index] = other.components[otherM11Index];
	components[m21Index] = other.components[otherM21Index];
	
	components[m02Index] = other.components[otherM02Index];
	components[m12Index] = other.components[otherM12Index];
	components[m22Index] = other.components[otherM22Index];
	return (*this);
}






template<
	class T,
	Uint8 m00Index, Uint8 m10Index, Uint8 m20Index, Uint8 m30Index,
	Uint8 m01Index, Uint8 m11Index, Uint8 m21Index, Uint8 m31Index,
	Uint8 m02Index, Uint8 m12Index, Uint8 m22Index, Uint8 m32Index,
	Uint8 m03Index, Uint8 m13Index, Uint8 m23Index, Uint8 m33Index>
struct Matrix4x4Component
{
	using ComponentType = typename T::Type;
	using TypeMatrix4x4 = typename T::TypeMatrix4x4;
	using TypeMatrix4x4Ref = std::add_lvalue_reference_t<TypeMatrix4x4>;
	using TypeMatrix4x4CRef = std::add_lvalue_reference_t<TypeMatrix4x4 const>;
	using TypeMatrix4x4RRef = std::add_rvalue_reference_t<TypeMatrix4x4>;

	using TypeVector3D = typename T::TypeVector3D;
	using TypeVector3DRef = std::add_lvalue_reference_t<TypeVector3D>;
	using TypeVector3DCRef = std::add_lvalue_reference_t<TypeVector3D const>;
	using TypeVector3DRRef = std::add_rvalue_reference_t<TypeVector3D>;
	static constexpr auto	Vector3DSize{ sizeof(TypeVector3D) };

	using TypeVector4D = typename T::TypeVector4D;
	using TypeVector4DRef = std::add_lvalue_reference_t<TypeVector4D>;
	using TypeVector4DCRef = std::add_lvalue_reference_t<TypeVector4D const>;
	using TypeVector4DRRef = std::add_rvalue_reference_t<TypeVector4D>;
	static constexpr auto	Vector4DSize{ sizeof(TypeVector4D) };

	inline Matrix4x4Component() = default;
	inline ~Matrix4x4Component() = default;

	inline Matrix4x4Component(
		ComponentType const m00, ComponentType const m10, 
		ComponentType const m20, ComponentType const m30,
		ComponentType const m01, ComponentType const m11, 
		ComponentType const m21, ComponentType const m31,
		ComponentType const m02, ComponentType const m12, 
		ComponentType const m22, ComponentType const m32,
		ComponentType const m03, ComponentType const m131, 
		ComponentType const m23, ComponentType const m331);

	inline Matrix4x4Component(TypeVector4DCRef col0, TypeVector4DCRef col1, 
		TypeVector4DCRef col2, TypeVector4DCRef col3);
	
	inline operator typename Matrix4x4Mapper<T,
		m00Index, m10Index, m20Index, m30Index,
		m01Index, m11Index, m21Index, m31Index,
		m02Index, m12Index, m22Index, m32Index,
		m03Index, m13Index, m23Index, m33Index>::TypeMatrix4x4Ref();

	inline Matrix4x4Component& operator=(TypeMatrix4x4CRef aggregate);

	template<
		Uint8 otherM00Index, Uint8 otherM10Index, Uint8 otherM20Index, Uint8 otherM30Index,
		Uint8 otherM01Index, Uint8 otherM11Index, Uint8 otherM21Index, Uint8 otherM31Index,
		Uint8 otherM02Index, Uint8 otherM12Index, Uint8 otherM22Index, Uint8 otherM32Index,
		Uint8 otherM03Index, Uint8 otherM13Index, Uint8 otherM23Index, Uint8 otherM33Index>
		inline Matrix4x4Component& operator=(
			Matrix4x4Component<T, otherM00Index, otherM10Index, otherM20Index, otherM30Index,
			otherM01Index, otherM11Index, otherM21Index, otherM31Index,
			otherM02Index, otherM12Index, otherM22Index, otherM32Index,
			otherM03Index, otherM13Index, otherM23Index, otherM33Index> const& other);


	ComponentType	components[16];
};


template<
	class T,
	Uint8 m00Index, Uint8 m10Index, Uint8 m20Index, Uint8 m30Index,
	Uint8 m01Index, Uint8 m11Index, Uint8 m21Index, Uint8 m31Index,
	Uint8 m02Index, Uint8 m12Index, Uint8 m22Index, Uint8 m32Index,
	Uint8 m03Index, Uint8 m13Index, Uint8 m23Index, Uint8 m33Index>
inline Matrix4x4Component<
	T,
	m00Index, m10Index, m20Index, m30Index,
	m01Index, m11Index, m21Index, m31Index, 
	m02Index, m12Index, m22Index, m32Index, 
	m03Index, m13Index, m23Index, m33Index>::Matrix4x4Component(
		ComponentType const m00, ComponentType const m10, 
		ComponentType const m20, ComponentType const m30, 
		ComponentType const m01, ComponentType const m11, 
		ComponentType const m21, ComponentType const m31, 
		ComponentType const m02, ComponentType const m12, 
		ComponentType const m22, ComponentType const m32, 
		ComponentType const m03, ComponentType const m13, 
		ComponentType const m23, ComponentType const m33):
	components{ m00, m10, m20, m30, m01, m11, m21, m31, 
	m02, m12, m22, m32, m03, m13, m23, m33 }

{
}


template<
	class T,
	Uint8 m00Index, Uint8 m10Index, Uint8 m20Index, Uint8 m30Index,
	Uint8 m01Index, Uint8 m11Index, Uint8 m21Index, Uint8 m31Index,
	Uint8 m02Index, Uint8 m12Index, Uint8 m22Index, Uint8 m32Index,
	Uint8 m03Index, Uint8 m13Index, Uint8 m23Index, Uint8 m33Index>
inline Matrix4x4Component<
	T,
	m00Index, m10Index, m20Index, m30Index,
	m01Index, m11Index, m21Index,
	m31Index, m02Index, m12Index,
	m22Index, m32Index, m03Index,
	m13Index, m23Index, m33Index>::Matrix4x4Component(
		TypeVector4DCRef col0, TypeVector4DCRef col1, 
		TypeVector4DCRef col2, TypeVector4DCRef col3)
{
	std::memcpy(components, std::addressof(col0), Vector4DSize);
	std::memcpy(components + 4, std::addressof(col1), Vector4DSize);
	std::memcpy(components + 8, std::addressof(col2), Vector4DSize);
	std::memcpy(components + 12, std::addressof(col3), Vector4DSize);
}


template<
	class T,
	Uint8 m00Index, Uint8 m10Index, Uint8 m20Index, Uint8 m30Index,
	Uint8 m01Index, Uint8 m11Index, Uint8 m21Index, Uint8 m31Index,
	Uint8 m02Index, Uint8 m12Index, Uint8 m22Index, Uint8 m32Index,
	Uint8 m03Index, Uint8 m13Index, Uint8 m23Index, Uint8 m33Index>
inline Matrix4x4Component<
	T,
	m00Index, m10Index, m20Index, m30Index,
	m01Index, m11Index, m21Index, m31Index, 
	m02Index, m12Index, m22Index, m32Index, 
	m03Index, m13Index, m23Index, m33Index>::operator typename 
	Matrix4x4Mapper<T, 
	m00Index, m10Index, m20Index, m30Index, 
	m01Index, m11Index, m21Index, m31Index, 
	m02Index, m12Index, m22Index, m32Index, 
	m03Index, m13Index, m23Index, m33Index>::TypeMatrix4x4Ref()
{
	return Matrix4x4Mapper<T,
		m00Index, m10Index, m20Index, m30Index,
		m01Index, m11Index, m21Index, m31Index,
		m02Index, m12Index, m22Index, m32Index,
		m03Index, m13Index, m23Index, m33Index>::Map(components);
}


template<
	class T,
	Uint8 m00Index, Uint8 m10Index, Uint8 m20Index, Uint8 m30Index,
	Uint8 m01Index, Uint8 m11Index, Uint8 m21Index, Uint8 m31Index,
	Uint8 m02Index, Uint8 m12Index, Uint8 m22Index, Uint8 m32Index,
	Uint8 m03Index, Uint8 m13Index, Uint8 m23Index, Uint8 m33Index>
inline Matrix4x4Component<
	T,
	m00Index, m10Index, m20Index, m30Index,
	m01Index, m11Index, m21Index, m31Index, 
	m02Index, m12Index, m22Index, m32Index, 
	m03Index, m13Index, m23Index, m33Index>& Matrix4x4Component<
	T,
	m00Index, m10Index, m20Index, m30Index,
	m01Index, m11Index, m21Index, m31Index,
	m02Index, m12Index, m22Index, m32Index,
	m03Index, m13Index, m23Index, m33Index>::operator=(TypeMatrix4x4CRef aggregate)
{
	// TODO: insert return statement here
	std::memcpy(components, std::addressof(aggregate), sizeof(decltype(*this)));
	return (*this);
}


template<
	class T, 
	Uint8 m00Index, Uint8 m10Index, Uint8 m20Index, Uint8 m30Index, 
	Uint8 m01Index, Uint8 m11Index, Uint8 m21Index, Uint8 m31Index, 
	Uint8 m02Index, Uint8 m12Index, Uint8 m22Index, Uint8 m32Index, 
	Uint8 m03Index, Uint8 m13Index, Uint8 m23Index, Uint8 m33Index>
template<
	Uint8 otherM00Index, Uint8 otherM10Index, 
	Uint8 otherM20Index, Uint8 otherM30Index, 
	Uint8 otherM01Index, Uint8 otherM11Index, 
	Uint8 otherM21Index, Uint8 otherM31Index, 
	Uint8 otherM02Index, Uint8 otherM12Index, 
	Uint8 otherM22Index, Uint8 otherM32Index, 
	Uint8 otherM03Index, Uint8 otherM13Index, 
	Uint8 otherM23Index, Uint8 otherM33Index>
inline Matrix4x4Component<
	T,
	m00Index, m10Index, m20Index, m30Index,
	m01Index, m11Index, m21Index, m31Index, 
	m02Index, m12Index, m22Index, m32Index, 
	m03Index, m13Index, m23Index, m33Index>& Matrix4x4Component<
	T,
	m00Index, m10Index, m20Index, m30Index,
	m01Index, m11Index, m21Index, m31Index,
	m02Index, m12Index, m22Index, m32Index,
	m03Index, m13Index, m23Index, m33Index>::operator=(
		Matrix4x4Component<T, 
		otherM00Index, otherM10Index, otherM20Index, otherM30Index, 
		otherM01Index, otherM11Index, otherM21Index, otherM31Index, 
		otherM02Index, otherM12Index, otherM22Index, otherM32Index, 
		otherM03Index, otherM13Index, otherM23Index, otherM33Index> const & other)
{
	components[m00Index] = other.components[otherM00Index];
	components[m10Index] = other.components[otherM10Index];
	components[m20Index] = other.components[otherM20Index];
	components[m30Index] = other.components[otherM30Index];

	components[m01Index] = other.components[otherM01Index];
	components[m11Index] = other.components[otherM11Index];
	components[m21Index] = other.components[otherM21Index];
	components[m31Index] = other.components[otherM31Index];

	components[m02Index] = other.components[otherM02Index];
	components[m12Index] = other.components[otherM12Index];
	components[m22Index] = other.components[otherM22Index];
	components[m32Index] = other.components[otherM32Index];

	components[m03Index] = other.components[otherM03Index];
	components[m13Index] = other.components[otherM13Index];
	components[m23Index] = other.components[otherM23Index];
	components[m33Index] = other.components[otherM33Index];

	return (*this);
}

}