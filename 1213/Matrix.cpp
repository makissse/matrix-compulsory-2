
#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
	// Default constructor, initalizes object to a N(10)xM(10) matrix
	m = M;
	n = N;
	// 0 out all inital values of matrix
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = 0;
		}
	}
}

Matrix::Matrix(int _m, int _n) : m(_m), n(_n)
{
	// Overload construcor, initalizes object to a cusom _m x _n matrix
	for (int i = 0; i < _m; i++) {
		for (int j = 0; j < _n; j++) {
			A[i][j] = 0;
		}
	}
}

void Matrix::read(const std::string& name)
{
	// Inform user what matrix is being entered
	std::cout << "\nEnter matrix " << name
		<< " (" << m << "x" << n << ") row by row:\n";

	for (int i = 0; i < m; i++) {

		std::cout << "Row " << i + 1 << ": ";

		// Read one full row
		for (int j = 0; j < n; j++) {
			std::cin >> A[i][j];
		}
	}
}

void Matrix::print(const std::string& name)
{
	// Print formatted matrix with its name
	std::cout << "\nMatrix " << name
		<< " (" << m << "x" << n << "):\n";

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << A[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

Matrix Matrix::multiplyExample(Matrix other)
{
	// Hardcoded example of a 2x2 matrix multiplication.

	if (n != other.m)
	{
		std::cout << "Can't multiply because of size differences" << std::endl;
		return Matrix();
	}

	Matrix result(m, other.n);

	// Temp variables for current matrix
	double a = A[0][0], b = A[0][1];
	double c = A[1][0], d = A[1][1];
	// Current matrix
	// | a b |
	// | c d |

	// Temp variables for other matrix
	double e = other.A[0][0], f = other.A[0][1];
	double g = other.A[1][0], h = other.A[1][1];
	// Other matrix
	// | e f |
	// | g h |

	// Multiplication:
	result.A[0][0] = a * e + b * g;
	result.A[0][1] = a * f + b * h;
	result.A[1][0] = c * e + d * g;
	result.A[1][1] = c * f + d * h;
	// | a b | * | e f | = | (a*e + b*g) (a*f + b*h) |
	// | c d |	 | g h |   | (c*e + d*g) (c*f + d*h) |

	return result;
}

Matrix Matrix::multiply(Matrix other)
{
	// Dynamic multiplication for all matrix sizes.

	if ((m != other.n) || (other.m != n)) {
		std::cout << "Cannot multiply, diffrent sizes" << std::endl;
		return Matrix();
	}

	Matrix dynamicResult(m, other.n);

	// Itterate through rows
	for (int i = 0; i < m; i++) {

		// Itterate through columns
		for (int j = 0; j < other.n; j++) {

			// Itterate through index of multiplication
			for (int k = 0; k < n; k++) {

				// Sequentially calulate each term of a matrix multiplication
				double resultValue = dynamicResult.A[i][j] + (A[i][k] * other.A[k][j]);
				dynamicResult.A[i][j] = resultValue;
			}
		}
	}

	return dynamicResult;
}

Matrix Matrix::transpose()
{
	// Create new matrix with swapped dimensions
	Matrix result(n, m);

	// Swap rows and columns
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			result.A[j][i] = A[i][j];
		}
	}

	return result;
}

double Matrix::determinant()
{
	// Check if matrix is 3x3
	if (m != 3 || n != 3) {
		std::cout << "Determinant defined only for 3x3 matrix" << std::endl;
		return 0.0;
	}

	// Using rule of Sarrus
	double det =
		A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
		- A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
		+ A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

	return det;
}

Matrix Matrix::inverse()
{
	Matrix result(3, 3);

	double det = determinant();

	if (det == 0) {
		std::cout << "Matrix is singular, no inverse." << std::endl;
		return result;
	}

	// Cofactor matrix
	result.A[0][0] = (A[1][1] * A[2][2] - A[1][2] * A[2][1]);
	result.A[0][1] = -(A[1][0] * A[2][2] - A[1][2] * A[2][0]);
	result.A[0][2] = (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

	result.A[1][0] = -(A[0][1] * A[2][2] - A[0][2] * A[2][1]);
	result.A[1][1] = (A[0][0] * A[2][2] - A[0][2] * A[2][0]);
	result.A[1][2] = -(A[0][0] * A[2][1] - A[0][1] * A[2][0]);

	result.A[2][0] = (A[0][1] * A[1][2] - A[0][2] * A[1][1]);
	result.A[2][1] = -(A[0][0] * A[1][2] - A[0][2] * A[1][0]);
	result.A[2][2] = (A[0][0] * A[1][1] - A[0][1] * A[1][0]);

	// Transpose (adjugate)
	result = result.transpose();

	// Multiply by 1/det
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.A[i][j] /= det;
		}
	}

	return result;
}

Vector3D Matrix::multiply(Vector3D v)
{
	// Check if matrix is 3x3
	if (m != 3 || n != 3) {
		std::cout << "Matrix must be 3x3 to multiply with Vector3D" << std::endl;
		return Vector3D();
	}

	Vector3D result;

	// Matrix-vector multiplication
	result.x = A[0][0] * v.x + A[0][1] * v.y + A[0][2] * v.z;
	result.y = A[1][0] * v.x + A[1][1] * v.y + A[1][2] * v.z;
	result.z = A[2][0] * v.x + A[2][1] * v.y + A[2][2] * v.z;

	return result;
}


// ---------------------------------------------------------------------------------------------------------------------------- //


// Default constructor
Vector3D::Vector3D() : x(0), y(0), z(0) {}

// Constructor with values
Vector3D::Vector3D(double _x, double _y, double _z)
	: x(_x), y(_y), z(_z) {
}

// Read vector values
void Vector3D::read()
{
	std::cout << "Enter vector (x y z): ";
	std::cin >> x >> y >> z;
}

// Print vector
void Vector3D::print()
{
	std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}