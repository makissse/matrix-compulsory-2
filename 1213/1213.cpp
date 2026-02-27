
#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {

    int choice = 0;

    do {
        // Display menu
        cout << "\n==============================\n";
        cout << "        MATRIX MENU\n";
        cout << "==============================\n";
        cout << "1 - Multiply two matrices\n";
        cout << "2 - Transpose matrix\n";
        cout << "3 - Determinant (3x3)\n";
        cout << "4 - Inverse (3x3)\n";
        cout << "5 - Matrix * Vector (3x3)\n";
        cout << "6 - Solve AX = B\n";
        cout << "0 - Exit\n";
        cout << "Choose option: ";
        cin >> choice;

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
            cout << "det(A) = " << det << std::endl;
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

        case 5: { // Matrix × Vector 
            Matrix A(3, 3); A.read("A"); 
            Vector3D v; v.read(); 

            Vector3D result = A.multiply(v); 
            cout << "Result = "; result.print();
            break; 
        }

        case 6: {
            // Solve linear system AX = B

            Matrix A(3, 3);
            A.read("A");

            Vector3D b;
            b.read();

            // Solve system
            Vector3D x = A.solve(b);

            cout << "Solution X = ";
            x.print();

            break;
        }

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}