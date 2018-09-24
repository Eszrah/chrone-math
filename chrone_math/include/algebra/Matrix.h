#pragma once

#include "NativeType.h"
#include "Vector.h"
#include "MatrixComponent.h"

namespace chrone::math
{

template<class T>
struct Matrix3x3
{
	using TypeComponentStruct = typename T::TypeComponentStruct;
	using TypeColumnStruct = typename T::TypeColumnStruct;

	using TypeVector3D = typename T::TypeVector3D;
	using TypeVector3DRef = std::add_lvalue_reference_t<TypeVector3D>;
	using TypeVector3DCRef = std::add_lvalue_reference_t<TypeVector3D const>;
	using TypeVector3DRRef = std::add_rvalue_reference_t<TypeVector3D const>;


	inline Matrix3x3() = default;
	inline Matrix3x3(Matrix3x3 const&) = default;
	inline Matrix3x3(Matrix3x3&&) = default;
	inline ~Matrix3x3() = default;

	inline Matrix3x3(TypeVector3DRef col0, TypeVector3DRef col1, TypeVector3DRef col2);

	inline Matrix3x3& operator=(Matrix3x3 const&) = default;
	inline Matrix3x3& operator=(Matrix3x3&&) = default;

	union
	{
		Vector1DComponent<TypeComponentStruct, 0>	m00;
		Vector1DComponent<TypeComponentStruct, 1>	m10;
		Vector1DComponent<TypeComponentStruct, 2>	m20;

		Vector1DComponent<TypeComponentStruct, 3>	m01;
		Vector1DComponent<TypeComponentStruct, 4>	m11;
		Vector1DComponent<TypeComponentStruct, 5>	m21;

		Vector1DComponent<TypeComponentStruct, 6>	m02;
		Vector1DComponent<TypeComponentStruct, 7>	m12;
		Vector1DComponent<TypeComponentStruct, 8>	m22;

		Vector3DComponent<TypeColumnStruct, 0, 1, 2> c0;
		Vector3DComponent<TypeColumnStruct, 3, 4, 5> c1;
		Vector3DComponent<TypeColumnStruct, 6, 7, 8> c2;

		Vector3DComponent<TypeColumnStruct, 0, 3, 6> r0;
		Vector3DComponent<TypeColumnStruct, 1, 4, 7> r1;
		Vector3DComponent<TypeColumnStruct, 2, 5, 8> r2;

		Matrix3x3Component<T, 0, 1, 2, 3, 4, 5, 6, 7, 8>	matrix;
		Matrix3x3Component<T, 0, 3, 6, 1, 4, 7, 2, 5, 8>	transpose;
	};
};


template<class T>
struct Matrix3x3MapData
{
	using Type = T;
	using TypeComponentStruct = Vector2DMapData<T>;
	using TypeColumnStruct = Vector3DMapData<T>;

	using TypeVector3D = Vector3D<Vector3DMapData<T>>;

	using TypeMatrix3x3 = Matrix3x3<Matrix3x3MapData>;
};

using Matrix3x3MapDataDec32 = Matrix3x3MapData<Decimal32>;
using Matrix3x3MapDataDec64 = Matrix3x3MapData<Decimal64>;
using Matrix3x3Dec32 = Matrix3x3<Matrix3x3MapDataDec32>;
using Matrix3x3Dec64 = Matrix3x3<Matrix3x3MapDataDec64>;


template<class T>
inline 
Matrix3x3<T>::Matrix3x3(
	TypeVector3DRef col0, 
	TypeVector3DRef col1, 
	TypeVector3DRef col2):
	matrix{ col0, col1, col2 }
{
}




template<class T>
struct Matrix4x4
{
	using TypeComponentStruct = typename T::TypeComponentStruct;
	using TypeColumn3DStruct = typename T::TypeColumn3DStruct;
	using TypeColumn4DStruct = typename T::TypeColumn4DStruct;
	using TypeMatrix3x3Struct = typename T::TypeMatrix3x3Struct;
	//using Vector4DTypeStruct = typename T::Type4D;

	using TypeVector3D = typename T::TypeVector3D;
	using TypeVector3DRef = std::add_lvalue_reference_t<TypeVector3D>;
	using TypeVector3DCRef = std::add_lvalue_reference_t<TypeVector3D const>;
	using TypeVector3DRRef = std::add_rvalue_reference_t<TypeVector3D const>;

