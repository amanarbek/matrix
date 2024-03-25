#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

// Unit test for default constructor
TEST(S21MatrixTest, DefaultConstructor) {
  S21Matrix mat;
  EXPECT_EQ(mat.GetRows(), 0);
  EXPECT_EQ(mat.GetCols(), 0);
}

// Unit test for constructor with specified dimensions
TEST(S21MatrixTest, ConstructorWithDimensions) {
  S21Matrix mat(2, 4);
  EXPECT_EQ(mat.GetRows(), 2);
  EXPECT_EQ(mat.GetCols(), 4);
}

// Unit test for copy constructor
TEST(S21MatrixTest, CopyConstructor) {
  S21Matrix mat1(2, 3);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(1, 0) = 4.0;
  mat1(1, 1) = 5.0;
  mat1(1, 2) = 6.0;

  S21Matrix mat2(mat1);
  EXPECT_EQ(mat2.GetRows(), 2);
  EXPECT_EQ(mat2.GetCols(), 3);
  EXPECT_EQ(mat2(0, 0), 1.0);
  EXPECT_EQ(mat2(0, 1), 2.0);
  EXPECT_EQ(mat2(0, 2), 3.0);
  EXPECT_EQ(mat2(1, 0), 4.0);
  EXPECT_EQ(mat2(1, 1), 5.0);
  EXPECT_EQ(mat2(1, 2), 6.0);
}

// Unit test for move constructor
TEST(S21MatrixTest, MoveConstructor) {
  S21Matrix mat1(2, 3);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(1, 0) = 4.0;
  mat1(1, 1) = 5.0;
  mat1(1, 2) = 6.0;

  S21Matrix mat2(std::move(mat1));
  EXPECT_EQ(mat2.GetRows(), 2);
  EXPECT_EQ(mat2.GetCols(), 3);
  EXPECT_EQ(mat2(0, 0), 1.0);
  EXPECT_EQ(mat2(0, 1), 2.0);
  EXPECT_EQ(mat2(0, 2), 3.0);
  EXPECT_EQ(mat2(1, 0), 4.0);
  EXPECT_EQ(mat2(1, 1), 5.0);
  EXPECT_EQ(mat2(1, 2), 6.0);
}

// Unit test for GetRows function
TEST(S21MatrixTest, GetRows) {
  S21Matrix mat(2, 3);
  EXPECT_EQ(mat.GetRows(), 2);
}

// Unit test for GetCols function
TEST(S21MatrixTest, GetCols) {
  S21Matrix mat(2, 3);
  EXPECT_EQ(mat.GetCols(), 3);
}

// Unit test for SetRows function
TEST(S21MatrixTest, SetRows) {
  S21Matrix mat(2, 3);
  mat.SetRows(4);
  EXPECT_EQ(mat.GetRows(), 4);
  EXPECT_EQ(mat.GetCols(), 3);
}

// Unit test for SetCols function
TEST(S21MatrixTest, SetCols) {
  S21Matrix mat(2, 3);
  mat.SetCols(4);
  EXPECT_EQ(mat.GetRows(), 2);
  EXPECT_EQ(mat.GetCols(), 4);
}

// Unit test for exception in SetRows function
TEST(S21MatrixTest, SetRowsException) {
  S21Matrix mat(2, 3);
  EXPECT_THROW(mat.SetRows(-1), std::out_of_range);
}

// Unit test for exception in SetCols function
TEST(S21MatrixTest, SetColsException) {
  S21Matrix mat(2, 3);
  EXPECT_THROW(mat.SetCols(0), std::out_of_range);
}

// Unit test for EqMatrix function with equal matrices
TEST(S21MatrixTest, EqMatrixEqual) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix mat2(2, 2);
  mat2(0, 0) = 1.0;
  mat2(0, 1) = 2.0;
  mat2(1, 0) = 3.0;
  mat2(1, 1) = 4.0;
  EXPECT_TRUE(mat1.EqMatrix(mat2));
}

// Unit test for EqMatrix function with different matrices
TEST(S21MatrixTest, EqMatrixDifferent) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix mat2(2, 2);
  mat2(0, 0) = 1.0;
  mat2(0, 1) = 2.0;
  mat2(1, 0) = 3.0;
  mat2(1, 1) = 5.0;
  EXPECT_FALSE(mat1.EqMatrix(mat2));
}

