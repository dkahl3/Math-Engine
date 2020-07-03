#include "Vector3n.h"
#include "Matrix3n.h"
#include <iostream>

int main() {
	// Vector3n Functionality 
	
	// Initialization
	MathEng::Vector3n vec1(1.5, 2, 3);
	MathEng::Vector3n vec2(0.5, 1, 2);
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

	std::cout << transformed.x << ", " << transformed.y << ", " << transformed.z << std::endl;

	return 0;
}