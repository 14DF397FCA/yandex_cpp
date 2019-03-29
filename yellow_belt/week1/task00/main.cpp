#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix() {
        rows = 0;
        cols = 0;
    }

    Matrix(unsigned int new_x, unsigned int new_y) {
        Reset(new_x, new_y);
    }

    void Reset(unsigned int new_rows, unsigned int new_cols) {
        if (new_rows < 0) {
            throw out_of_range("num_rows must be >= 0");
        }
        if (new_cols < 0) {
            throw out_of_range("num_columns must be >= 0");
        }
        rows = new_rows;
        cols = new_cols;
        elements.assign(rows, vector<int>(rows));
    }

    int &At(int row, int col) {
        return elements.at(row).at(col);
    }

    int At(int row, int col) const {
        return elements.at(row).at(col);
    }

    int GetNumRows() const {
        return rows;
    }

    int GetNumColumns() const {
        return cols;
    }

private:
    unsigned int rows = 0;
    unsigned int cols = 0;
    vector<vector<int>> elements;
};

bool operator==(const Matrix &m1, const Matrix &m2) {
    if (m1.GetNumRows() != m2.GetNumRows()) {
        return false;
    }
    if (m1.GetNumColumns() != m2.GetNumColumns()) {
        return false;
    }
    for (unsigned int row = 0; row < m1.GetNumRows(); ++row) {
        for (unsigned int col = 0; col < m1.GetNumColumns(); ++col) {
            if (m1.At(row, col) != m2.At(row, col)) {
                return false;
            }
        }
    }

    return true;
}

Matrix operator+(const Matrix &m1, const Matrix &m2) {
    if (m1.GetNumRows() != m2.GetNumRows()) {
        throw invalid_argument("Mismatched number of rows");
    }
    if (m1.GetNumColumns() != m2.GetNumColumns()) {
        throw invalid_argument("Mismatched number of columns");
    }
    Matrix R(m1.GetNumRows(), m2.GetNumColumns());
    for (unsigned int row = 0; row < R.GetNumRows(); ++row) {
        for (unsigned int col = 0; col < R.GetNumColumns(); ++col) {
            R.At(row, col) = m1.At(row, col) + m2.At(row, col);
        }
    }
    return R;
}

istream &operator>>(istream &in, Matrix &m1) {
    unsigned int rows, cols;
    in >> rows >> cols;
    m1.Reset(rows, cols);
    for (unsigned int row = 0; row < rows; ++row) {
        for (unsigned int column = 0; column < cols; ++column) {
            in >> m1.At(row, column);
        }
    }
    return in;
}

ostream &operator<<(ostream &out, const Matrix &m1) {
    out << m1.GetNumRows() << " " << m1.GetNumColumns() << endl;
    for (unsigned int row = 0; row < m1.GetNumRows(); ++row) {
        for (unsigned int col = 0; col < m1.GetNumColumns(); ++col) {
            if (col > 0) {
                out << " ";
            }
            out << m1.At(row, col);
        }
        out << endl;
    }
    return out;
}

int main() {
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;
    return 0;
}