// Unit test for EqMatrix function with different dimensions
TEST(S21MatrixTest, EqMatrixDifferentDimensions) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix mat2(3, 3);
  mat2(0, 0) = 1.0;
  mat2(0, 1) = 2.0;
  mat2(0, 2) = 3.0;
  mat2(1, 0) = 4.0;
  mat2(1, 1) = 5.0;
  mat2(1, 2) = 6.0;
  mat2(2, 0) = 7.0;
  mat2(2, 1) = 8.0;
  mat2(2, 2) = 9.0;
  EXPECT_FALSE(mat1.EqMatrix(mat2));
}

// Unit test for SumMatrix function with matrices of the same size
TEST(S21MatrixTest, SumMatrixSameSize) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix mat2(2, 2);
  mat2(0, 0) = 5.0;
  mat2(0, 1) = 6.0;
  mat2(1, 0) = 7.0;
  mat2(1, 1) = 8.0;
  mat1.SumMatrix(mat2);
  EXPECT_DOUBLE_EQ(mat1(0, 0), 6.0);
  EXPECT_DOUBLE_EQ(mat1(0, 1), 8.0);
  EXPECT_DOUBLE_EQ(mat1(1, 0), 10.0);
  EXPECT_DOUBLE_EQ(mat1(1, 1), 12.0);
}

// Unit test for SumMatrix function with matrices of different sizes
TEST(S21MatrixTest, SumMatrixDifferentSize) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix mat2(1, 2);
  mat2(0, 0) = 5.0;
  mat2(0, 1) = 6.0;
  EXPECT_THROW(mat1.SumMatrix(mat2), std::invalid_argument);
}

// Unit test for SubMatrix function with matrices of the same size
TEST(S21MatrixTest, SubMatrixSameSize) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix mat2(2, 2);
  mat2(0, 0) = 5.0;
  mat2(0, 1) = 6.0;
  mat2(1, 0) = 7.0;
  mat2(1, 1) = 8.0;
  mat1.SubMatrix(mat2);
  EXPECT_DOUBLE_EQ(mat1(0, 0), -4.0);
  EXPECT_DOUBLE_EQ(mat1(0, 1), -4.0);
  EXPECT_DOUBLE_EQ(mat1(1, 0), -4.0);
  EXPECT_DOUBLE_EQ(mat1(1, 1), -4.0);
}

TEST(S21MatrixTest, SubMatrixDifferentSize) {
  S21Matrix mat1(2, 2);
  S21Matrix mat2(3, 3);
  EXPECT_THROW(mat1.SubMatrix(mat2), std::invalid_argument);
}

// Unit test for MulNumber function with a positive number
TEST(S21MatrixTest, MulNumberPositive) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  mat1.MulNumber(2.0);
  EXPECT_DOUBLE_EQ(mat1(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(mat1(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(mat1(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(mat1(1, 1), 8.0);
}

// Unit test for MulNumber function with a negative number
TEST(S21MatrixTest, MulNumberNegative) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  mat1.MulNumber(-2.0);
  EXPECT_DOUBLE_EQ(mat1(0, 0), -2.0);
  EXPECT_DOUBLE_EQ(mat1(0, 1), -4.0);
  EXPECT_DOUBLE_EQ(mat1(1, 0), -6.0);
  EXPECT_DOUBLE_EQ(mat1(1, 1), -8.0);
}

// Unit test for MulNumber function with a very large number
TEST(S21MatrixTest, MulNumberLargeNumber) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  double largeNum = 1e20;
  mat1.MulNumber(largeNum);
  EXPECT_DOUBLE_EQ(mat1(0, 0), 1e20);
  EXPECT_DOUBLE_EQ(mat1(0, 1), 2e20);
  EXPECT_DOUBLE_EQ(mat1(1, 0), 3e20);
  EXPECT_DOUBLE_EQ(mat1(1, 1), 4e20);
}

// Unit test for MulMatrix function with valid matrices
TEST(S21MatrixTest, MulMatrixValid) {
  S21Matrix mat1(2, 3);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(1, 0) = 4.0;
  mat1(1, 1) = 5.0;
  mat1(1, 2) = 6.0;
  S21Matrix mat2(3, 2);
  mat2(0, 0) = 7.0;
  mat2(0, 1) = 8.0;
  mat2(1, 0) = 9.0;
  mat2(1, 1) = 10.0;
  mat2(2, 0) = 11.0;
  mat2(2, 1) = 12.0;
  mat1.MulMatrix(mat2);
  EXPECT_DOUBLE_EQ(mat1(0, 0), 58.0);
  EXPECT_DOUBLE_EQ(mat1(0, 1), 64.0);
  EXPECT_DOUBLE_EQ(mat1(1, 0), 139.0);
  EXPECT_DOUBLE_EQ(mat1(1, 1), 154.0);
}

// Unit test for MulMatrix function with invalid matrices
TEST(S21MatrixTest, MulMatrixInvalid) {
  S21Matrix mat1(2, 3);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(1, 0) = 4.0;
  mat1(1, 1) = 5.0;
  mat1(1, 2) = 6.0;
  S21Matrix mat2(2, 2);
  mat2(0, 0) = 7.0;
  mat2(0, 1) = 8.0;
  mat2(1, 0) = 9.0;
  mat2(1, 1) = 10.0;
  EXPECT_THROW(mat1.MulMatrix(mat2), std::invalid_argument);
}

// Unit test for MulMatrix function with a very large matrix
TEST(S21MatrixTest, MulMatrixLargeMatrix) {
  size_t size = 500;
  S21Matrix mat1(size, size);
  S21Matrix mat2(size, size);
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      mat1(i, j) = 1.0;
      mat2(i, j) = 2.0;
    }
  }
  mat1.MulMatrix(mat2);
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      EXPECT_DOUBLE_EQ(mat1(i, j), 2.0 * size);
    }
  }
}

