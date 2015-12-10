#include "Float4x4.h"
#include <iostream>
#include <math.h>

//TODO Add more functionality like scalar, lookAt and maybe more

const Float4x4 Float4x4::DEFAULT = Float4x4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

Float4x4::Float4x4() {
	*this = DEFAULT;
}

// Private helper constructor
Float4x4::Float4x4(float _00, float _01, float _02, float _03, 
				   float _10, float _11, float _12, float _13, 
				   float _20, float _21, float _22, float _23, 
				   float _30, float _31, float _32, float _33) {
	Float4x4 &A = *this;
	A.matrix[0][0] = _00;
	A.matrix[0][1] = _01;
	A.matrix[0][2] = _02;
	A.matrix[0][3] = _03;

	A.matrix[1][0] = _10;
	A.matrix[1][1] = _11;
	A.matrix[1][2] = _12;
	A.matrix[1][3] = _13;

	A.matrix[2][0] = _20;
	A.matrix[2][1] = _21;
	A.matrix[2][2] = _22;
	A.matrix[2][3] = _23;

	A.matrix[3][0] = _30;
	A.matrix[3][1] = _31;
	A.matrix[3][2] = _32;
	A.matrix[3][3] = _33;
}

void Float4x4::toConsole() {
	// Adding two newlines for better readability when printing many matrixes
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)	{
		for (int j = 0; j < 4; j++) {
			std::cout << this->matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


float& Float4x4::operator() (int row, int col) {
	return matrix[row][col];
}

float Float4x4::operator() (int row, int col) const {
	return matrix[row][col];
}

const Float4x4 Float4x4::operator +  (const Float4x4 &B) const {
	Float4x4 C;
	const Float4x4 &A = *this;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; i < 4; j++) {
			C.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
		}
	}
	return C;
}

const Float4x4 Float4x4::operator -  (const Float4x4 &B) const {
	Float4x4 C;
	const Float4x4 &A = *this;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; i < 4; j++) {
			C.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
		}
	}
	return C;
}

const Float4x4 Float4x4::operator * (const Float4x4 &B) const {
	Float4x4 C;
	const Float4x4 &A = *this;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
		{
			C.matrix[i][j] = A.matrix[i][0] * B.matrix[0][j]
						   + A.matrix[i][1] * B.matrix[1][j]
						   + A.matrix[i][2] * B.matrix[2][j]
						   + A.matrix[i][3] * B.matrix[3][j];
		}
	}
	return C;
}

void Float4x4::transpose() {
	Float4x4 transposed;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			transposed.matrix[i][j] = (*this).matrix[j][i];

	(*this) = transposed;
}

Float4x4 Float4x4::createIdentity() {
	return Float4x4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
}

Float4x4 Float4x4::createTransposedFrom(const Float4x4 &B) {
	Float4x4 transposed;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			transposed.matrix[i][j] = B.matrix[j][i];
		}
	}

	return transposed;
}

Float4x4 Float4x4::createTranslation(float x, float y, float z) {
	Float4x4 A = Float4x4::createIdentity();
	A.matrix[0][3] = x;
	A.matrix[1][3] = y;
	A.matrix[2][3] = z;
	return A;
}

Float4x4 Float4x4::createRotationX(float v) {
	return Float4x4	(
			1, 0, 0, 0,
			0, cos(v), sin(v), 0,
			0, -sin(v), cos(v), 0,
			0, 0, 0, 1
		);
}

Float4x4 Float4x4::createRotationY(float v) {
	return Float4x4	(
			cos(v), 0, -sin(v), 0,
			0, 1, 0, 0,
			sin(v), 0, cos(v), 0,
			0, 0, 0, 1
		);
}

Float4x4 Float4x4::createRotationZ(float v) {
	return Float4x4	(
			cos(v), sin(v), 0, 0,
			-sin(v), cos(v), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
}


Float4x4 Float4x4::createPerspective(float fov, float aspect, float near, float far)
{
	//TODO: Fix a better PI
	float angle = (fov / 180.0f) * 3.14;
	float f = 1.0f / tan(angle * 0.5f);

	return Float4x4	(
			f / aspect, 0, 0, 0,
			0, f, 0, 0,
			0, 0, (far + near) / (near - far), -1,
			0, 0, 2 * far * near / (near - far), 0
		);
}