#include "s21_matrix_oop.h"

void S21Matrix::s21_create_matrix() {
  if (rows_ < 1 || cols_ < 1) {
    throw std::out_of_range("Row or сolumn out of range!");
  }
  matrix_ = new double*[rows_];
  double* values = new double[rows_ * cols_]();
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = values + i * cols_;
  }
}

void S21Matrix::s21_remove_matrix() {
  if (matrix_) {
    delete[] matrix_[0];
    delete[] matrix_;
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols)
    : rows_(rows), cols_(cols), matrix_(nullptr) {
  s21_create_matrix();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix(other.rows_, other.cols_) {
  *this = other;
}

S21Matrix::S21Matrix(S21Matrix&& other) : S21Matrix() {
  *this = std::move(other);
}

S21Matrix::~S21Matrix() { s21_remove_matrix(); }

int S21Matrix::GetRows() const noexcept { return rows_; }

int S21Matrix::GetCols() const noexcept { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows < 1) {
    throw std::out_of_range("Rows must be a positive integer");
  }
  S21Matrix temp = std::move(*this);
  rows_ = rows;
  cols_ = temp.cols_;
  if (cols_ >= 1) {
    s21_create_matrix();
    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < cols_; ++j)
        matrix_[i][j] = i >= temp.rows_ ? 0 : temp.matrix_[i][j];
  }
}

void S21Matrix::SetCols(int cols) {
  if (cols < 1) {
    throw std::out_of_range("Cols must be a positive integer");
  }
  S21Matrix temp = std::move(*this);
  rows_ = temp.rows_;
  cols_ = cols;
  if (rows_ >= 1) {
    s21_create_matrix();
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] = (j >= temp.cols_) ? 0 : temp.matrix_[i][j];
      }
    }
  }
}

double& S21Matrix::operator()(const int i, const int j) {
  if (nullptr == matrix_ || i < 0 || j < 0 || i >= rows_ || j >= cols_) {
    throw std::out_of_range("Row or сolumn out of range or invalid matrix");
  }
  return matrix_[i][j];
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    s21_remove_matrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    s21_create_matrix();
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        this->matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  if (this != &other) {
    s21_remove_matrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
  }
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix res = *this;
  res.SumMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix res = *this;
  res.SubMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix res = *this;
  res.MulNumber(num);
  return res;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

S21Matrix operator*(const double value, const S21Matrix& matrix) {
  S21Matrix result = matrix;
  result.MulNumber(value);
  return result;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix res = *this;
  res.MulMatrix(other);
  return res;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (nullptr == matrix_ || nullptr == other.matrix_) {
    throw std::invalid_argument("Invalid matrix");
  }
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (std::fabs(matrix_[i][j] - other.matrix_[i][j]) >= S21Matrix::eps) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (nullptr == matrix_ || nullptr == other.matrix_ || rows_ != other.rows_ ||
      cols_ != other.cols_) {
    throw std::invalid_argument("Invalid matrix");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) matrix_[i][j] += other.matrix_[i][j];
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (nullptr == matrix_ || nullptr == other.matrix_ || rows_ != other.rows_ ||
      cols_ != other.cols_) {
    throw std::invalid_argument("Invalid matrix");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) matrix_[i][j] -= other.matrix_[i][j];
  }
}

void S21Matrix::MulNumber(const double num) {
  if (nullptr == matrix_) {
    throw std::invalid_argument("Invalid matrix");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (nullptr == matrix_ || nullptr == other.matrix_ || cols_ != other.rows_) {
    throw std::invalid_argument("Invalid matrix");
  }
  S21Matrix res(rows_, other.cols_);
  for (int i = 0; i < res.rows_; ++i) {
    for (int j = 0; j < res.cols_; ++j) {
      res.matrix_[i][j] = 0;
      for (int k = 0; k < cols_; ++k) {
        res.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = std::move(res);
}

S21Matrix S21Matrix::Transpose() {
  if (nullptr == matrix_) {
    throw std::out_of_range("Invalid matrix");
  }
  S21Matrix res(cols_, rows_);
  for (int i = 0; i < res.rows_; ++i) {
    for (int j = 0; j < res.cols_; ++j) {
      res.matrix_[i][j] = matrix_[j][i];
    }
  }
  return res;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix res(rows_, cols_);
  if (1 == rows_) {
    res.matrix_[0][0] = 1;
  } else {
    S21Matrix minor(rows_ - 1, cols_ - 1);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        MinorMatrix(minor, i, j);
        double det = minor.Determinant();
        double sign = ((i + j) % 2 == 0) ? 1 : -1;
        res.matrix_[i][j] = sign * det;
      }
    }
  }
  return res;
}

double S21Matrix::Determinant() {
  double result = 0.0;
  if (rows_ < 1 || rows_ != cols_) {
    throw std::invalid_argument("Incorrect size");
  }
  if (1 == rows_) {
    result = matrix_[0][0];
  } else if (2 == rows_) {
    result += matrix_[0][0] * matrix_[1][1];
    result += matrix_[0][1] * matrix_[1][0] * -1;
  } else {
    double temp_result = 0.0;
    char minus_flag = 1;
    S21Matrix minor(rows_ - 1, cols_ - 1);
    for (int i = 0; i < rows_; ++i) {
      MinorMatrix(minor, 0, i);
      temp_result = minor.Determinant();
      result += temp_result * minus_flag * matrix_[0][i];
      minus_flag = -minus_flag;
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_ || nullptr == matrix_) {
    throw std::invalid_argument("Matrix is not square or does not exist");
  }
  double det = Determinant();
  if (std::fabs(det) < S21Matrix::eps) {
    throw "Matrix determinant is 0";
  }
  S21Matrix res(rows_, cols_);
  S21Matrix M = CalcComplements().Transpose();
  res = M * (1.0 / det);
  return res;
}

void S21Matrix::MinorMatrix(S21Matrix& minor, int using_row, int using_col) {
  int i, j, k, l;
  for (i = 0, k = 0; k < minor.rows_; ++i) {
    if (i == using_row) {
      continue;
    }
    for (j = 0, l = 0; l < minor.rows_; ++j) {
      if (j == using_col) {
        continue;
      }
      minor.matrix_[k][l] = matrix_[i][j];
      ++l;
    }
    ++k;
  }
}