// Unit test for Transpose function with a square matrix
TEST(S21MatrixTest, TransposeSquare) {
  S21Matrix mat1(3, 3);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(1, 0) = 4.0;
  mat1(1, 1) = 5.0;
  mat1(1, 2) = 6.0;
  mat1(2, 0) = 7.0;
  mat1(2, 1) = 8.0;
  mat1(2, 2) = 9.0;
  S21Matrix result = mat1.Transpose();
  EXPECT_DOUBLE_EQ(result(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(result(0, 2), 7.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 5.0);
  EXPECT_DOUBLE_EQ(result(1, 2), 8.0);
  EXPECT_DOUBLE_EQ(result(2, 0), 3.0);
  EXPECT_DOUBLE_EQ(result(2, 1), 6.0);
  EXPECT_DOUBLE_EQ(result(2, 2), 9.0);
}

// Unit test for Transpose function with a rectangular matrix
TEST(S21MatrixTest, TransposeRectangular) {
  S21Matrix mat1(2, 3);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(1, 0) = 4.0;
  mat1(1, 1) = 5.0;
  mat1(1, 2) = 6.0;
  S21Matrix result = mat1.Transpose();
  EXPECT_DOUBLE_EQ(result(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 5.0);
  EXPECT_DOUBLE_EQ(result(2, 0), 3.0);
  EXPECT_DOUBLE_EQ(result(2, 1), 6.0);
}

// Unit test for CalcComplements function with a 1x1 matrix
TEST(S21MatrixTest, CalcComplements1x1) {
  S21Matrix mat1(1, 1);
  mat1(0, 0) = 3.0;
  S21Matrix result = mat1.CalcComplements();
  EXPECT_DOUBLE_EQ(result(0, 0), 1.0);
}

// Unit test for CalcComplements function with a 2x2 matrix
TEST(S21MatrixTest, CalcComplements2x2) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix result = mat1.CalcComplements();
  EXPECT_DOUBLE_EQ(result(0, 0), 4.0);
  EXPECT_DOUBLE_EQ(result(0, 1), -3.0);
  EXPECT_DOUBLE_EQ(result(1, 0), -2.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 1.0);
}

// Unit test for CalcComplements function with a 3x3 matrix
TEST(S21MatrixTest, CalcComplements3x3) {
  S21Matrix mat1(3, 3);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(1, 0) = 4.0;
  mat1(1, 1) = 5.0;
  mat1(1, 2) = 6.0;
  mat1(2, 0) = 7.0;
  mat1(2, 1) = 8.0;
  mat1(2, 2) = 9.0;
  S21Matrix result = mat1.CalcComplements();
  EXPECT_DOUBLE_EQ(result(0, 0), -3.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 6.0);
  EXPECT_DOUBLE_EQ(result(0, 2), -3.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(result(1, 1), -12.0);
  EXPECT_DOUBLE_EQ(result(1, 2), 6.0);
  EXPECT_DOUBLE_EQ(result(2, 0), -3.0);
  EXPECT_DOUBLE_EQ(result(2, 1), 6.0);
  EXPECT_DOUBLE_EQ(result(2, 2), -3.0);
}

// Unit test for Determinant function with a 1x1 matrix
TEST(S21MatrixTest, Determinant_1x1) {
  S21Matrix mat1(1, 1);
  mat1(0, 0) = 5.0;
  double det = mat1.Determinant();
  EXPECT_DOUBLE_EQ(det, 5.0);
}

// Unit test for Determinant function with a 2x2 matrix
TEST(S21MatrixTest, Determinant_2x2) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  double det = mat1.Determinant();
  EXPECT_DOUBLE_EQ(det, -2.0);
}

// Unit test for Determinant function with a 3x3 matrix
TEST(S21MatrixTest, Determinant_3x3) {
  S21Matrix mat1(3, 3);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(1, 0) = 4.0;
  mat1(1, 1) = 5.0;
  mat1(1, 2) = 6.0;
  mat1(2, 0) = 7.0;
  mat1(2, 1) = 8.0;
  mat1(2, 2) = 9.0;
  double det = mat1.Determinant();
  EXPECT_DOUBLE_EQ(det, 0.0);
}

// Unit test for Determinant function with a 4x4 matrix
TEST(S21MatrixTest, Determinant_4x4) {
  S21Matrix mat1(4, 4);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(0, 3) = 4.0;
  mat1(1, 0) = 5.0;
  mat1(1, 1) = 6.0;
  mat1(1, 2) = 7.0;
  mat1(1, 3) = 8.0;
  mat1(2, 0) = 9.0;
  mat1(2, 1) = 10.0;
  mat1(2, 2) = 11.0;
  mat1(2, 3) = 12.0;
  mat1(3, 0) = 13.0;
  mat1(3, 1) = 14.0;
  mat1(3, 2) = 15.0;
  mat1(3, 3) = 16.0;
  double det = mat1.Determinant();
  EXPECT_DOUBLE_EQ(det, 0.0);
}

// Unit test for InverseMatrix function with a 1x1 matrix
TEST(S21MatrixTest, InverseMatrix_1x1) {
  S21Matrix mat1(1, 1);
  mat1(0, 0) = 5.0;
  S21Matrix inv_mat = mat1.InverseMatrix();
  EXPECT_DOUBLE_EQ(inv_mat(0, 0), 0.2);
}

// Unit test for InverseMatrix function with a 2x2 matrix
TEST(S21MatrixTest, InverseMatrix_2x2) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix inv_mat = mat1.InverseMatrix();
  EXPECT_DOUBLE_EQ(inv_mat(0, 0), -2.0);
  EXPECT_DOUBLE_EQ(inv_mat(0, 1), 1.0);
  EXPECT_DOUBLE_EQ(inv_mat(1, 0), 1.5);
  EXPECT_DOUBLE_EQ(inv_mat(1, 1), -0.5);
}

// Unit test for InverseMatrix function with a 3x3 matrix
TEST(S21MatrixTest, InverseMatrix_3x3) {
  S21Matrix mat1(2, 3);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(1, 0) = 4.0;
  mat1(1, 1) = 5.0;
  mat1(1, 2) = 6.0;
  EXPECT_THROW(mat1.InverseMatrix(), std::invalid_argument);
}

// Unit test for InverseMatrix function with a singular matrix
TEST(S21MatrixTest, InverseMatrix_Singular) {
  S21Matrix mat1(1, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  EXPECT_THROW(mat1.InverseMatrix(), std::invalid_argument);
}

// Unit test for operator+ function
TEST(S21MatrixTest, OperatorPlus) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix mat2(2, 2);
  mat2(0, 0) = 5.0;
  mat2(0, 1) = 6.0;
  mat2(1, 0) = 7.0;
  mat2(1, 1) = 8.0;
  S21Matrix result = mat1 + mat2;
  EXPECT_EQ(result(0, 0), 6.0);
  EXPECT_EQ(result(0, 1), 8.0);
  EXPECT_EQ(result(1, 0), 10.0);
  EXPECT_EQ(result(1, 1), 12.0);
}

// Unit test for operator- function
TEST(S21MatrixTest, OperatorMinus) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix mat2(2, 2);
  mat2(0, 0) = 5.0;
  mat2(0, 1) = 6.0;
  mat2(1, 0) = 7.0;
  mat2(1, 1) = 8.0;
  S21Matrix result = mat2 - mat1;
  EXPECT_EQ(result(0, 0), 4.0);
  EXPECT_EQ(result(0, 1), 4.0);
  EXPECT_EQ(result(1, 0), 4.0);
  EXPECT_EQ(result(1, 1), 4.0);
}

