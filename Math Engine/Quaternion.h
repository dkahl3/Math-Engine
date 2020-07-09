#pragma once

#include "Vector3n.h"

namespace MathEng {
	class Quaternion {
	private:

	public:
		// Scalar
		float s;

		// Vector
		Vector3n v;

		// Constructors
		Quaternion();
		Quaternion(float scalar, Vector3n v);

		// Destructor
		~Quaternion();

		// Copy Constructor
		Quaternion(const Quaternion& q);
		Quaternion& operator=(const Quaternion& q);

		// Addition
		void operator+=(const Quaternion& q);
		Quaternion operator+(const Quaternion& q);

		// Subtraction
		void operator-=(const Quaternion& q);
		Quaternion operator-(const Quaternion& q);

		// Scalar Multiplication
		void operator*=(const float num);
		Quaternion operator*(const float num);

		// Quaternion Multiplication
		void operator*=(const Quaternion& q);
		Quaternion operator*(const Quaternion& q);
		Quaternion multiply(const Quaternion& q);

		// Norm
		float norm();

		// Normalize
		void normalize();

		// Convert to unit norm - Rotations
		void convertToUnitNorm();

		// Conjugate
		Quaternion conjugate();

		// Inverse 
		Quaternion inverse();

	};
}
