#include "Matrix3n.h"
#include "Vector3n.h"
#include <iostream>

// Matrix Class Implementation
// This class will be useful for computing different forms of transformations on 3D opjects in virtual space

namespace MathEng {
	
	// Contructor implementations
	Matrix3n::Matrix3n() {
		// Column Major Format - OpenGL 
		//	0	3	6
		//	1	4	7
		//	2	5	8

		// Initialized as identity matrix by default
		for (int i = 0; i < 9; i++) {
			data[i] = 0.0f;
		}

		data[0] = 1.0f;
		data[4] = 1.0f;
		data[8] = 1.0f;
	}

	Matrix3n::Matrix3n(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8) {
		// Column Major Format - OpenGL 
		//	0	3	6
		//	1	4	7
		//	2	5	8

		data[0] = m0;
		data[1] = m1;
		data[2] = m2;
		
		data[3] = m3;
		data[4] = m4;
		data[5] = m5;

		data[6] = m6;
		data[7] = m7;
		data[8] = m8;
	}

	// Copy Constructor implementation
	Matrix3n& Matrix3n::operator=(const Matrix3n& mat) {

		for (int i = 0; i < 9; i++) {
			data[i] = mat.data[i];
		}

		return *this;
	}

	// Destructor implementation
	Matrix3n::~Matrix3n() {}

	// Print implementation
	void Matrix3n::print() {
		//	Display as:
		//	0	3	6
		//	1	4	7
		//	2	5	8
	
		std::cout << data[0] << "	" << data[3] << "	" << data[6] << std::endl;
		std::cout << data[1] << "	" << data[4] << "	" << data[7] << std::endl;
		std::cout << data[2] << "	" << data[5] << "	" << data[8] << std::endl;
		std::cout << std::endl;
	}

	// Addition implementation
	Matrix3n Matrix3n::operator+(const Matrix3n& mat) {
		Matrix3n m;

		m.data[0] = data[0] + mat.data[0];
		m.data[1] = data[1] + mat.data[1];
		m.data[2] = data[2] + mat.data[2];
		
		m.data[3] = data[3] + mat.data[3];
		m.data[4] = data[4] + mat.data[4];
		m.data[5] = data[5] + mat.data[5];

		m.data[6] = data[6] + mat.data[6];
		m.data[7] = data[7] + mat.data[7];
		m.data[8] = data[8] + mat.data[8];

		return m;
		
	}

	void Matrix3n::operator+=(const Matrix3n& mat) {
		data[0] += mat.data[0];
		data[1] += mat.data[1];
		data[2] += mat.data[2];
		
		data[3] += mat.data[3];
		data[4] += mat.data[4];
		data[5] += mat.data[5];

		data[6] += mat.data[6];
		data[7] += mat.data[7];
		data[8] += mat.data[8];
	}

	// Subtraction implementation
	Matrix3n Matrix3n::operator-(const Matrix3n& mat) {
		Matrix3n m;

		m.data[0] = data[0] - mat.data[0];
		m.data[1] = data[1] - mat.data[1];
		m.data[2] = data[2] - mat.data[2];

		m.data[3] = data[3] - mat.data[3];
		m.data[4] = data[4] - mat.data[4];
		m.data[5] = data[5] - mat.data[5];

		m.data[6] = data[6] - mat.data[6];
		m.data[7] = data[7] - mat.data[7];
		m.data[8] = data[8] - mat.data[8];

		return m;
	}

	void Matrix3n::operator-=(const Matrix3n& mat) {
		data[0] -= mat.data[0];
		data[1] -= mat.data[1];
		data[2] -= mat.data[2];

		data[3] -= mat.data[3];
		data[4] -= mat.data[4];
		data[5] -= mat.data[5];

		data[6] -= mat.data[6];
		data[7] -= mat.data[7];
		data[8] -= mat.data[8];
	}

	// Scalar Multiplication implementation
	Matrix3n Matrix3n::operator*(const float num) {
		Matrix3n m;

		m.data[0] = data[0] * num;
		m.data[1] = data[1] * num;
		m.data[2] = data[2] * num;
		
		m.data[3] = data[3] * num;
		m.data[4] = data[4] * num;
		m.data[5] = data[5] * num;

		m.data[6] = data[6] * num;
		m.data[7] = data[7] * num;
		m.data[8] = data[8] * num;
	
		return m;
	}

	void Matrix3n::operator*=(const float num) {
		data[0] *= num;
		data[1] *= num;
		data[2] *= num;
		
		data[3] *= num;
		data[4] *= num;
		data[5] *= num;

		data[6] *= num;
		data[7] *= num;
		data[8] *= num;
	}

