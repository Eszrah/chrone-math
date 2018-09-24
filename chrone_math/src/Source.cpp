#include "algebra/Vector.h"
#include "algebra/Matrix.h"

using namespace chrone::math;

int main()
{
	using Vector2DFData = Vector2DMapData<float>;
	using Vector3DFData = Vector3DMapData<float>;

	//Vector1DComponent<Vector2DFData, 0>	vector20{ Vector1DComponent<Vector2DFData, 0>{1} };
	Vector2D<Vector2DFData>	vector20{};
	Vector2D<Vector2DFData>	vector21{};
	//Vector1DComponent<Vector2DFData, 0> comp0;
	//Vector1DComponent<Vector2DFData, 0> comp1;

	//vector20 = Vector2D<Vector2DFData>(0, 1);
	//vector2.y = 1;

	//vector20.x = ;

	vector20.x = 1;
	vector20.y = 0;
	vector21.yx = vector20.xy;
	vector21.xy = vector20.xy;
	vector21.xy = {};
	vector21.xy = vector20;
	vector21.yx = Vector2DComponent<Vector2DFData, 0, 1>{};

	vector21 = vector20.yx;
	vector21 = Vector2D<Vector2DFData>{1, 1};

	auto sum = vector20 + vector21;
	auto diff = vector20 - vector21;

	Vector3DDec32	vec3{};
	Vector3DDec32	vec3_1{};

	//vec3 = vec3_1.xyz;
	vec3_1 = Vector3DComponent<Vector3DFData, 0, 1, 2>{0, 1, 1};

	//Vector3DComponent<Vector3DFData, 0, 1, 2> test = vec3_1.xyz;

	vec3.xyz = {};
	vec3.xyz = {0, 1, 2};

	Matrix3x3Dec32	mat0;

	vec3.xyz = Vector3DComponent<Vector3DFData, 0, 1, 2>{};
	mat0.c0 = Vector3DDec32{ 1, 0, 1 };

	////Vector3DComponent<Vector3DFData, 0, 1, 2> top = mat0.c1;
	Vector3DDec32 c1 = mat0.c1;

	Vector3DDec32 c1Test0 = Vector3DComponent<Vector3DFData, 0, 1, 2>{ 0, 1, 1 };
	Vector3DDec32 c1Test1 = Vector3DComponent<Vector3DFData, 3, 4, 5>{ 0, 1, 1 };

	//mat0.c1 = Vector3DDec32{ 1, 1, 1 };
	//mat0.r0 = mat0.c0;
	//mat0.c0 = Vector3DComponent<Vector3DFData, 0, 1, 2>{};
	Vector3DDec32	column{ 1, 0, 0 };
	Vector3DDec32	column2{ 1, 0, 0 };

	Matrix3x3Dec32	mat1{ column , column , column };

	mat1.matrix = mat1.transpose;
	mat1 = mat1.matrix;

	Matrix3x3Component<Matrix3x3MapDataDec32, 0, 1, 2, 3, 4, 5, 6, 7, 8>	matrix{};
	Matrix3x3Component<Matrix3x3MapDataDec32, 0, 1, 2, 3, 4, 5, 6, 7, 8>	matrix1{};
	Matrix3x3Component<Matrix3x3MapDataDec32, 0, 3, 6, 1, 4, 7, 2, 5, 8>	transpose{};

	matrix = matrix1;

	transpose = matrix;

	{
		Matrix3x3Dec32	matrix3x3_0;
		Matrix3x3Dec32	matrix3x3_1;

		matrix3x3_1.m00 = matrix3x3_0.m22;
		matrix3x3_1.transpose = matrix3x3_0.matrix;
		matrix3x3_1.matrix = matrix3x3_0.matrix;
		matrix3x3_1.matrix = matrix3x3_0.transpose;
		matrix3x3_1.transpose = matrix3x3_0.transpose;

		matrix3x3_1.c0 = matrix3x3_0.c1;
	}

	{
		Vector3DDec32	column0_3x3{};
		Vector3DDec32	column1_3x3{};
		Vector4DDec32	column0{};
		Vector4DDec32	column1{  };

		column0 = column1;
		//column0 = column0_3x3.xyz;
		column1_3x3 = column0_3x3.xyz;
		Vector4DDec32	column2{ column1_3x3 };


		Matrix4x4Dec32	matrix4x4_0;
		Matrix4x4Dec32	matrix4x4_1;

		matrix4x4_1.m00 = matrix4x4_0.m33;
		matrix4x4_1.transpose = matrix4x4_0.matrix;
		matrix4x4_1.matrix = matrix4x4_0.matrix;
		matrix4x4_1.matrix = matrix4x4_0.transpose;
		matrix4x4_1.transpose = matrix4x4_0.transpose;

		matrix4x4_1.c0 = matrix4x4_0.c1;
	}


	return 0;
}