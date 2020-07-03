#pragma once
#include "Vector3n.h"

namespace MathEng {
	class Matrix3n {
	
	private:

	public:
		// Holds 3x3 Matrix data
		float data[9] = { 0.0 };

		// Contructors
		Matrix3n();

		Matrix3n(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8);

		// Copy Constructor
		Matrix3n& operator=(const Matrix3n& mat);

		// Destructor
		~Matrix3n();

		// Print - Displays data in proper format
		void print();

		// Addition
		Matrix3n operator+(const Matrix3n& mat);

		void operator+=(const Matrix3n& mat);

		// Subtraction
		Matrix3n operator-(const Matrix3n& mat);

		void operator-=(const Matrix3n& mat);

		// Scalar Mutliplication
		Matrix3n operator*(const float num);

		void operator*=(const float num);

		// Matrix Multiplication
		Matrix3n operator*(const Matrix3n& mat);

		// Identitiy Matrix
		void setAsIdentityMatrix();

		// Inverse Matrix
		void setAsInverseOfGivenMatrix(const Matrix3n& mat);
		Matrix3n getInverseOfMatrix();
		void invertMatrix();

		// Transpose Matrix
		void setAsTransposeOfGivenMatrix(const Matrix3n& mat);
		Matrix3n getTransposeOfMatrix();
		void transposeMatrix();

		// Vector Transformation
		Vector3n operator*(const Vector3n & vec);

	};
}