	// Matrix Multiplication implementation
	Matrix3n Matrix3n::operator*(const Matrix3n& m) {
		//	0	3	6	|	m0	m3	m6	
		//	1	4	7	|	m1	m4	m7
		//	2	5	8	|	m2	m5	m8

		Matrix3n mat;

		mat.data[0] = (data[0] * m.data[0]) + (data[3] * m.data[1]) + (data[6] * m.data[2]);
		mat.data[1] = (data[1] * m.data[0]) + (data[4] * m.data[1]) + (data[7] * m.data[2]);
		mat.data[2] = (data[2] * m.data[0]) + (data[5] * m.data[1]) + (data[8] * m.data[2]);
		
		mat.data[3] = (data[0] * m.data[3]) + (data[3] * m.data[4]) + (data[6] * m.data[5]);
		mat.data[4] = (data[1] * m.data[3]) + (data[4] * m.data[4]) + (data[7] * m.data[5]);
		mat.data[5] = (data[2] * m.data[3]) + (data[5] * m.data[4]) + (data[8] * m.data[5]);

		mat.data[6] = (data[0] * m.data[6]) + (data[3] * m.data[7]) + (data[6] * m.data[8]);
		mat.data[7] = (data[1] * m.data[6]) + (data[4] * m.data[7]) + (data[7] * m.data[8]);
		mat.data[8] = (data[2] * m.data[0]) + (data[5] * m.data[1]) + (data[8] * m.data[8]);

		return mat;
	}

	// Identity Matrix implementation
	void Matrix3n::setAsIdentityMatrix() {
		for (int i = 0; i < 9; i++) {
			data[i] = 0.0f;
		}

		data[0] = 1.0f;
		data[4] = 1.0f;
		data[8] = 1.0f;
	}

	// Inverse Matrix implementation
	void Matrix3n::setAsInverseOfGivenMatrix(const Matrix3n& mat) {
		//	0	3	6
		//	1	4	7
		//	2	5	8

		Matrix3n inv;

		// Calculate determinant
		float a = (mat.data[4] * mat.data[8]) - (mat.data[7] * mat.data[5]);
		float b = (mat.data[1] * mat.data[8]) - (mat.data[7] * mat.data[2]);
		float c = (mat.data[1] * mat.data[5]) - (mat.data[4] * mat.data[2]);
		float det = (a * mat.data[0]) + (b * mat.data[3]) + (c * mat.data[6]);

		// Calculate matrix of minors
		inv.data[0] = (mat.data[4] * mat.data[8]) - (mat.data[7] * mat.data[5]);
		inv.data[1] = (mat.data[3] * mat.data[8]) - (mat.data[6] * mat.data[5]);
		inv.data[2] = (mat.data[3] * mat.data[7]) - (mat.data[6] * mat.data[4]);

		inv.data[3] = (mat.data[1] * mat.data[8]) - (mat.data[7] * mat.data[2]);
		inv.data[4] = (mat.data[0] * mat.data[8]) - (mat.data[6] * mat.data[2]);
		inv.data[5] = (mat.data[0] * mat.data[7]) - (mat.data[6] * mat.data[1]);
		
		inv.data[6] = (mat.data[1] * mat.data[5]) - (mat.data[4] * mat.data[2]);
		inv.data[7] = (mat.data[0] * mat.data[5]) - (mat.data[3] * mat.data[2]);
		inv.data[8] = (mat.data[0] * mat.data[4]) - (mat.data[3] * mat.data[1]);
		
		// Convert to matrix of cofactors
		inv.data[1] = inv.data[1] * -1;
		inv.data[3] = inv.data[3] * -1;
		inv.data[5] = inv.data[5] * -1;
		inv.data[7] = inv.data[7] * -1;
		
		// Find Adjugate/Transpose
		float swap = 0;

		swap = inv.data[1];
		inv.data[1] = inv.data[3];
		inv.data[3] = swap;

		swap = inv.data[2];
		inv.data[2] = inv.data[6];
		inv.data[6] = swap;

		swap = inv.data[5];
		inv.data[5] = inv.data[7];
		inv.data[7] = swap;

		// Multiply by 1 / determinant
		inv = inv * (1 / det);

		*this = inv;
	}

	Matrix3n Matrix3n::getInverseOfMatrix() {
		Matrix3n m;
		m.setAsInverseOfGivenMatrix(*this);
		return m;
	}

	void Matrix3n::invertMatrix() {
		setAsInverseOfGivenMatrix(*this);
	}

	// Transpose Matrix implementation
	void Matrix3n::setAsTransposeOfGivenMatrix(const Matrix3n& m) {
		//	0	3	6	|	0	1	2
		//	1	4	7	|	3	4	5
		//	2	5	8	|	6	7	8

		Matrix3n mat = m;

		data[0] = mat.data[0];
		data[1] = mat.data[3];
		data[2] = mat.data[6];

		data[3] = mat.data[1];
		data[4] = mat.data[4];
		data[5] = mat.data[7];

		data[6] = mat.data[2];
		data[7] = mat.data[5];
		data[8] = mat.data[8];
		
	}

	Matrix3n Matrix3n::getTransposeOfMatrix() {
		Matrix3n m;
		m.setAsTransposeOfGivenMatrix(*this);
		return m;
	}

	void Matrix3n::transposeMatrix() {
		setAsTransposeOfGivenMatrix(*this);
	}

	// Vector Transformation implementation
	Vector3n Matrix3n::operator*(const Vector3n& vec) {
		return Vector3n(data[0] * vec.x + data[3] * vec.y + data[6] * vec.z,
						data[1] * vec.x + data[4] * vec.y + data[7] * vec.z,
						data[2] * vec.x + data[5] * vec.y + data[8] * vec.z);
	}
}