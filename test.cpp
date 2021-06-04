
#include <iostream>
class Matrix {
public:
  int rows_ = 0;
  int cols_ = 0;
  int **matrix = new int *[rows_];
  Matrix(int rows, int cols);
  void Reset(int rows, int cols);
  int At(int i, int j) const;
  int &At(int i, int j);
  int GetNumRows(int rows) const;
  int GetNumColumns(int cols) const;
  friend std::ostream &operator<<(std::ostream &out, const Matrix &matrix);
  friend std::istream &operator>>(std::istream &in, Matrix &matrix);
  Matrix operator+(Matrix &a);
  friend bool operator==(const Matrix &c1, const Matrix &c2);
};

Matrix::Matrix(int rows, int cols) {
  try {
    if (rows < 0 || cols < 0) {
      throw std::out_of_range("blah");
    }
    rows_ = rows;
    cols_ = cols;
    for (int i = 0; i < rows_; i++) {

      matrix[i] = new int[cols_];
    }

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix[i][j] = 0;
      }
    }
  } catch (std::out_of_range a) {
    std::cerr << "out of range";
  }
}

void Matrix::Reset(int rows, int cols) {

  for (int i = 0; i < rows_; i++) {
    delete[] matrix[i];
  }
  cols_ = cols;
  rows_ = rows;
  for (int i = 0; i < rows_; i++) {

    matrix[i] = new int[cols_];
  }
}
int Matrix::At(int i, int j) const {
  try {
    if (i > rows_ || j > cols_) {
      throw std::out_of_range("blah");
    }
    return matrix[i][j];
  } catch (std::out_of_range a) {
    std::cerr << "out of range";
  }
}
int &Matrix::At(int i, int j) {
  try {
    if (i > rows_ || j > cols_) {
      throw std::out_of_range("blah");
    }

    return matrix[i][j];
  } catch (std::out_of_range a) {
    std::cerr << "out of range";
  }
}
int Matrix::GetNumRows(int rows) const { return rows_; }
int Matrix::GetNumColumns(int cols) const { return cols_; }

std::ostream &operator<<(std::ostream &out, const Matrix &matrix) {
  out << matrix.rows_ << matrix.cols_ << "\n";
  for (int i = 0; i < matrix.rows_; i++) {
    for (int j = 0; j < matrix.cols_; j++) {
      out << matrix.matrix[i][j];
    }
    out << "\n";

    return out;
  }
}
std::istream &operator>>(std::istream &in, Matrix &matrix) {
  in >> matrix.rows_;
  in >> matrix.cols_;
  matrix.Reset(matrix.rows_, matrix.cols_);
  for (int i = 0; i < matrix.rows_; i++) {
    for (int j = 0; j < matrix.cols_; j++) {
      in >> matrix.matrix[i][j];
    }
  }

  return in;
}

Matrix Matrix::operator+(Matrix &a) {

  try {
    if (rows_ != a.rows_ || cols_ != a.cols_) {
      throw std::invalid_argument("invalid_argument");
    }

    Matrix c(a.rows_, a.cols_);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; i < cols_; j++) {
        c.matrix[i][j] = matrix[i][j] + a.matrix[i][j];
      }
      return c;
    }
  } catch (std::invalid_argument a) {
    std::cerr << "invalid_argument";
  }
}

bool operator==(const Matrix &c1, const Matrix &c2) {

  if (c1.rows_ != c2.rows_ || c1.cols_ != c2.cols_) {
    return false;
  }
  for (int i = 0; i < c1.rows_; i++) {
    for (int j = 0; i < c1.cols_; j++) {

      if (c1.matrix[i][j] != c2.matrix[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  Matrix a(1, 2);
  std::cin >> a;
  std::cout << a;
  return 1;
}