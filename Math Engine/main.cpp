#include "Vector3n.h"
#include "Matrix3n.h"
#include "Quaternion.h"
#include <iostream>

// Daniel Kahl - Math Engine
// This code contains implementations for Vectors, Matrices, and Quaternions
// A 3D math library that can be used with rendering APIS 
// I would like give credit to Harold Serrano as I used his tutorials on his website as a point or reference when working on this
// https://www.haroldserrano.com/math-engine-project/

int main() {
	// Vector3n Functionality 
	
	// Initialization
	MathEng::Vector3n vec1(1, 2, 3);
	MathEng::Vector3n vec2(1, 1, 1);
	MathEng::Vector3n vec;

	std::cout << "Default Constructor" << std::endl;
	std::cout << vec.x << ", " << vec.y << ", " << vec.z << std::endl;
	std::cout << std::endl;

	// Testing Addition
	vec = vec1 + vec2;
	std::cout << "Addition:" << std::endl;
	std::cout << vec.x << ", " << vec.y << ", " << vec.z << std::endl;
	std::cout << std::endl;

	// Testing Subtraction
	vec = vec1 - vec2;
	std::cout << "Subtraction:" << std::endl;
	std::cout << vec.x << ", " << vec.y << ", " << vec.z << std::endl;
	std::cout << std::endl;

	// Testing Scalar Multiplication
	vec = vec1 * 2;
	std::cout << "Multiplication:" << std::endl;
	std::cout << vec.x << ", " << vec.y << ", " << vec.z << std::endl;
	std::cout << std::endl;

	// Testing Scalar Division
	vec = vec1 / 2;
	std::cout << "Division:" << std::endl;
	std::cout << vec.x << ", " << vec.y << ", " << vec.z << std::endl;
	std::cout << std::endl;

	// Testing Dot Product
	float dotProd = vec1.dot(vec2);
	std::cout << "Dot Product:" << std::endl;
	std::cout << dotProd << std::endl;
	std::cout << std::endl;

	// Testing Cross Product
	vec = vec1.cross(vec2);
	std::cout << "Cross Product:" << std::endl;
	std::cout << vec.x << ", " << vec.y << ", " << vec.z << std::endl;
	std::cout << std::endl;

	// Testing Magnitude
	float mag = vec1.magnitude();
	std::cout << "Magnitude:" << std::endl;
	std::cout << mag << std::endl;
	std::cout << std::endl;

	// Testing Normalize
	std::cout << "Normalize:" << std::endl;
	std::cout << vec.x << ", " << vec.y << ", " << vec.z << std::endl;
	vec.normalize();
	std::cout << vec.x << ", " << vec.y << ", " << vec.z << std::endl;
	std::cout << std::endl;

	// Matrix functionality
	
	// Initialization
	MathEng::Matrix3n m1(2, 3, 1,
						 4, 3, 1,
						 5, 3, 1);

	MathEng::Matrix3n m2(1, 2, 1,
						 1, 2, 1,
						 1, 2, 1);

	MathEng::Matrix3n m3;

	// Testing Addition
	std::cout << "Addition:" << std::endl;
	m1.print();
	std::cout << "	+" << std::endl << std::endl;
	m2.print();
	std::cout << "----------------------" << std::endl;
	m3 = m1 + m2;
	m3.print();

	// Testing Subtraction
	std::cout << "Subtraction:" << std::endl;
	m1.print();
	std::cout << "	-" << std::endl << std::endl;
	m2.print();
	std::cout << "----------------------" << std::endl;
	m3 = m1 - m2;
	m3.print();

	// Testing Scalar Multiplication
	std::cout << "Scalar Multiplication:" << std::endl;
	m1.print();
	std::cout << "	*" << std::endl << std::endl;
	std::cout << "	2" << std::endl;
	std::cout << "----------------------" << std::endl;
	m3 = m1 * 2;
	m3.print();

	// Testing Matrix Multiplication
	std::cout << "Matrix Multiplication:" << std::endl;
	m1.print();
	std::cout << "	*" << std::endl << std::endl;
	m2.print();
	std::cout << "----------------------" << std::endl;
	m3 = m1 * m2;
	m3.print();

	// Testing Identity Matrix
	std::cout << "Identity Matrix:" << std::endl;
	m1.print();
	std::cout << "----------------------" << std::endl;
	m1.setAsIdentityMatrix();
	m1.print();

	// Testing Inverse Matrix
	std::cout << "Inverse Matrix:" << std::endl;
	MathEng::Matrix3n inv(3, 0, 2,
						  2, 0, -2,
						  0, 1, 1);
	inv.print();

	inv.setAsInverseOfGivenMatrix(inv);
	std::cout << "----------------------" << std::endl;

	inv.print();

	// Testing Transpose Matrix
	std::cout << "Transpose Matrix:" << std::endl;
	MathEng::Matrix3n tran(1, 2, 3,
						   1, 1, 3,
						   1, 2, 1);

	tran.print();
	
	tran.transposeMatrix();
	std::cout << "----------------------" << std::endl;

	tran.print();

	// Testing Vector Transformation
	std::cout << "Vector Transformation:" << std::endl;
	MathEng::Matrix3n m(0, 0, 0,
						0, 0, -1,
						0, 1, 0);

	MathEng::Vector3n v(0, 1, 0);

	MathEng::Vector3n transformed = m * v;

	std::cout << transformed.x << ", " << transformed.y << ", " << transformed.z << std::endl << std::endl;

	// Quaternion Functionality

	// Initialization
	MathEng::Vector3n qVec(1, 2, 3);
	MathEng::Quaternion q(1, qVec);

	std::cout << "Quaternion Initialization:" << std::endl;
	std::cout << q.s << " ";
	q.v.print();
	std::cout << std::endl;

	// Copy Constructor
	MathEng::Quaternion newQ = q;
	
	std::cout << "Quaternion Copy Constructor:" << std::endl;
	std::cout << newQ.s << " ";
	newQ.v.print();
	std::cout << std::endl;

	// Quaternion Math
	MathEng::Vector3n qVec1(1, 1, 1);
	MathEng::Quaternion q1(1, qVec1);

	MathEng::Vector3n qVec2(1, 2, 3);
	MathEng::Quaternion q2(2, qVec2);
	
	// Addition
	MathEng::Quaternion addQ = q1 + q2;

	std::cout << "Quaternion Addition:" << std::endl;
	std::cout << q1.s << " ";
	q1.v.print();

	std::cout << "      +" << std::endl;

	std::cout << q2.s << " ";
	q2.v.print();

	std::cout << "-------------" << std::endl;
	std::cout << addQ.s << " ";
	addQ.v.print();
	std::cout << std::endl;

	// Subtraction
	MathEng::Quaternion subQ = q1 - q2;

	std::cout << "Quaternion Subtraction:" << std::endl;
	std::cout << q1.s << " ";
	q1.v.print();

	std::cout << "      -" << std::endl;

	std::cout << q2.s << " ";
	q2.v.print();

	std::cout << "-------------" << std::endl;
	std::cout << subQ.s << " ";
	subQ.v.print();
	std::cout << std::endl;

	// Scalar Multiplication
	MathEng::Quaternion multS = q1 * 2;

	std::cout << "Quaternion Scalar Multiplication:" << std::endl;
	std::cout << q1.s << " ";
	q1.v.print();

	std::cout << "      *" << std::endl;

	std::cout << "      2" << std::endl;

	std::cout << "-------------" << std::endl;
	std::cout << multS.s << " ";
	multS.v.print();
	std::cout << std::endl;

	// Multiplication
	MathEng::Quaternion multQ = q1 * q2;

	std::cout << "Quaternion Multiplication:" << std::endl;
	std::cout << q1.s << " ";
	q1.v.print();

	std::cout << "      *" << std::endl;

	std::cout << q2.s << " ";
	q2.v.print();

	std::cout << "-------------" << std::endl;
	std::cout << multQ.s << " ";
	multQ.v.print();
	std::cout << std::endl;

	// Quaternion Normalize
	std::cout << "Quaternion Normalization:" << std::endl;
	MathEng::Vector3n nVec(0, 1, 0);
	MathEng::Quaternion nQuat(1, nVec);

	std::cout << nQuat.s << " ";
	nQuat.v.print();

	std::cout << "       v" << std::endl;
	nQuat.normalize();

	std::cout << nQuat.s << " ";
	nQuat.v.print();
	std::cout << std::endl;

	// Vector rotation
	std::cout << "Rotating Vector:" << std::endl;
	MathEng::Vector3n rVec(0, 1, 0);
	MathEng::Vector3n axis(1, 0, 0);

	rVec.print();

	MathEng::Vector3n rotatedVector = rVec.rotateVectorAboutAxis(90, axis);

	rotatedVector.print();

	return 0;
}