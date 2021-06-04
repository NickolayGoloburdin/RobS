
#include <iostream>
class Matrix
{
public:
int rows_ = 0;
int cols_ = 0;
int** matrix = new int* [rows_];
Matrix(int rows, int cols);
void Reset(int rows, int cols);
int At(int i, int j) const;
int& At(int i, int j);
int GetNumRows(int rows) const;
int GetNumColumns(int cols) const;
std::ostream& operator<< (std::ostream &out, const Matrix &matrix);
std::ostream& operator>> (std::ostream &in, const Matrix &matrix);
Matrix operator+(Matrix& a);

}

Matrix(int rows, int cols)
    {
        try
        {
            if (rows < 0 || cols < 0)
            {throw std::out_of_range;}
            
            for (int i = 0, i < rows_, i++)
                {
                        matrix[i][j] = new int[cols_];   
                }
            }
        
    }

void Reset(int rows, int cols){

    for (int i = 0, i < rows_, i++)
            {
                delete[] matrix[i];
            }
    cols_ = cols;
    rows_ = rows;
    for (int i = 0, i < rows_, i++)
            {
               
                    matrix[i][j] = new int[cols_];
                
            }
}
int At(int i, int j) const {try{
    if (i > rows_ || j> cols_)
    {throw std::out_of_range;}
    return matrix[i][j];}}
int& At(int i, int j) {try{
    if (i > rows_ || j> cols_)
    {throw std::out_of_range;}
    return matrix[i][j];}}
int GetNumRows(int rows) const {return rows_};
int GetNumColumns(int cols) const {return cols_};

std::ostream& operator<< (std::ostream &out, const Matrix &matrix)
{
    out << rows_ << cols_ << "\n";
    for (int i =0; i < rows_, i++ )
    {
        for (int j = 0; i < cols_, j++)
        {
            out << matrix[i][j];
        }
    out << "\n";
 
    return out;
}
std::ostream& operator>> (std::ostream &in, const Matrix &matrix)
{   in >> rows;
    in >> cols;
    this->Reset(rows, cols);
    for (int i =0; i < rows_, i++ )
    {
        for (int j = 0; i < cols_, j++)
        {
            in >> matrix[i][j];
        }

    }
 
    return in;
}

Matrix operator+(Matrix& a){

    try
    {
        if (rows_ != rows_ || a.cols_ != b.cols_)
            {throw std::invalid_argument;}

        Matrix c(a.rows_, a.cols_);
        for (int i =0; i < rows_, i++ )
    {
        for (int j = 0; i < cols_, j++)
        {
            c[i][j] = matrix[i][j] + a[i][j];
        }
        return c;

    }
    }
}

bool operator== (const Matrix &c1, const Matrix &c2)
{
    return (c1.m_company == c2.m_company &&
            c1.m_model== c2.m_model);
}