// Unit test for operator* function
TEST(S21MatrixTest, OperatorMultiply) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix mat2(2, 2);
  mat2(0, 0) = 5.0;
  mat2(0, 1) = 6.0;
  mat2(1, 0) = 7.0;
  mat2(1, 1) = 8.0;
  S21Matrix result = mat1 * mat2;
  EXPECT_EQ(result(0, 0), 19.0);
  EXPECT_EQ(result(0, 1), 22.0);
  EXPECT_EQ(result(1, 0), 43.0);
  EXPECT_EQ(result(1, 1), 50.0);
}

TEST(S21MatrixTest1, OperatorMultiply1) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix result = 2 * mat1;
  EXPECT_EQ(result(0, 0), 2.0);
  EXPECT_EQ(result(0, 1), 4.0);
  EXPECT_EQ(result(1, 0), 6.0);
  EXPECT_EQ(result(1, 1), 8.0);
}

TEST(S21MatrixTest2, OperatorMultiply2) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  mat1 *= 2.0;
  EXPECT_EQ(mat1(0, 0), 2.0);
  EXPECT_EQ(mat1(0, 1), 4.0);
  EXPECT_EQ(mat1(1, 0), 6.0);
  EXPECT_EQ(mat1(1, 1), 8.0);
}

// Unit test for operator== function
TEST(S21MatrixTest, OperatorEqual) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix mat2(2, 2);
  mat2(0, 0) = 1.0;
  mat2(0, 1) = 2.0;
  mat2(1, 0) = 3.0;
  mat2(1, 1) = 4.0;
  bool result = (mat1 == mat2);
  EXPECT_TRUE(result);
}

