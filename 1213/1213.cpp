
#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {

    int choice = 0;

    do {
        // Display menu
        std::cout << "\n==============================\n";
        std::cout << "        MATRIX MENU\n";
        std::cout << "==============================\n";
        std::cout << "1 - Multiply two matrices\n";
        std::cout << "2 - Transpose matrix\n";
        std::cout << "3 - Determinant (3x3)\n";
        std::cout << "4 - Inverse (3x3)\n";
        std::cout << "5 - Matrix × Vector (3x3)\n";
        std::cout << "0 - Exit\n";
        std::cout << "Choose option: ";
        std::cin >> choice;

        switch (choice) {

        case 1: {
            // Matrix multiplication
            Matrix A(3, 3);
            Matrix B(3, 3);

            A.read("A");
            B.read("B");

            Matrix C = A.multiply(B);
            C.print("C = A * B");
            break;
        }

        case 2: {
            // Transpose
            Matrix A(3, 3);
            A.read("A");

            Matrix AT = A.transpose();
            AT.print("A^T");
            break;
        }

        case 3: {
            // Determinant
            Matrix A(3, 3);
            A.read("A");

            double det = A.determinant();
            std::cout << "det(A) = " << det << std::endl;
            break;
        }

        case 4: {
            // Inverse
            Matrix A(3, 3);
            A.read("A");

            Matrix invA = A.inverse();
            invA.print("A^-1");
            break;
        }

        case 5: {
            // Matrix × Vector
            Matrix A(3, 3);
            A.read("A");

            Vector3D v;
            v.read();

            Vector3D result = A.multiply(v);

            std::cout << "Result = ";
            result.print();
            break;
        }

        case 0:
            std::cout << "Exiting program...\n";
            break;

        default:
            std::cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}