	using TypeVector4D = typename T::TypeVector4D;
	using TypeVector4DRef = std::add_lvalue_reference_t<TypeVector4D>;
	using TypeVector4DCRef = std::add_lvalue_reference_t<TypeVector4D const>;
	using TypeVector4DRRef = std::add_rvalue_reference_t<TypeVector4D const>;

	inline Matrix4x4() = default;
	inline Matrix4x4(Matrix4x4 const&) = default;
	inline Matrix4x4(Matrix4x4&&) = default;
	inline ~Matrix4x4() = default;

	inline Matrix4x4(TypeVector4DCRef col0, TypeVector4DCRef col1, 
		TypeVector4DCRef col2, TypeVector4DCRef col3);

	inline Matrix4x4& operator=(Matrix4x4 const&) = default;
	inline Matrix4x4& operator=(Matrix4x4&&) = default;

	union
	{
		Vector1DComponent<TypeComponentStruct, 0>	m00;
		Vector1DComponent<TypeComponentStruct, 1>	m10;
		Vector1DComponent<TypeComponentStruct, 2>	m20;
		Vector1DComponent<TypeComponentStruct, 3>	m30;
		
		Vector1DComponent<TypeComponentStruct, 4>	m01;
		Vector1DComponent<TypeComponentStruct, 5>	m11;
		Vector1DComponent<TypeComponentStruct, 6>	m21;
		Vector1DComponent<TypeComponentStruct, 7>	m31;

		Vector1DComponent<TypeComponentStruct, 8>	m02;
		Vector1DComponent<TypeComponentStruct, 9>	m12;
		Vector1DComponent<TypeComponentStruct, 10>	m22;
		Vector1DComponent<TypeComponentStruct, 11>	m32;

		Vector1DComponent<TypeComponentStruct, 12>	m03;
		Vector1DComponent<TypeComponentStruct, 13>	m13;
		Vector1DComponent<TypeComponentStruct, 14>	m23;
		Vector1DComponent<TypeComponentStruct, 15>	m33;

		Vector4DComponent<TypeColumn4DStruct, 0, 1, 2, 3> c0;
		Vector4DComponent<TypeColumn4DStruct, 4, 5, 6, 7> c1;
		Vector4DComponent<TypeColumn4DStruct, 8, 9, 10, 11> c2;
		Vector4DComponent<TypeColumn4DStruct, 12, 13, 14, 15> c3;

		Vector4DComponent<TypeColumn4DStruct, 0, 4, 8, 12> r0;
		Vector4DComponent<TypeColumn4DStruct, 1, 5, 9, 13> r1;
		Vector4DComponent<TypeColumn4DStruct, 2, 6, 10, 14> r2;
		Vector4DComponent<TypeColumn4DStruct, 3, 7, 11, 15> r3;

		Matrix3x3Component<TypeMatrix3x3Struct, 0, 1, 2, 4, 5, 6, 8, 9, 10>	mat3x3;
		Matrix3x3Component<TypeMatrix3x3Struct, 0, 4, 8, 1, 5, 9, 2, 6, 10>	mat3x3Transpose;

		Matrix4x4Component<T, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> matrix;
		Matrix4x4Component<T, 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15>	transpose;
	};
};


template<class T>
inline 
Matrix4x4<T>::Matrix4x4(
	TypeVector4DCRef col0, TypeVector4DCRef col1, 
	TypeVector4DCRef col2, TypeVector4DCRef col3):
	matrix{ col0, col1, col2, col3 }
{
}


template<class T>
struct Matrix4x4MapData
{
	using Type = T;
	using Type4D = Vector4DMapData<T>;
	using TypeComponentStruct = Vector2DMapData<T>;
	using TypeColumn3DStruct = Vector3DMapData<T>;
	using TypeColumn4DStruct = Type4D;

	using TypeVector3D = Vector3D<TypeColumn3DStruct>;
	using TypeVector4D = Vector4D<TypeColumn4DStruct>;

	using TypeMatrix3x3Struct = Matrix3x3MapData<T>;
	using TypeMatrix4x4 = Matrix4x4<Matrix4x4MapData>;
};

using Matrix4x4MapDataDec32 = Matrix4x4MapData<Decimal32>;
using Matrix4x4MapDataDec64 = Matrix4x4MapData<Decimal64>;
using Matrix4x4Dec32 = Matrix4x4<Matrix4x4MapDataDec32>;
using Matrix4x4Dec64 = Matrix4x4<Matrix4x4MapDataDec64>;

}