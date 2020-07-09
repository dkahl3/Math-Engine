#define _USE_MATH_DEFINES

#include "Quaternion.h"
#include <math.h>

// Quaternion Class Implementation
// A Quaternion is basically a four component vector that does not suffer from gimbal lock
// This will prove useful for rotating vectors

namespace MathEng {
	// Constructor implementations
	Quaternion::Quaternion() : s(0), v() { }

	Quaternion::Quaternion(float scalar, Vector3n vec): s(scalar), v(vec) { }

	// Destructor implementation
	Quaternion::~Quaternion() { }

	// Copy Constructor implementation
	Quaternion::Quaternion(const Quaternion& q) {
		s = q.s;
		v = q.v;
	}

	Quaternion& Quaternion::operator=(const Quaternion& q) {
		s = q.s;
		v = q.v;

		return *this;
	}

	// Addition implementation
	void Quaternion::operator+=(const Quaternion& q) {
		s += q.s;
		v += q.v;
	}

	Quaternion Quaternion::operator+(const Quaternion& q) {
		float scalar = s + q.s;
		Vector3n vec = v + q.v;

		return Quaternion(scalar, vec);
	}

	// Subtraction implementation
	void Quaternion::operator-=(const Quaternion& q) {
		s -= q.s;
		v -= q.v;
	}

	Quaternion Quaternion::operator-(const Quaternion& q) {
		float scalar = s - q.s;
		Vector3n vec = v - q.v;

		return Quaternion(scalar, vec);
	}

	// Scalar Multiplication implementation
	void Quaternion::operator*=(const float num) {
		s *= num;
		v *= num;
	}

	Quaternion Quaternion::operator*(const float num) {
		float scalar = s * num;
		Vector3n vec = v * num;

		return Quaternion(scalar, vec);
	}

	// Quaternion Multiplication implementation
	void Quaternion::operator*=(const Quaternion& q) {
		(*this) = multiply(q);
	}

	Quaternion Quaternion::operator*(const Quaternion& q) {		
		float scalar = s * q.s - v.dot(q.v);
		Vector3n vec = q.v;
		Vector3n imaginary = vec * s + v * q.s + v.cross(q.v);
		
		return Quaternion(scalar, imaginary);
	}

	Quaternion Quaternion::multiply(const Quaternion& q) {
		float scalar = (s * q.s) - (v.dot(q.v));
		Vector3n vec = q.v;
		Vector3n imaginary = vec * s + v * q.s + v.cross(q.v);

		return Quaternion(scalar, imaginary);
	}

	// Norm implementation
	float Quaternion::norm() {
		return sqrt(s * s + v.dot(v));
	}

	// Normalize implementation
	void Quaternion::normalize() {
		float n = norm();
		
		if (n != 0) {
			float normVal = 1 / n;

			s *= normVal;
			v *= normVal;
		}
	}

	// Convert To Unit Norm implementation
	void Quaternion::convertToUnitNorm() {
		float angle = (s * M_PI) / 180;
		v.normalize();
		s = cosf(angle * 0.5);
		v = v * sinf(angle * 0.5);
	}

	// Conjugate implementation
	Quaternion Quaternion::conjugate() {
		float scalar = s;
		Vector3n vec = v * -1;

		return Quaternion(scalar, vec);
	}

	// Inverse implementation
	Quaternion Quaternion::inverse() {
		float absVal = norm();
		absVal *= absVal;
		absVal = 1 / absVal;

		Quaternion conjVal = conjugate();

		float scalar = conjVal.s * absVal;
		Vector3n imaginary = conjVal.v * absVal;

		return Quaternion(scalar, imaginary);
	}

}