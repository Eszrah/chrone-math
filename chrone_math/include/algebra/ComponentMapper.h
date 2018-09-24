#pragma once

#include "NativeType.h"
#include <type_traits>

namespace chrone::math
{

template<
	class T,
	Uint8 index0>
struct ComponentMapper1D
{
	using ComponentType = typename T::Type;
	using AggregateTypeRef = std::add_lvalue_reference_t<ComponentType>;
	using AggregateTypeCRef = std::add_lvalue_reference_t<ComponentType const>;

	inline static AggregateTypeRef 
		Map(ComponentType* data)
	{
		return reinterpret_cast<AggregateTypeRef>(data[index0]);
	}

};


template<
	class T, 
	Uint8 index0, 
	Uint8 index1>
struct ComponentMapper2D final
{
	using ComponentType = typename T::Type;
	using Type2D = typename T::Type2D;
	using Type2DRef = Type2D;

	static Type2DRef
		Map(ComponentType* data)
	{
		return Type2DRef{ data[index0], data[index1] };
	}
	
};


template<class T>
struct ComponentMapper2D<T, 0, 1> final
{
	using ComponentType = typename T::Type;
	using Type2D = typename T::Type2D;
	using Type2DRef = std::add_lvalue_reference_t<Type2D>;
	using Type2DCRef = std::add_lvalue_reference_t<Type2D const>;


	static Type2DRef
		Map(ComponentType* data)
	{
		return reinterpret_cast<Type2DRef>(data[0]);
	}

};


template<class T>
struct ComponentMapper2D<T, 1, 2> final
{
	using ComponentType = typename T::Type;
	using Type2D = typename T::Type2D;
	using Type2DRef = std::add_lvalue_reference_t<Type2D>;
	using Type2DCRef = std::add_lvalue_reference_t<Type2D const>;


	static Type2DRef
		Map(ComponentType* data)
	{
		return reinterpret_cast<Type2DRef>(data[1]);
	}

};


template<class T>
struct ComponentMapper2D<T, 2, 3> final
{
	using ComponentType = typename T::Type;
	using Type2D = typename T::Type2D;
	using Type2DRef = std::add_lvalue_reference_t<Type2D>;
	using Type2DCRef = std::add_lvalue_reference_t<Type2D const>;


	static Type2DRef
		Map(ComponentType* data)
	{
		return reinterpret_cast<Type2DRef>(data[2]);
	}

};


template<
	class T,
	Uint8 index0,
	Uint8 index1,
	Uint8 index2>
struct ComponentMapper3D final
{
	using ComponentType = typename T::Type;
	using Type3D = typename T::Type3D;
	using Type3DRef = Type3D;


	static Type3DRef
		Map(ComponentType* data)
	{
		return Type3DRef{ data[index0], data[index1], data[index2] };
	}

};


template<class T>
struct ComponentMapper3D<T, 0, 1, 2> final
{
	using ComponentType = typename T::Type;
	using Type3D = typename T::Type3D;
	using Type3DRef = std::add_lvalue_reference_t<Type3D>;


	static Type3DRef
		Map(ComponentType* data)
	{
		return reinterpret_cast<Type3DRef>(data[0]);
	}

};


template<class T>
struct ComponentMapper3D<T, 1, 2, 3> final
{
	using ComponentType = typename T::Type;
	using Type3D = typename T::Type3D;
	using Type3DRef = std::add_lvalue_reference_t<Type3D>;


	static Type3DRef
		Map(ComponentType* data)
	{
		return reinterpret_cast<Type3DRef>(data[1]);
	}

};


template<
	class T,
	Uint8 index0,
	Uint8 index1,
	Uint8 index2,
	Uint8 index3>
	struct ComponentMapper4D final
{
	using ComponentType = typename T::Type;
	using Type4D = typename T::Type4D;
	using Type4DRef = Type4D;


	static Type4DRef
		Map(ComponentType* data)
	{
		return Type4DRef{ data[index0], data[index1], data[index2], data[index3] };
	}

};


template<class T>
struct ComponentMapper4D<T, 0, 1, 2, 3> final
{
	using ComponentType = typename T::Type;
	using Type4D = typename T::Type4D;
	using Type4DRef = std::add_lvalue_reference_t<Type4D>;


	static Type4DRef
		Map(ComponentType* data)
	{
		return reinterpret_cast<Type4DRef>(data[0]);
	}

};





template<
	class T,
	Uint8 m00Index, Uint8 m10Index, Uint8 m20Index,
	Uint8 m01Index, Uint8 m11Index, Uint8 m21Index,
	Uint8 m02Index, Uint8 m12Index, Uint8 m22Index>
struct Matrix3x3Mapper final
{
	using ComponentType = typename T::Type;
	using TypeMatrix3x3 = typename T::TypeMatrix3x3;
	using TypeMatrix3x3Ref = TypeMatrix3x3;

	using TypeVector3D = typename T::TypeVector3D;

	static TypeMatrix3x3Ref
		Map(ComponentType* data)
	{
		return TypeMatrix3x3Ref{ 
			TypeVector3D{data[m00Index], data[m10Index], data[m20Index]},
			TypeVector3D{data[m01Index], data[m11Index], data[m21Index]},
			TypeVector3D{data[m02Index], data[m12Index], data[m22Index]} };
	}
};


template<class T>
struct Matrix3x3Mapper<T, 0, 1, 2, 3, 4, 5, 6, 7, 8> final
{
	using ComponentType = typename T::Type;
	using TypeMatrix3x3 = typename T::TypeMatrix3x3;
	using TypeMatrix3x3Ref = std::add_lvalue_reference_t<TypeMatrix3x3>;

	static TypeMatrix3x3Ref
		Map(ComponentType* data)
	{
		return reinterpret_cast<TypeMatrix3x3Ref>(data[0]);
	}
};


template<
	class T,
	Uint8 m00Index, Uint8 m10Index, Uint8 m20Index, Uint8 m30Index,
	Uint8 m01Index, Uint8 m11Index, Uint8 m21Index, Uint8 m31Index,
	Uint8 m02Index, Uint8 m12Index, Uint8 m22Index, Uint8 m32Index,
	Uint8 m03Index, Uint8 m13Index, Uint8 m23Index, Uint8 m33Index >
struct Matrix4x4Mapper final
{
	using ComponentType = typename T::Type;
	using TypeMatrix4x4 = typename T::TypeMatrix4x4;
	using TypeMatrix4x4Ref = TypeMatrix4x4;

	using TypeVector4D = typename T::TypeVector4D;

	static TypeMatrix4x4Ref
		Map(ComponentType* data)
	{
		return TypeMatrix4x4Ref{
			TypeVector4D(data[m00Index], data[m10Index], data[m20Index],
			data[m30Index]),
			TypeVector4D(data[m01Index], data[m11Index], data[m21Index],
			data[m31Index]),
			TypeVector4D(data[m02Index], data[m12Index], data[m22Index],
			data[m32Index]),
			TypeVector4D(data[m03Index], data[m13Index], data[m23Index],
			data[m33Index]),
		};
	}
};


template<
	class T>
struct Matrix4x4Mapper<
	T, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> final
{
	using ComponentType = typename T::Type;
	using TypeMatrix4x4 = typename T::TypeMatrix4x4;
	using TypeMatrix4x4Ref = std::add_lvalue_reference_t <TypeMatrix4x4>;

	using TypeVector4D = typename T::TypeVector4D;

	static TypeMatrix4x4Ref
		Map(ComponentType* data)
	{
		return TypeMatrix4x4Ref{
			reinterpret_cast<TypeMatrix4x4Ref>(data[0])};
	}
};
}
