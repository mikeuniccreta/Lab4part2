/** \file Matrix.h
 *  \brief     A small marix library, header file
 *  \details   The  ..
 *  \author    Harald Gjermundrod
 *  \version   0.1
 *  \date      2020-2020
 *  \pre       First initialize the system.
 *  \bug       No bugs so far
 *  \copyright University of Nicosia.
 */
#pragma once

 // Global constant
const int MAX_COL = 5;
const int RANDOM_MIN = 0;
const int RANDOM_MAX = 50;

double sumOfRow(const double mat[][MAX_COL], const int row, const int maxRow);
double sumOfCol(const double mat[][MAX_COL], const int column, const int maxRow);
void fillWithRandomNum(double mat[][MAX_COL], const int maxRow);
void printMatrix(const double mat[][MAX_COL], const int maxRow);

bool isIdentityMatrix(const double mat[][MAX_COL], const int maxRow);
bool makeIdentityMatrix(double mat[][MAX_COL], const int maxRow);
double sumOfDiagonal(const double mat[][MAX_COL], const int maxRow);
double* sumOfRows(const double mat[][MAX_COL], const int maxRow);
void transposeMatrix(double mat[][MAX_COL], const int maxRow);