// Unit test for operator= function
TEST(S21MatrixTest, OperatorAssignment) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix mat2(2, 2);
  mat2 = mat1;
  EXPECT_EQ(mat2(0, 0), 1.0);
  EXPECT_EQ(mat2(0, 1), 2.0);
  EXPECT_EQ(mat2(1, 0), 3.0);
  EXPECT_EQ(mat2(1, 1), 4.0);
}

// Unit test for operator+= function
TEST(S21MatrixTest, OperatorPlusEqual) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix mat2(2, 2);
  mat2(0, 0) = 5.0;
  mat2(0, 1) = 6.0;
  mat2(1, 0) = 7.0;
  mat2(1, 1) = 8.0;
  mat1 += mat2;
  EXPECT_EQ(mat1(0, 0), 6.0);
  EXPECT_EQ(mat1(0, 1), 8.0);
  EXPECT_EQ(mat1(1, 0), 10.0);
  EXPECT_EQ(mat1(1, 1), 12.0);
}

// Unit test for operator-= function
TEST(S21MatrixTest, OperatorMinusEqual) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix mat2(2, 2);
  mat2(0, 0) = 5.0;
  mat2(0, 1) = 6.0;
  mat2(1, 0) = 7.0;
  mat2(1, 1) = 8.0;
  mat1 -= mat2;
  EXPECT_EQ(mat1(0, 0), -4.0);
  EXPECT_EQ(mat1(0, 1), -4.0);
  EXPECT_EQ(mat1(1, 0), -4.0);
  EXPECT_EQ(mat1(1, 1), -4.0);
}
// Unit test for operator*= function
TEST(S21MatrixTest, OperatorMultiplyEqual) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;
  S21Matrix mat2(2, 2);
  mat2(0, 0) = 5.0;
  mat2(0, 1) = 6.0;
  mat2(1, 0) = 7.0;
  mat2(1, 1) = 8.0;
  mat1 *= mat2;
  EXPECT_EQ(mat1(0, 0), 19.0);
  EXPECT_EQ(mat1(0, 1), 22.0);
  EXPECT_EQ(mat1(1, 0), 43.0);
  EXPECT_EQ(mat1(1, 1), 50.0);
}
// Unit test for operator() function
TEST(S21MatrixTest, OperatorParentheses) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;
  EXPECT_EQ(mat(0, 0), 1.0);
  EXPECT_EQ(mat(0, 1), 2.0);
  EXPECT_EQ(mat(1, 0), 3.0);
  EXPECT_EQ(mat(1, 1), 4.0);
  EXPECT_THROW(mat(-1, 0), std::out_of_range);
  EXPECT_THROW(mat(0, -1), std::out_of_range);
  EXPECT_THROW(mat(2, 0), std::out_of_range);
  EXPECT_THROW(mat(0, 2), std::out_of_range);
}

/////////////////////////////////
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
/////////////////////////////////