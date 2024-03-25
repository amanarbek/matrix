#ifndef CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H_
#define CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  friend S21Matrix operator*(const double value, const S21Matrix& matrix);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  bool operator==(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const double num);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  S21Matrix& operator*=(const S21Matrix& other);
  double& operator()(const int i, const int j);

  int GetRows() const noexcept;
  int GetCols() const noexcept;
  void SetRows(int rows);
  void SetCols(int cols);

 private:
  int rows_;
  int cols_;
  double** matrix_;
  static constexpr double eps = 1e-6;
  void MinorMatrix(S21Matrix& minor, int using_row, int using_col);
  void s21_create_matrix();
  void s21_remove_matrix();
};

#endif  // CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H_
