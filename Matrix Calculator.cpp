#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printMatrix(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> addMatrices(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
    vector<vector<int>> result(matrix1.size(), vector<int>(matrix1[0].size()));
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1[i].size(); j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

vector<vector<int>> multiplyMatrices(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
    vector<vector<int>> result(matrix1.size(), vector<int>(matrix2[0].size()));
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix2[0].size(); j++) {
            result[i][j] = 0;
            for (int k = 0; k < matrix1[i].size(); k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix) {
    vector<vector<int>> result(matrix[0].size(), vector<int>(matrix.size()));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

vector<vector<int>> powerMatrix(vector<vector<int>> matrix, int power) {
    vector<vector<int>> result = matrix;
    for (int i = 1; i < power; i++) {
        result = multiplyMatrices(result, matrix);
    }
    return result;
}

vector<vector<int>> getInputMatrix(int m, int n) {
    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        cout << "Enter the numbers for row #" << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}
void GetRowColumns(int& m1, int& n1, int& m2, int& n2)
{
    
    cout << "Please enter the dimensions of the first matrix: ";
    cin >> m1 >> n1;
    cout << "Please enter the dimensions of the second matrix: ";
    cin >> m2 >> n2;
}

void GetRowColumns(int& m1, int& n1)
{

    cout << "Please enter the dimensions of the matrix: ";
    cin >> m1 >> n1;
}

int GetChoice()
{
    int choice;
    cout << "Pick a choice from the list:" << endl;
    cout << "1- Addition Operation" << endl;
    cout << "2- Multiplication Operation" << endl;
    cout << "3- Power Operation" << endl;
    cout << "4- Transpose Operation" << endl;
    cout << "5- Exit" << endl;
    cout << "Choice:" << endl;
    cin >> choice;
    return choice;

}

int main() {
    int choice;
    int m1, n1, m2, n2;
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;
    do {
        choice = GetChoice();
        if (choice == 1) {
            
            GetRowColumns(m1, n1, m2, n2);
            if (m1 != m2 || n1 != n2) {
                cout << "The two matrices do not have the same dimensions. Addition cannot be performed." << endl;
            }
            else
            {
                cout << "The two matrices have the same dimensions. Addition can be performed." << endl << endl;
                cout << "Please enter the numbers for the first matrix." << endl;
                matrix1 = getInputMatrix(m1, n1);
                cout << "The first matrix is:" << endl;
                printMatrix(matrix1);
                cout << endl;

                cout << "Please enter the numbers for the second matrix." << endl;
                matrix2 = getInputMatrix(m2, n2);
                cout << "The second matrix is:" << endl;
                printMatrix(matrix2);
                cout << endl;
                cout << "Result of the Sum Operation:" << endl;
                printMatrix(addMatrices(matrix1, matrix2));
                cout << endl;
            }
        }
        else if (choice == 2)
        {
            GetRowColumns(m1, n1, m2, n2);
            if (n1 != m2) {
                cout << "The number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
                cout << "Multiplication cannot be performed." << endl;
            }
            else
            {
                cout << "The number of columns in the first matrix is equal to the number of rows in the second matrix. Multiplication can be performed." << endl;
                cout << "Please enter the numbers for the first matrix." << endl;
                matrix1 = getInputMatrix(m1, n1);
                cout << "The first matrix is:" << endl;
                printMatrix(matrix1);
                cout << endl;

                cout << "Please enter the numbers for the second matrix." << endl;
                matrix2 = getInputMatrix(m2, n2);
                cout << "The second matrix is:" << endl;
                printMatrix(matrix2);
                cout << endl;
                cout << "Result of the Multiplication Operation:" << endl;
                printMatrix(multiplyMatrices(matrix1, matrix2));
                cout << endl;

            }
        
        }
        else if (choice == 3)
        {
            GetRowColumns(m1, n1);
            int power;
            if (m1 != n1)
            {
                cout << "The matrix does not have the same number of rows as columns. Power cannot be performed." << endl << endl;
            }
            else
            {
                cout << "The matrix has the same number of rows as columns. Power can be performed." << endl << endl;
                cout << "Please enter the numbers for the matrix." << endl;
                matrix1 = getInputMatrix(m1, n1);
                cout << "The matrix is:" << endl;
                printMatrix(matrix1);
                cout << endl;
                cout << "Please enter the power: ";
                cin >> power;
                cout << "Result of the Power Operation:" << endl;
                printMatrix(powerMatrix(matrix1, power));
                cout << endl;
            }

        }
        else if (choice == 4)
        {
            GetRowColumns(m1, n1);
            cout << "Please enter the numbers for the matrix." << endl;
            matrix1 = getInputMatrix(m1, n1);
            cout << "The matrix is:" << endl;
            printMatrix(matrix1);
            cout << endl << "Result of the Transpose Operation:" << endl;
            printMatrix(transposeMatrix(matrix1));
            cout << endl;

        }


    } while (choice != 5);

    return 0;
}
