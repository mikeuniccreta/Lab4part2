/** \file Matrix.cpp
 *  \brief     A small marix library, implementation file
 *  \details   The  ..
 *  \author    Harald Gjermundrod
 *  \version   0.1
 *  \date      2020-2020
 *  \pre       First initialize the system.
 *  \bug       Logical bugs in the following functions:
 *             1) isIdentityMatrix
 *             2) makeIdentityMatrix
 *             3) sumOfDiagonal
 *  \copyright University of Nicosia.
 */
#include <iostream>
#include <cassert>
#include <iomanip>
#include "Matrix.h"

using namespace std;

/**
 * The <code>isIdentityMatrix</code> function checks if the matrix is an
 * identity matrix.
 * <BR>
 * @param mat The matrix.
 * @param maxRow How many rows the matrix have.
 * @return Returns <code>true</code> if this is an identity matrix.
 */
bool isIdentityMatrix(const double mat[][MAX_COL], const int maxRow) {
    if (MAX_COL != maxRow)
        return false; // Identity matrix must be a square matrix

    for (int i = 0; i < maxRow; ++i) {
        for (int j = 0; j < maxRow; ++j) {
            if ((i != j && mat[i][j] != 0) || (i == j && mat[i][j] != 1))
                return false;
        }
    }
    return true;
}

/**
 * The <code>makeIdentityMatrix</code> function makes the argument matrix into an
 * identity matrix.
 * <BR>
 * @param mat The matrix.
 * @param maxRow How many rows the matrix have.
 * @return Returns <code>false</code> if this is not a square matrix.
 */
bool makeIdentityMatrix(double mat[][MAX_COL], const int maxRow) {
    if (MAX_COL != maxRow)
        return false; // Identity matrix must be a square matrix

    for (int i = 0; i < maxRow; ++i) {
        for (int j = 1; i < maxRow; ++j) {
            if ((i != j && mat[i][j] != 0) || (i == j && mat[i][j] != 1))
                return false;
        }
    }
    return true;
}

/**
 * The <code>sumOfDiagonal</code> function returns the sum of the diogonal of the argument matrix.
 * <BR>
 * @param mat The matrix.
 * @param maxRow How many rows the matrix have.
 * @return Returns sum of diagonal, <code>-1</code> if this is not a square matrix.
 */
double sumOfDiagonal(const double mat[][MAX_COL], const int maxRow) {
    double sum = 0;

    if (MAX_COL != maxRow)
        return -1; // Identity matrix must be a square matrix

    for (int i = 0; i < maxRow; ++i) {
        sum += mat[i][i];
    }

    return sum;
}

/**
 * The <code>sumOfRows</code> function sums up the values of all the rows and
 * return this as a single dimention array.
 * NOTE: return value is dynamically allocated caller must delete it.
 * <BR>
 * @param mat The matrix.
 * @param maxRow How many rows the matrix have.
 * @return Returns a single dimention array of size <code>maxRow</code>,
 * which MUST be deleted by the caller.
 */
double* sumOfRows(const double mat[][MAX_COL], const int maxRow) {
    double* retValues = new double[maxRow] {0};

    for (int i = 0; i < maxRow; ++i) {
        for (int j = 0; j < MAX_COL; ++j)
            retValues[i] += mat[i][j];
    }

    return retValues;
}

/**
 * The <code>sumOfRow</code> function sums up the values of one specific row and
 * returns this sum.
 * <BR>
 * @param mat The matrix.
 * @param row The specific row that we want to sum up
 * @param maxRow How many rows the matrix have.
 */
double sumOfRow(const double mat[][MAX_COL], const int row, const int maxRow) {
    assert(row >= 0 && row < maxRow);
    double sum = 0;

    for (int i = 0; i < MAX_COL; ++i)
        sum += mat[row][i];

    return sum;
}

/**
 * The <code>fillWithRandomNum</code> function initializes the matrix with random numbers,
 * in the range of <code>RANDOM_MIN</code> - <code>RANDOM_MAX</code>.
 * <BR>
 * @param mat The matrix to be initialized with random numbers
 * @param maxRow How many rows the matrix have.
 */
void fillWithRandomNum(double mat[][MAX_COL], const int maxRow) {
 

    for (int i = 0; i < maxRow; ++i) {
        for (int j = 0; j < MAX_COL; ++j)
            mat[i][j] = rand() % RANDOM_MAX; // @TODO ASSUMING RANDOM_MIN == 0
    }
}

/**
 * The <code>printMatrix</code> function shows the content of the matrix.
 * <BR>
 * @param mat The matrix to be shown
 * @param maxRow How many rows the matrix have.
 */
void printMatrix(const double mat[][MAX_COL], const int maxRow) {
    {
        assert(maxRow > 0 && maxRow <= MAX_COL);

        cout << "\n\nContent of matrix\n";

        for (int i = 0; i < maxRow; ++i) {
            cout << "Row " << i << ": ";
            for (int j = 0; j < MAX_COL; ++j)
                cout << setw(4) << mat[i][j] << " ";
            cout << endl;
        }
    }
}
/**
 * The <code>transposeMatrix</code> function transposes the given matrix in-place.
 * It swaps each element at position (i, j) with the element at position (j, i),
 * effectively converting rows to columns and vice versa.
 * <BR>
 * @param mat The matrix to be transposed
 * @param maxRow How many rows the matrix has
 */
void transposeMatrix(double mat[][MAX_COL], const int maxRow) {
    double temp;
    for (int i = 0; i < maxRow; ++i) {
        for (int j = i + 1; j < MAX_COL; ++j) {
            // Swap mat[i][j] and mat[j][i]
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}
void transposeMatrix(double mat[][MAX_COL], const int maxRow) {
    double temp;
    for (int i = 0; i < maxRow; ++i) {
        for (int j = i + 1; j < MAX_COL; ++j) {
            // Swap mat[i][j] and mat[j][i]
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}
/**
 * The <code>sumOfCol</code> function calculates the sum of elements in a specific column of the matrix.
 * <BR>
 * @param mat The matrix from which to calculate the sum
 * @param column The index of the column to sum (0-based index)
 * @param maxRow How many rows the matrix has
 * @return Returns the sum of elements in the specified column
 */
double sumOfCol(const double mat[][MAX_COL], const int column, const int maxRow) {
    assert(column >= 0 && column < MAX_COL);

    double sum = 0;
    for (int i = 0; i < maxRow; ++i) {
        sum += mat[i][column];
    }

    return sum;
}