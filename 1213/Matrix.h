#pragma once
#include <string> 

class Vector3D {
public:
    double x, y, z;

    Vector3D();
    Vector3D(double _x, double _y, double _z);

    void read();
    void print();
};

// ------------------------------------------- //

class Matrix
{
public:
    // --- Constructors ---
    Matrix();
    Matrix(int m, int _n);

    //  --- Functions --- 
    void read(const std::string& name);
    void print(const std::string& name);
    Matrix multiply(Matrix other);
    Matrix transpose();
    double determinant();
    Matrix inverse();
    Vector3D solve(Vector3D b);

    //  --- Constants --- 
    static const int M = 10;
    static const int N = 10;

    //  --- Veriables --- 
    double A[M][N];
    int m; // actual number of rows
    int n; // actual number of columns
};
